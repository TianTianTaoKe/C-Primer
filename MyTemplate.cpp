#include "stdafx.h"
#include "MyTemplate.h"


string debug_rep(const string& s)
{
    return '"' + s + '"';
}

string debug_rep(char* p)
{
    return debug_rep(string(p));
}

string debug_rep(const char* p)
{
    return debug_rep(string(p));
}
