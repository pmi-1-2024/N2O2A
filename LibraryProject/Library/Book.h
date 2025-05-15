#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include "StructsForBook.h"
using namespace std;
class Book
{
protected:
	int ID;
	string name;
	Genre genre;
	int release_year;
	size_t aunum;
	Author* authors;
	int page_num;
public:
	Book();
	Book(int id, string n, Genre g, int rel_y,size_t an, int pn);
	int getID() const;
	string getName()const;
	Genre getGenre()const;
	int getRelYear()const;
	Author* getAuthors()const;
	int getPageNum()const;
	Book(const Book& b);
	virtual void printtofile(ostream& os)const;
	virtual void Consoleprint()const;
	virtual void fileinput(istream& is);
	virtual void ConsoleInput() = 0;
	Book& operator =(const Book& b);
	virtual ~Book();
	friend istream& operator>>(istream& is, Book& b);
	friend ostream& operator<<(ostream& os, const Book& b);
};
#endif
