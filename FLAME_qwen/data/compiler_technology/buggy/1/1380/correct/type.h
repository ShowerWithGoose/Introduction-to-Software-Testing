#ifndef TYPE_H
#define TYPE_H

#include <bits/stdc++.h>
using namespace std;

struct TOKEN{
    string ori,sym;
    int line;
};

enum Sym{
    IDENFR
};

struct ERROR{
    int line;
    string type;
};

#endif