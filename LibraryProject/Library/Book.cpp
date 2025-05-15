#include "Book.h"


Book::Book() : ID(0), name("noname"), genre(Genre()), release_year(0),aunum(0), authors(nullptr), page_num(0) {}

Book::Book(int id, string n, Genre g, int rel_y,size_t an, int pn) : ID(id), name(n), genre(g), release_year(rel_y),aunum(an), page_num(pn) {
	authors = new Author[an];
}

int Book::getID() const
{
	return ID;
}

string Book::getName() const
{
	return name;
}

Genre Book::getGenre() const
{
	return genre;
}

int Book::getRelYear() const
{
	return release_year;
}

Author* Book::getAuthors() const
{
	return authors;
}

int Book::getPageNum() const
{
	return page_num;
}

Book::Book(const Book& b) : ID(b.ID), name(b.name), genre(b.genre), release_year(b.release_year),aunum(b.aunum), page_num(b.page_num) {
	authors = new Author[aunum];
	for (size_t i = 0; i < aunum; i++) {
		authors[i] = b.authors[i];
	}
}

void Book::printtofile(ostream& os) const
{
	os << ID << " " << name << " ", genre.printtofile(os), os << " " << release_year << " " << aunum <<" "<< page_num;
	os << "\n";
	for (size_t i = 0; i < aunum; i++) {
		 authors[i].printtofile(os), os << "\n";
	}
}

void Book::Consoleprint() const
{
	cout << "\nID: " << ID << ", Name: " << name << ", Genre: " << genre << ", Release year: " << release_year << ", Number of pages: " << page_num;
	cout << "\nAuthors: " << "\n";
	for (size_t i = 0; i < aunum; i++) {
		if (i == aunum - 1) {
			cout << authors[i];
		}
		else {
			cout << authors[i] << "\n";
		}
	}
}

void Book::fileinput(istream& is)
{
	is >> ID >> name >> genre >> release_year >> aunum >> page_num;
	delete[]authors;
	authors = new Author[aunum];
	for (size_t i = 0; i < aunum; i++) {
		is >> authors[i];
	}
}

Book& Book::operator=(const Book& b)
{
	if (this == &b) {
		return *this;
	}
	ID = b.ID;
	name = b.name;
	genre = b.genre;
	release_year = b.release_year;
	aunum = b.aunum;
	page_num = b.page_num;
	delete[]authors;
	authors = new Author[aunum];
	for (size_t i = 0; i < aunum; i++) {
		authors[i] = b.authors[i];
	}
	return *this;
}

Book::~Book()
{
	delete[]authors;
}

istream& operator>>(istream& is, Book& b)
{
	b.fileinput(is);
	return is;
}

ostream& operator<<(ostream& os, const Book& b)
{
	b.printtofile(os);
	return os;
}
