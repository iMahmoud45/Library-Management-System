#include "LibraryClass.h"

void Library::MainPanel() {
	cout << "(1) Search For Books" << endl;
	cout << "(2) Add Book" << endl;
	cout << "(3) Remove Book" << endl;
	cout << "(4) Display Books" << endl;
	cout << "(5) Exit\n" << endl;
};

void Library::Search() {
	string name;
	bool found = false;
	int bookIndex;
	string ask;
	if (Books.size() == 0) {
		cout << "\nThere's no books in the library. " << endl;
	}
	else {
		cout << "\nName of the Book: ";
		cin >> name;
		for (int i = 0; i < Books.size(); i++) {
			if (Books.at(i).name == name) {
				found = true;
				bookIndex = i;
			}
		}
		if (found) {
			cout << "\nThe Books was found." << endl;
			cout << "Here's book details: " << endl;
			cout << "The Name: " << Books.at(bookIndex).name << endl;
			cout << "The Author: " << Books.at(bookIndex).author << endl;
			cout << "The Year: " << Books.at(bookIndex).year << endl;
		}
		else {
			cout << "\nBook was not found. " << endl;
			do {
				cin.ignore();
				cout << "Do you want to search again? (Y/N) " << endl;
				getline(cin, ask);
				if (ask == "Y" || ask == "y") {
					Search();
				}
				else if (ask == "n" || ask == "N") {
					break;
				}
				else {
					cout << "Wrong Input, please try again. " << endl;
					continue;
				}
			} while (true);
		}
	}
}

void Library::AddBook() {
	string name;
	int year;
	string author;
	cin.ignore();
	do {
		cout << "Name of the Book: ";
		getline(cin, name);
	} while (name.length() == 0);
	do {
		cout << "Name of the Author: ";
		getline(cin, author);
	} while (author.length() == 0);

	do {
		cout << "The Year the Book was made: ";
		cin >> year;
		if (cin.fail() || year < 0) {
			cin.clear();
			cin.ignore();
			cout << "Wrong Input, try again. " << endl;
			continue;
		}
		else {
			break;
		}
	} while (true);
	Book book;
	book.name = name;
	book.author = author;
	book.year = year;
	Books.push_back(book);
}

void Library::RemoveBook() {
	cin.ignore();
	string name;
	bool found = false;
	if (Books.size() == 0) {
		cout << "There's no books in the library. " << endl;
		return;
	}
	do {
		cout << "Name of the Book: ";
		getline(cin, name);
	} while (name.length() == 0);
	for (int i = 0; i < Books.size(); i++) {
		if (Books.at(i).name == name) {
			found = true;
			Books.erase(Books.begin() + i);
		}
	}
	if (found) {
		cout << "\nBook has been Removed. " << endl;
	}
	else {
		cout << "\nWrong name, please try again. " << endl;
	}
}

void Library::Display() {
	if (Books.size() <= 0) {
		cout << "\nThere's no books in the library. " << endl;
		return;
	}
	cout << "\nList of Books: " << endl;
	for (int i = 0; i < Books.size(); i++) {
		cout << "= " << Books.at(i).name << endl;
	}
	string ask;
	cin.ignore();
	do {
		cout << "Do you want to get more details? (Y/N)" << endl;
		getline(cin, ask);
		if (ask == "y" || ask == "Y" || ask == "N" || ask == "n") {
			break;
		}
	} while (true);
	if (ask == "y" || ask == "Y") {
		Search();
	}
}

void Library::Exit() {
	if (Books.size() > 1) {
		cout << "Exited, Your books are lost :(" << endl;
	}
	else if (Books.size() == 1) {
		cout << "Exited, Your book is lost :(" << endl;
	}
	else {
		cout << "Exited." << endl;
	}
}