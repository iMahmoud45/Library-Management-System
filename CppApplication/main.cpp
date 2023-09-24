#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Library.h"
#include "LibraryClass.h"
using namespace std;

int main() {
	Library library;
	cout << "===================================" << endl;
	cout << "==== Library Management System ====" << endl;
	cout << "===================================" << endl;
	short choose;
	while (true) {
		cout << endl;
		library.MainPanel();
		cout << "Enter your Action: ";
		cin >> choose;
		switch (choose) {
		case enList::Search:
			library.Search();
			break;
		case enList::Add:
			library.AddBook();
			break;
		case enList::Display:
			library.Display();
			break;
		case enList::Remove:
			library.RemoveBook();
			break;
		case enList::Exit:
			library.Exit();
			break;
		default:
			cout << "Wrong Input, please try again. " << endl;
			break;
		}
		if (choose == enList::Exit) {
			break;
		}
	}

	return 0;
}