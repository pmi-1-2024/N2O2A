#include "User.h"
#include <stdexcept>
#include <algorithm>

User::User(const string& first, const string& last, const string& id,
    const string& mail, const string& pass)
    : firstName(first), lastName(last), userId(id), email(mail), password(pass) {
    ValidateId(id);
    ValidateEmail(mail);
}

void User::ValidateId(const string& id) {
    if (id.length() != 8 || !all_of(id.begin(), id.end(), ::isdigit)) {
        throw invalid_argument("User ID must be an 8-digit number.");
    }
}

void User::ValidateEmail(const string& mail) {
    size_t atPos = mail.find('@');
    size_t dotPos = mail.find('.', atPos);

    if (atPos == string::npos || dotPos == string::npos || dotPos <= atPos + 1) {
        throw invalid_argument("Invalid email format.");
    }
}

string User::GetName() const {
    return firstName;
}

string User::GetLastName() const
{
    return lastName;
}

string User::GetEmail() const {
    return email;
}

string User::GetUserId() const {
    return userId;
}

void User::ConsolePrint() const
{
    cout << "\nUser: " << userId << ": " << firstName << " " << lastName << ", " << email;
}

void User::ConsoleInput()
{
    cout << "\nEnter ID: ";
    cin >> userId;
    cout << "\nEnter name: ";
    cin >> firstName;
    cin.ignore();
    cout << "\nEnter last name: ";
    getline(cin, lastName);
    cout << "\nEnter email: ";
    cin >> email;
    cout << "\nEnter password: ";
    cin >> password;
}

bool User::CheckPassword(const string& inputPassword) const {
    return password == inputPassword;
}

void User::SetPassword(const string& newPassword) {
    password = newPassword;
}

void User::SetEmail(const string& newEmail) {
    ValidateEmail(newEmail);
    email = newEmail;
}

istream& operator>>(istream& is, User& u)
{
    is >> u.userId >> u.firstName, is.ignore(), getline(is, u.lastName, ','), is >> u.email >> u.password;
    return is;
}

ostream& operator<<(ostream& os, const User& u)
{
    os << u.userId << " " << u.firstName << " " << u.lastName << ", " << u.email << " " << u.password;
    return os;
}