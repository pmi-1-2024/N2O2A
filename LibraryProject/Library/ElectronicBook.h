#ifndef ELECTRONICBOOK_H
#define ELECTRONICBOOK_H
#include "Book.h"
class ElectronicBook : public Book
{
private:
	string format;
	double file_size;
public:
	ElectronicBook();
	ElectronicBook(int id, string n, Genre g, int rel_y, size_t an, int pn, string f, double fs);
	void printtofile(ostream& os)const override;
	void Consoleprint()const override;
	void fileinput(istream& is)override;
	void ConsoleInput() override;
	friend istream& operator>>(istream& is, ElectronicBook& eb);
	friend ostream& operator<<(ostream& os, const ElectronicBook& eb);
};
#endif

