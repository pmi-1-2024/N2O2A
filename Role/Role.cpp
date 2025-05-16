#include "Role.h"

Role::Role() : name(""), id(0) {}

Role::Role(string name, int id) : name(name), id(id) {}

string Role::GetName() const {
    return name;
}
int Role::GetId() const {
    return id;
}

void Role::SetName(string name) {
    this->name = name;
}
void Role::SetId(int id) {
    this->id = id;
}

void Role::ConsolePrint() const {
    cout << "Role :" << id << ": " << name;
}
void Role::ConsoleRead() {
    cout << "Enter role ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter role name: ";
    getline(cin, name);
}

ostream& operator<<(ostream& out, const Role& role) {
    out << role.id << " " << role.name << " ";
    return out;
}
istream& operator>>(istream& in, Role& role) {
    in >> role.id, in.ignore(), getline(in, role.name, ';');
    return in;
}