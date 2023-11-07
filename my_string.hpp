#include <iostream>
#include <assert.h>

using namespace std;


class my_string
{
private:
    char *pStr;
public:
    my_string() : pStr(nullptr) {}    //default constructor
    my_string(const char* s);         //normal constructor
    my_string(const my_string& s) : pStr(s.pStr) {} //copy constructor
    my_string& operator=(const my_string& s);       //assignment operator overload
    ~my_string() {}
    
    char getChar(const int& i);
    void setChar(const int& i, const char& c);
    void print() const;

    int getLength(const char* str) const;
};