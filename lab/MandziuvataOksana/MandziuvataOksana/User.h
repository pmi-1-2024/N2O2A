#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User {
private:
    string firstName;
    string lastName;
    string userId;
    string email;
    string password;

    void ValidateId(const string& id);
    void ValidateEmail(const string& mail);

public:
    User(const string& first, const string& last, const string& id, const string& mail, const string& pass);
    string GetName() const;
    string GetLastName() const;
    string GetEmail() const;
    string GetUserId() const;
    void ConsolePrint()const;
    void ConsoleInput();
    bool CheckPassword(const string& inputPassword) const;
    void SetPassword(const string& newPassword);
    void SetEmail(const string& newEmail);
    friend istream& operator>>(istream& is, User& u);
    friend ostream& operator <<(ostream& os, const User& u);
};

#endif
