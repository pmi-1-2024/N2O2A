#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
using namespace std;
class Order
{
private:
    int id;
    int bookID;
    string userID;
    string startDay;

public:
    Order();
    Order(int id, int bid, string uid, string sd);

    int getId() const;
    int getBookID() const;
    string getUserID() const;
    void ConsolePrint()const;
    void ConsoleInput();
    friend istream& operator>>(istream& in, Order& o);
    friend ostream& operator<<(ostream& out, const Order& o);
};
#endif

