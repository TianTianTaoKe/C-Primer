#pragma once
#include  "stdafx.h"
#include <stdexcept>

template<typename T>
int Compare(const T& v1, const T& v2)
{
    if (v1 < v2)
    {
        return -1;
    }
    if (v2 < v1)
    {
        return 1;
    }
    return 0;
}

template<typename Iter,typename T>
Iter MyFind(Iter begin, Iter end, T value)
{
    for (Iter iter = begin;iter != end;iter++)
    {
        if (*iter == value)
        {
            return iter;
        }
    }
    return end;
}

template<typename T, size_t N>
const T* MyBegin(const T(&a)[N])
{
    return &a[0];
}

template<typename T, size_t N>
const T* MyEnd(const T(&a)[N])
{
    return &a[0] + N;
}

template<typename T, size_t N>
constexpr int ArrSize(const T(&a)[N])
{
    return N;
}

template<typename T,size_t N>
void MyPrint(const T(&a)[N])
{
    //for (auto iter = MyBegin(a);iter != MyEnd(a);++iter)
    //{
    //	cout << *iter << endl;
    //}
    for (int i = 0;i<ArrSize(a);++i)
    {
        cout << a[i] << endl;
    }
}

template <typename T>
class SP{
public:
    SP():p(nullptr),use(nullptr){}
    explicit SP(T *pt):p(pt),use(new size_t(1)){}
    SP(const SP &sp):
        p(sp.p),use(sp.use){
            if (use){
                ++ *use;
            }
        }
    SP& operator=(const SP&);
    ~SP();
    T& operator*() {return *p;}
    T& operator*() const {return *p;}
private:
    T *p;
    size_t *use;
};

template <typename T>
SP<T>::~SP(){
    if (use && --*use == 0){
        delete p;
        delete use;
    }
}

template <typename T>
SP<T>& SP<T>::operator=(const SP<T> &rhs)
{
    if (rhs.use){
        ++*rhs.use;
    }
    if (use && --*use == 0){
        delete p;
        delete use;
    }
    p = rhs.p;
    use = rhs.use;
    return *this;
}

template <typename T,class... Args>
SP<T>make_SP(Args&&... args)
{
    return SP<T>(new T(std::forward<Args>(args)...));
}

template <typename T>
class UP
{
public:
    UP():p(nullptr){}
    UP(const UP&) = delete;
    explicit UP(T* pt):p(pt){}
    UP& operator=(const UP&) = delete;
    ~UP();
    T* release();
    void reset(T *new_p);
    T& operator*(){return *p;}
    T& operator*() const {return *p;}
private:
    T *p;
};

template<typename T>
void UP<T>::reset(T *new_p)
{
    if (p){
        delete p;
    }
    p = new_p;
}

template<typename T>
UP<T>::~UP()
{
    if (p){
        delete p;
    }
}

template<typename T>
T* UP<T>::release()
{
    T *q = p;
    p = nullptr;
    return q;
}

