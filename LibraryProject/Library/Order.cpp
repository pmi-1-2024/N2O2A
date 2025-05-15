#include "Order.h"

Order::Order() : id(int()), bookID(int()), userID(""), startDay("") {}

Order::Order(int i, int bid, string uid, string sd): id(i), bookID(bid), userID(uid), startDay(sd) {}

int Order::getId() const
{
	return id;
}

int Order::getBookID() const
{
	return bookID;
}

string Order::getUserID() const
{
	return userID;
}

void Order::ConsolePrint() const
{
	cout << "\nOrder ID: " << id << ", Book ID: " << bookID;
	cout << "\nUser ID: " << userID << ", Start Date: " << startDay;
}

void Order::ConsoleInput()
{
    cout << "\nEnter Order ID: ";
    cin >> id;
    cout << "\nEnter Book ID: ";
    cin >> bookID;
    cout << "\nEnter User ID: ";
    cin >> userID;
    cout << "\nEnter Start Date: ";
    getline(cin, startDay);
}

istream& operator>>(istream& in, Order& o)
{
    in >> o.id >> o.bookID >> o.userID, in.ignore(), getline(in, o.startDay);
    return in;
}

ostream& operator<<(ostream& out, const Order& o)
{
    out << o.id << " " << o.bookID << " " << o.userID << " " << o.startDay;
    return out;
}
