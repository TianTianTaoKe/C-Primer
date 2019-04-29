#include "stdafx.h"

#include "X.h"

int Employee::sn = 0;

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete use;
		delete ps;
	}
}

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete use;
		delete ps;
	}
	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}

HasPtr& HasPtr::operator=(const string& rhs)
{
	*ps = rhs;
	return  *this;
}

bool HasPtr::operator<(const HasPtr& rhs)const
{
	return *ps < *rhs.ps;
}

string& HasPtr::operator*()
{
	return *ps;
}

void TreeNode::CopyTree()
{
	if (left)
	{	
		left->CopyTree();
	}
	if (right)
	{
		right->CopyTree();
	}
	count++;
}

TreeNode::TreeNode(const TreeNode &tn)
:value(tn.value), count(tn.count), left(tn.left), right(tn.right)
{
	if (left)
	{
		left->CopyTree();
	}
	if (right)
	{
		right->CopyTree();
	}
}

int TreeNode::ReleaseTree()
{
	if (left)
	{
		if (!left->ReleaseTree())
		{
			delete left;
		}
	}
	if (right)
	{
		if (!right->ReleaseTree())
		{
			delete right;
		}
	}
	count--;
	return count;
}

TreeNode::~TreeNode()
{
	if (count)
	{
		ReleaseTree();
	}
}

BinStrTree::BinStrTree(const BinStrTree& bst) :root(bst.root)
{
	root->CopyTree();
}

BinStrTree::~BinStrTree()
{
	if (!root->ReleaseTree())
	{
		delete root;
	}
}

void Message::add_to_Folders(const Message& m)
{
	for (auto f:m.folders)
	{
		f->addMsg(this);
	}
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
	{
		f->remMsg(this);
	}
}

Message::Message(const Message& m) :content(m.content), folders(m.folders)
{
	add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
	remove_from_Folders();
	content = rhs.content;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	folders.erase(&f);
	f.remMsg(this);
}

void swap(Message &lhs, Message&rhs)
{
	using std::swap;
	for (auto f:lhs.folders)
	{
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->remMsg(&rhs);
	}

	swap(lhs.folders, rhs.folders);
	swap(lhs.content, rhs.content);

	for (auto f : lhs.folders)
	{
		f->addMsg(&lhs);
	}
	for (auto f : rhs.folders)
	{
		f->addMsg(&rhs);
	}
}

void Folder::add_to_Message(const Folder& f)
{
	for (auto m : f.msgs)
	{
		m->addFldr(this);
	}
}

void Folder::remove_from_Message()
{
	for (auto m : msgs)
	{
		m->remFldr(this);
	}
}

Folder::Folder(const Folder&f) :msgs(f.msgs)
{
	add_to_Message(f);
}

Folder::~Folder()
{
	remove_from_Message();
}

Folder& Folder::operator=(const Folder& rhs)
{
	remove_from_Message();
	msgs = rhs.msgs;
	add_to_Message(rhs);
	return *this;
}