#pragma once
#include <vector>
#include "Library.h"

class Library {
private:
	vector<Book> Books;
public:
	void MainPanel();
	void Search();
	void AddBook();
	void RemoveBook();
	void Display();
	void Exit();
};

