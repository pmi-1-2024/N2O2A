#ifndef PAPERBOOK_H
#define PAPERBOOK_H
#include "Book.h"
class PaperBook : public Book {
private:
	Publisher pub_house;
public:
	PaperBook();
	PaperBook(int id, string n, Genre g, int rel_y, size_t an, int pn, Publisher pb);
	Publisher getPubHouse()const;
    void printtofile(ostream& os)const override;
	void Consoleprint() const override;
	void fileinput(istream& is)override;
	void ConsoleInput();
	friend istream& operator>>(istream& is, PaperBook& pb);
	friend ostream& operator<<(ostream& os, const PaperBook& pb);
};
#endif

