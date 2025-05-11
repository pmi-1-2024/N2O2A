#include <iostream>
#include <string>
using namespace std;

struct Author {
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

    friend istream& operator>>(istream& in, Author& a) {
        cout << "Enter ID: ";
        in >> a.id;
        in.ignore();
        cout << "Enter first name: ";
        getline(in, a.name);
        cout << "Enter surname: ";
        getline(in, a.surname);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Author& a) {
        out << "Author ID: " << a.id << ", Name: " << a.name << ", Surname: " << a.surname;
        return out;
    }
};


struct Publisher {
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

    friend istream& operator>>(istream& in, Publisher& p) {
        cout << "Enter Publisher ID: ";
        in >> p.id;
        in.ignore();
        cout << "Enter Publisher Name: ";
        getline(in, p.name);
        cout << "Enter Publisher Address: ";
        getline(in, p.address);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Publisher& p) {
        out << "Publisher ID: " << p.id << ", Name: " << p.name << ", Address: " << p.address;
        return out;
    }
};

struct Genre {
private:
    int id;
    string name;

public:
    Genre() : id(0), name("") {}
    Genre(int id, string name) : id(id), name(name) {}

    int getId() const { return id; }
    string getName() const { return name; }

    friend istream& operator>>(istream& in, Genre& g) {
        cout << "Enter Genre ID: ";
        in >> g.id;
        in.ignore();
        cout << "Enter Genre Name: ";
        getline(in, g.name);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Genre& g) {
        out << "Genre ID: " << g.id << ", Name: " << g.name;
        return out;
    }
};

struct Library {
private:
    int id;
    string name, address;
    int duration;

public:
    Library() : id(0), name(""), address(""), duration(0) {}
    Library(int id, string name, string address, int duration)
        : id(id), name(name), address(address), duration(duration) {}


    int getId() const { return id; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    int getDuration() const { return duration; }

    friend istream& operator>>(istream& in, Library& l) {
        cout << "Enter Library ID: "; in >> l.id;
        in.ignore();
        cout << "Enter Library Name: ";
        getline(in, l.name);
        cout << "Enter Library Address: ";
        getline(in, l.address);
        cout << "Enter Duration (days): ";
        in >> l.duration;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Library& l) {
        out << "Library ID: " << l.id << ", Name: " << l.name << ", Address: " << l.address << ", Duration: " << l.duration;
        return out;
    }
};

struct UserLibrary {
private:
    int userID;
    int libraryID;
    int roleID;

public:
    UserLibrary() : userID(0), libraryID(0), roleID(0) {}
    UserLibrary(int uid, int lid, int rid) : userID(uid), libraryID(lid), roleID(rid) {}

    int getUserID() const { return userID; }
    int getLibraryID() const { return libraryID; }
    int getRoleID() const { return roleID; }

    friend istream& operator>>(istream& in, UserLibrary& ul) {
        cout << "Enter User ID: ";
        in >> ul.userID;
        cout << "Enter Library ID: ";
        in >> ul.libraryID;
        cout << "Enter Role ID: ";
        in >> ul.roleID;
        return in;
    }

    friend ostream& operator<<(ostream& out, const UserLibrary& ul) {
        out << "UserLibrary User ID: " << ul.userID << ", Library ID: " << ul.libraryID << ", Role ID: " << ul.roleID;
        return out;
    }
};

struct LibraryBook {
private:
    int libraryID;
    int bookID;
    int quantity;

public:
    LibraryBook() : libraryID(0), bookID(0), quantity(0) {}
    LibraryBook(int lid, int bid, int qty) : libraryID(lid), bookID(bid), quantity(qty) {}

    int getLibraryID() const { return libraryID; }
    int getBookID() const { return bookID; }
    int getQuantity() const { return quantity; }

    friend istream& operator>>(istream& in, LibraryBook& lb) {
        cout << "Enter Library ID: ";
        in >> lb.libraryID;
        cout << "Enter Book ID: ";
        in >> lb.bookID;
        cout << "Enter Quantity: ";
        in >> lb.quantity;
        return in;
    }

    friend ostream& operator<<(ostream& out, const LibraryBook& lb) {
        out << "LibraryBook  Library ID: " << lb.libraryID << ", Book ID: " << lb.bookID << ", Quantity: " << lb.quantity;
        return out;
    }
};

struct Date {
private:
    int day, month, year;

public:
    Date() : day(1), month(1), year(2000) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    friend istream& operator>>(istream& in, Date& d) {
        cout << "Enter Day: ";
        in >> d.day;
        cout << "Enter Month: ";
        in >> d.month;
        cout << "Enter Year: ";
        in >> d.year;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Date& d) {
        out << d.day << "." << d.month << "." << d.year;
        return out;
    }
};


struct Order {
private:
    int id;
    int bookID;
    int userID;
    Date startDay;

public:
    Order() : id(0), bookID(0), userID(0), startDay() {}
    Order(int id, int bid, int uid, const Date& sd) : id(id), bookID(bid), userID(uid), startDay(sd) {}

    int getId() const { return id; }
    int getBookID() const { return bookID; }
    int getUserID() const { return userID; }
    Date getStartDay() const { return startDay; }

    friend istream& operator>>(istream& in, Order& o) {
        cout << "Enter Order ID: ";
        in >> o.id;
        cout << "Enter Book ID: ";
        in >> o.bookID;
        cout << "Enter User ID: ";
        in >> o.userID;
        cout << "Enter Start Date:\n";
        in >> o.startDay;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Order& o) {
        out << "Order ID: " << o.id << ", Book ID: " << o.bookID << ", User ID: " << o.userID << ", Start Date: " << o.startDay;
        return out;
    }
};
