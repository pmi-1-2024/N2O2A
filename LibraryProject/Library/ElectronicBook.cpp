#include "ElectronicBook.h"

ElectronicBook::ElectronicBook() : Book(), format("no"), file_size(0.0){}

ElectronicBook::ElectronicBook(int id, string n, Genre g, int rel_y, size_t an, int pn, string f, double fs): Book(id,n,g,rel_y,an,pn), format(f), file_size(fs){}

void ElectronicBook::printtofile(ostream& os) const
{
    Book::printtofile(os);
    os << format << " " << file_size;
}

void ElectronicBook::Consoleprint() const
{
	Book::Consoleprint();
	cout << "\nFormat: " << format << ", File size: " << file_size << " GB";
}

void ElectronicBook::fileinput(istream& is)
{
	Book::fileinput(is);
	is >> format >> file_size;
}

void ElectronicBook::ConsoleInput()
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
    cout << "\nEnter book file format";
    cin >> format;
    cout << "\nEnter book file size";
    cin >> file_size;
}

istream& operator>>(istream& is, ElectronicBook& eb)
{
	eb.fileinput(is);
	return is;
}

ostream& operator<<(ostream& os, const ElectronicBook& eb)
{
	eb.printtofile(os);
	return os;
}

