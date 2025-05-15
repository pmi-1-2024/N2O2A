#include "PaperBook.h"

PaperBook::PaperBook() : Book(), pub_house(Publisher()) {}

PaperBook::PaperBook(int id, string n, Genre g, int rel_y, size_t an, int pn, Publisher pb) : Book(id, n, g, rel_y, an, pn), pub_house(pb) {}

Publisher PaperBook::getPubHouse() const
{
	return pub_house;
}

void PaperBook::printtofile(ostream& os) const
{
    Book::printtofile(os);
     pub_house.printtofile(os);
}

void PaperBook::Consoleprint() const
{
	Book::Consoleprint();
	cout << "\nPublishing house: " << pub_house;
}

void PaperBook::fileinput(istream& is)
{
	Book::fileinput(is);
	is >> pub_house;
}

void PaperBook::ConsoleInput()
{
    cout << "Enter book ID: ";
    cin >> ID;
    cin.ignore();

    cout << "Enter book name: ";
    getline(cin, name);

    cout << "Enter genre: ";
    genre.ConsoleInput();

    cout << "Enter publication year: ";
    cin >> release_year;

    cout << "\nEnter number of authors:";
    cin >> aunum;
    cout << "Enter number of pages: ";
    cin >> page_num;
    cin.ignore();
    delete[]authors;
    authors = new Author[aunum];
    for (size_t i = 0; i < aunum; i++) {
         authors[i].ConsoleInput();
    }
    cout << "\nEnter Publishing house";
    pub_house.ConsoleInput();
}

istream& operator>>(istream& is, PaperBook& pb)
{
	pb.fileinput(is);
	return is;
}

ostream& operator<<(ostream& os, const PaperBook& pb)
{
	pb.printtofile(os);
	return os;
}