template <typename> class BlobPtrTemp;
template <typename> class BlobTemp;
template <typename T>
bool operator==(const BlobTemp<T>&, const BlobTemp<T>&);
template <typename T>class BlobTemp
{
    friend class BlobPtrTemp<T>;
    friend bool operator==<T>(const BlobTemp<T>&, const BlobTemp<T>&);
public:
    typedef T value_type;
    typedef typename vector<T>::size_type size_type;

    BlobTemp();

    BlobTemp(initializer_list<T> il);
    template <typename It> BlobTemp(It b, It e);
    BlobTemp(T*, std::size_t);

    BlobPtrTemp<T> begin(){ return BlobPtrTemp<T>(*this); }
    BlobPtrTemp<T> end()
    {
        auto ret = BlobPtrTemp<T>(*this, data->size());
        return  ret;
    }

    size_type size() const { return (*data).size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { (*data).push_back(std::move(t)); }
    void pop_back();

    T& front();
    T& back();
    T& at(size_type);
    const T& back() const;
    const T& front() const;
    const T& at(size_type) const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;

    void swap(BlobTemp& b) { data.swap(b.data); }

private:
    SP<std::vector<T> > data;

    void check(size_type i, const std::string& msg) const;
};

template <typename T>
BlobTemp<T>::BlobTemp(T* p, std::size_t n)
    :data(make_SP<std::vector<T> >(p, p + n))
{
}

template <typename T>
BlobTemp<T>::BlobTemp()
    : data(make_SP<std::vector<T> >())
{

}

template <typename T>
template <typename It>
BlobTemp<T>::BlobTemp(It b, It e)
    :data(make_SP<std::vector<T>>(b, e))
{

}

template<typename T>
BlobTemp<T>::BlobTemp(std::initializer_list<T> il) :
    data(make_SP<std::vector<T> >(il))
{

}

template<typename T>
void BlobTemp<T>::check(size_type i, const std::string& msg) const
{
    if (i >= (*data).size())
    {
        throw std::out_of_range(msg);
    }
}

template<typename T>
T& BlobTemp<T>::front()
{
    check(0, "fron on empty BlobTemp");
    return data->front();
}

template<typename T>
T& BlobTemp<T>::back()
{
    check(0, "back on empty BlobTemp");
    return data->back();
}

template<typename T>
void BlobTemp<T>::pop_back()
{
    check(0, "pop_back on empty BlobTemp");
    return data->pop_back();
}

template<typename T>
const T& BlobTemp<T>::front() const
{
    check(0, "fron on empty BlobTemp");
    return data->front();
}

template<typename T>
const T& BlobTemp<T>::back() const
{
    check(0, "back on empty BlobTemp");
    return data->back();
}

template<typename T>
T& BlobTemp<T>::at(size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T& BlobTemp<T>::at(size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
T& BlobTemp<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T& BlobTemp<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
bool operator==(const BlobTemp<T>& lhs, const BlobTemp<T>& rhs)
{
    if (rhs.size() != lhs.size())
    {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
        {
            return false;
        }
    }
    return true;
}

template<typename T>
bool operator==(const BlobPtrTemp<T>&, const BlobPtrTemp<T>&);

template <typename T> class BlobPtrTemp
{
    friend bool operator==<T>(const BlobPtrTemp<T>&, const BlobPtrTemp<T>&);
public:
    BlobPtrTemp() :curr(0) {}
    BlobPtrTemp(BlobTemp<T>&a,size_t sz = 0):wptr(a.data),curr(sz){}
    T& operator[](size_t i)
    {
        auto p = check(i, "subscript out of range");
        return (*p)[i];
    }
    const T& operator[](size_t i) const
    {
        auto p = check(i, "subscript out of range");
        return (*p)[i];
    }
    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    T* operator->() const
    {
        return &this->operator*();
    }
    BlobPtrTemp& operator++();
    BlobPtrTemp& operator--();

    BlobPtrTemp operator++(int);
    BlobPtrTemp operator--(int);
protected:
private:
    shared_ptr<vector<T> > check(size_t, const string&) const;
    weak_ptr<vector<T> >wptr;
    size_t curr;
};

template<typename T>
bool operator==(const BlobPtrTemp<T>& lhs, const BlobPtrTemp<T>& rhs)
{
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}

template<typename T>
bool operator!=(const BlobPtrTemp<T>& lhs, const BlobPtrTemp<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
shared_ptr<vector<T> > BlobPtrTemp<T>::check(size_t i, const string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("unbound BlobPtrTemp");
    }
    
    if (i >= ret->size() || i < 0)
    {
        throw std::out_of_range(msg);
    }
    
    return ret;
}

template <typename T>
BlobPtrTemp<T> BlobPtrTemp<T>::operator++(int)
{
    BlobPtrTemp ret = *this;
    ++* this;
    return ret;
}

template <typename T>
BlobPtrTemp<T> BlobPtrTemp<T>::operator--(int)
{
    BlobPtrTemp ret = *this;
    --* this;
    return ret;
}

template <typename T>
BlobPtrTemp<T>& BlobPtrTemp<T>::operator++()
{
    check(curr, "increment past end of BlobPtrTemp");
    ++curr;
    return *this;
}

template <typename T>
BlobPtrTemp<T>& BlobPtrTemp<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtrTemp");
    return *this;
}

template<unsigned uWidth,unsigned uHeight> class Screen;

template<unsigned uWidth,unsigned uHeight>
istream & operator >> (istream &,Screen<uWidth,uHeight>&);

template<unsigned uWidth,unsigned uHeight>
class Screen
{
    friend istream & operator >> <uWidth,uHeight > (istream &,Screen<uWidth,uHeight>&);
public:
    Screen():contents(uWidth * uHeight,' '){}
    Screen(char c):contents(uWidth * uHeight,c){}
    friend class Window_mgr;
    char get() const { return contents[cursor]; }
    char get(int, int) const;
    Screen& clear(char = bkground);
    Screen& move(int r, int c);
    Screen& set(char);
    Screen& set(int, int, char);
    Screen& display(ostream& os) { do_display(os); return *this; }
    const Screen& display(ostream& os) const { do_display(os); return*this; }
protected:
private:
    static const char bkground = ' ';
    int cursor = 0;
    string contents;
    void do_display(ostream& os) const 
    {
        for (int i = 0; i < uHeight; ++i)
        {
            for (int j = 0; j < uWidth; ++j)
            {
                os << contents[i * uWidth + j];
            }
            os << endl;
        }
    }
};

template<unsigned uWidth, unsigned uHeight>
Screen<uWidth, uHeight>& Screen<uWidth, uHeight>::clear(char c)
{
    contents = string(uWidth * uHeight, c);
    return *this;
}

template<unsigned uWidth, unsigned uHeight>
Screen<uWidth, uHeight>& Screen<uWidth, uHeight>::move(int r, int c)
{
    int row = r * uWidth;
    cursor = row + c;
    return *this;
}

template<unsigned uWidth, unsigned uHeight>
char Screen<uWidth, uHeight>::get(int r, int c)const
{
    int row = r * uWidth;
    return contents[row + c];
}

template<unsigned uWidth, unsigned uHeight>
Screen<uWidth, uHeight>& Screen<uWidth, uHeight>::set(char c)
{
    contents[cursor] = c;
    return *this;
}

template<unsigned uWidth, unsigned uHeight>
Screen<uWidth, uHeight>& Screen<uWidth, uHeight>::set(int r, int col,char ch)
{
    int row = r * uWidth;
    contents[row + col] = ch;
    return *this;
}

template<unsigned uWidth,unsigned uHeight>
ostream & operator << (ostream & os,Screen<uWidth,uHeight>& s)
{    
    s.display(os);
    return os;
}

template<unsigned uWidth,unsigned uHeight>
istream & operator >> (istream & is,Screen<uWidth,uHeight>& s)
{
    string t;
    is >> t;
    s.contents = t.substr(0,uWidth*uHeight);
    return is;
}

template<typename T>
class Vec;

template<typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
bool operator>(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
bool operator>=(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
bool operator<(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
bool operator<=(const Vec<T>& lhs, const Vec<T>& rhs);

template<typename T>
class Vec
{
public:
	friend bool operator== <T>(const Vec& lhs, const Vec& rhs);
	friend bool operator!= <T>(const Vec& lhs, const Vec& rhs);
	friend bool operator>  <T>(const Vec& lhs, const Vec& rhs);
	friend bool operator>= <T>(const Vec& lhs, const Vec& rhs);
	friend bool operator<  <T>(const Vec& lhs, const Vec& rhs);
	friend bool operator<= <T>(const Vec& lhs, const Vec& rhs);
	Vec():
		element(nullptr), first_free(nullptr), cap(nullptr){}
	Vec(initializer_list<T> li);
	Vec(const Vec&);
	Vec(Vec&&) throw();
	Vec& operator=(const Vec&);
	Vec& operator=(Vec &&)throw();
	Vec& operator=(initializer_list<T> il);
	T& operator[](size_t n){ return element[n]; }
	const T& operator[](size_t n) const{ return element[n]; }
	~Vec();
	void push_back(const T&);
	size_t size() const{ return first_free - element; }
	size_t capacity() const{ return cap - element; }
	T* begin() const{ return element; }
	T* end() const{ return first_free; }
	void reserve(size_t n);
	void resize(size_t n);
	void resize(size_t n, const T &);
protected:
private:
	T *element;
	T *first_free;
	T *cap;
	static allocator<T> alloc;

	void chk_n_alloc(){ if (size() == capacity()) reallocate(); }
	pair<T*, T*> alloc_n_copy(const T*, const T*);
	void free();
	void reallocate();
	void reallocate(size_t newcapacity);
};

template<typename T>
inline
Vec<T>::Vec(initializer_list<T> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	element = newdata.first;
	first_free = cap = newdata.second;
}

template<typename T>
inline
Vec<T>::Vec(Vec &&s) throw() :
element(s.element), first_free(s.first_free), cap(s.cap)
{
	s.element = s.first_free = s.cap = nullptr;
}

template<typename T>
inline
Vec<T>& Vec<T>::operator=(Vec && rhs) throw()
{
	if (this != &rhs)
	{
		free();
		element = rhs.element;
		first_free = rhs.first_free;
		cap = rhs.cap;

		rhs.element = rhs.first_free = rhs.cap = nullptr;
	}

	return *this;
}

template<typename T>
allocator<T> Vec<T>::alloc;

template<typename T>
void Vec<T>::push_back(const T& s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

template<typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T *b,const T *e)
{
	auto date = alloc.allocate(e - b);
	return{ date, uninitialized_copy(b, e, date) };
}

template<typename T>
void Vec<T>::free()
{
	if (element)
	{
		//for (auto p = first_free; p != element;)
		//{
		//	alloc.destroy(--p);
		//}
		for_each(element, first_free, [](T &s){alloc.destroy(&s); });
	}
	alloc.deallocate(element, cap - element);
}

template<typename T>
Vec<T>::Vec(const Vec& s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	element = data.first;
	first_free = cap = data.second;
}

template<typename T>
Vec<T>::~Vec()
{
	free();
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec& s)
{
	auto data = alloc_n_copy(s.begin(), s.end());
	free();
	element = data.first;
	first_free = cap =data.second;
	return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator=(initializer_list<T> il)
{
	auto data = alloc_n_copy(il.begin(), il.end());
	free();
	element = data.first;
	first_free = cap = data.second;
	return *this;
}

template<typename T>
void Vec<T>::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;

	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = element;

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}

template<typename T>
void Vec<T>::reallocate(size_t newcapacity)
{
	auto newdata = alloc.allocate(newcapacity);

	auto dest = newdata;
	auto elem = element;

	for (size_t i = 0; i != size(); ++i)
	{
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	element = newdata;
	first_free = dest;
	cap = element + newcapacity;
}

template<typename T>
void Vec<T>::reserve(size_t n)
{
	if (n>capacity())
	{
		reallocate(n);
	}
}

template<typename T>
void Vec<T>::resize(size_t n)
{
	if (n>size())
	{
		while (size() < n)
		{
			push_back("");
		}
	}
	else if (n < size())
	{
		while (size() > n)
		{
			alloc.destroy(--first_free);
		}
	}
}

template<typename T>
void Vec<T>::resize(size_t n,const T& s)
{
	if (n > size())
	{
		while (size() < n)
		{
			push_back(s);
		}
	}
}

template<typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs)
{
	if (lhs.size() != rhs.size())
	{
		return false;
	}
	for (auto itr1 = lhs.begin(), itr2 = rhs.begin(); 
			itr1 != lhs.end() && itr2 != rhs.end();++itr1,++itr2)
	{
		if (*itr1 != *itr2)
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs)
{
	return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T>& lhs, const Vec<T>& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (;itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}

	if (itr1 == lhs.end() && itr2 != lhs.end())
	{
		return true;
	}
	return false;
}

template<typename T>
bool operator<=(const Vec<T>& lhs, const Vec<T>& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 < *itr2)
			return true;
		else if (*itr1 > *itr2)
			return false;
	}

	if (itr1 == lhs.end())
	{
		return true;
	}
	return false;
}

template<typename T>
bool operator>(const Vec<T>& lhs, const Vec<T>& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}

	if (itr1 != lhs.end() && itr2 == lhs.end())
	{
		return true;
	}
	return false;
}

template<typename T>
bool operator>=(const Vec<T>& lhs, const Vec<T>& rhs)
{
	auto itr1 = lhs.begin(), itr2 = rhs.begin();
	for (; itr1 != lhs.end() && itr2 != rhs.end(); ++itr1, ++itr2)
	{
		if (*itr1 > *itr2)
			return true;
		else if (*itr1 < *itr2)
			return false;
	}

	if (itr2 == lhs.end())
	{
		return true;
	}
	return false;
}

template<typename T>
void print(const T& t)
{
    for (typename T::size_type i = 0;i<t.size();++i)
    {
        cout << t.at(i) << " ";
    }
    cout << endl;
}

template<typename T>
void print2(const T& t)
{
    for (typename T::const_iterator iter = t.begin();iter != t.end();++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr):os(s){}
    template <typename T>
    void operator()(T *p)const
    {
        os << "deleting unique_ptr" << endl;
        delete p;
    }
private:
    std::ostream &os;
};

template<typename T>
bool compare(const T& a,const T& b)
{
    return a < b;
}

template<typename T1,typename T2>
auto sum(T1 a,T2 b) -> decltype(a+b)
{
    return a + b;
}

template<typename F,typename T1,typename T2>
void flip(F f,T1 &&t1,T2 &&t2)
{
    f(std::forward<T2>(t2),std::forward<T1>(t1));
}

template<typename T>string debug_rep(const T &t)
{
    ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T>string debug_rep(T* p)
{
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
    {
        ret << " " << debug_rep(*p);
    }
    else
    {
        ret << " null pointer";
    }
    return ret.str();
}

string debug_rep(const string& s);

string debug_rep(char* p);

string debug_rep(const char* p);

template <typename T> void f(T t)
{
    cout << "f(T t)" << endl;
}

template <typename T> void f(const T* t)
{
    cout << "f(const T* t)" << endl;
}

template <typename T> void gg(T t)
{
    cout << "gg(T t)" << endl;
}

template <typename T> void gg(T* t)
{
    cout << "gg(T* t)" << endl;
}

template <typename T,typename... Args>
void foo(const T& t,const Args& ... rest)
{
    cout << sizeof...(Args) << endl;
    cout << sizeof...(rest) << endl;
}

template <typename T>
ostream& print3(ostream& os,const T &t)
{
    return os << t <<endl;
}
template <typename T,typename... Args>
ostream& print3(ostream& os,const T &t,Args...rest)
{
    os << t << ";";
    return print3(os,rest...);
}

template <typename... Args>
ostream& ErrorMsg(ostream& os,Args... rest)
{
    return print3(os,debug_rep(rest)...);
}