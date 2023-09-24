#pragma once
#include <iostream>
#include <string>
using namespace std;

enum enList { Search = 1, Add, Remove, Display, Exit };

struct Book {
	string name;
	string author;
	int year;
};

