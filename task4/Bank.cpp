#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Customer Class
class Customer {
private:
    string cID;
    string name;
    unsigned int age;
    char gender;
    vector<Account*> acc;
public:
    Customer(const string& cID,const string& n,const unsigned int& a,const char& g):{
        this->cID=cID;
        name=n;
        age=a;
        gender=g;
    }
};

// Account Class
class Account {
private:
    const string IBN;
    long double balance;
    vector<Transaction*> tran;
public:
    Account(const string& ibn): IBN(ibn), balance(0) {}
};

// Transaction Class
class Transaction {
private:

public:

};

// Helper Function


// Main Function
int main() {

    return 0;
}