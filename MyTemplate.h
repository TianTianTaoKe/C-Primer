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

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const T& t) { data->push_back(t); }
    void push_back(T&& t) { data->push_back(std::move(t)); }
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
    std::shared_ptr<std::vector<T> > data;

    void check(size_type i, const std::string& msg) const;
};

template <typename T>
BlobTemp<T>::BlobTemp(T* p, std::size_t n)
    :data(std::make_shared<std::vector<T> >(p, p + n))
{
}

template <typename T>
BlobTemp<T>::BlobTemp()
    : data(std::make_shared<std::vector<T> >())
{

}

template <typename T>
template <typename It>
BlobTemp<T>::BlobTemp(It b, It e)
    :data(std::make_shared<std::vector<T>>(b, e))
{

}

template<typename T>
BlobTemp<T>::BlobTemp(std::initializer_list<T> il) :
    data(std::make_shared<std::vector<T> >(il))
{

}

template<typename T>
void BlobTemp<T>::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
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