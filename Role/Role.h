#ifndef ROLE_H
#define ROLE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Role {
private:
    string name;
    int id;
public:
    Role();
    Role(string name, int id);
    string GetName() const;
    int GetId() const;
    void SetName(string name);
    void SetId(int id);
    void ConsolePrint() const;
    void ConsoleRead();
    friend ostream& operator<<(ostream& out, const Role& role);
    friend istream& operator>>(istream& in, Role& role);
};

#endif