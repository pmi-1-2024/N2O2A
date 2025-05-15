#ifndef STRUCTSFORBOOK_H
#define STRUCTSFORBOOK_H
#include "iostream"
#include <string>
using namespace std;

class Author {
private:
    int id;
    string name;
    string surname;
public:
    Author() : id(0), name(""), surname("") {}
    Author(int id, string name, string surname)
        : id(id), name(name), surname(surname) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getSurname() const { return surname; }
    void ConsoleInput() {
        cout << "\nEnter author ID: ";
        cin >> id;
        cout << "\nEnter author name: ";
        cin >> name;
        cout << "\nEnter author surname: ";
        cin >> surname;
    }
    void printtofile(ostream& os)const {
        os << id <<" " << name<<" " << surname;
    }
    friend istream& operator>>(istream& in, Author& a) {
        in >> a.id >> a.name >> a.surname;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Author& a) {
        out << "Author ID: " << a.id << ", Name: " << a.name << " " << a.surname;
        return out;
    }
};


class Publisher {
private:
    int id;
    string name, address;

public:
    Publisher() : id(0), name(""), address("") {}
    Publisher(int id, string name, string address)
        : id(id), name(name), address(address) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    void ConsoleInput() {
        cout << "\nEnter ID: ";
        cin >> id;
        cin.ignore();
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "\nEnter address: ";
        getline(cin, address);
    }
    void printtofile(ostream&os) const{
        os << id << " " << name << ", " << address<<", ";
    }
    friend istream& operator>>(istream& in, Publisher& p) {
        in >> p.id ,in.ignore(), getline(in, p.name,','), getline(in, p.address, ';');
        return in;
    }

    friend ostream& operator<<(ostream& out, const Publisher& p) {
        out << "Publisher : " << p.id << ", " << p.name << "," << p.address;
        return out;
    }
};

class Genre {
private:
    int id;
    string name;

public:
    Genre() : id(0), name("") {}
    Genre(int id, string name) : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }
    void ConsoleInput() {
        cout << "\nEnter genre ID: ";
        cin >> id;
        cin.ignore();
        cout << "\nEnter genre name: ";
        getline(cin,name);
    }
    void printtofile(ostream& os)const {
        os << id << " " << name;
    }
    friend istream& operator>>(istream& in, Genre& g) {
        in >> g.id >> g.name;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Genre& g) {
        out << g.id << ": " << g.name;
        return out;
    }
};
#endif