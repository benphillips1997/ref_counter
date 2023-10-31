#include "my_string.hpp"

// normal constructor
my_string::my_string(const char* s)
{
    pStr = new char[getLength(s)]; //allocate memory for pointer
    //sets each character
    for (int i = 0; i < getLength(s); i++){
        pStr[i] = s[i];
    }
}

// overload assignment operator
my_string& my_string::operator=(const my_string& s)
{
    // if object is the same or pointing to the same allocated data
    if (&s == this || s.pStr == pStr) {
        return *this; 
    }

    pStr = s.pStr;
    return *this;
} 

// destructor
my_string::~my_string()
{
    //cout << "Destructor called for: ";
    //print();
}

char my_string::getChar(const int& i)
{
    assert(i < getLength(pStr));
    return pStr[i];
}

void my_string::setChar(const int& i, const char& c)
{
    assert(i < getLength(pStr));
    pStr[i] = c;
}

void my_string::print() const
{   
    //print each character to console
    for (int i = 0; i < getLength(pStr); i++){
        cout << pStr[i];
    }
    cout << endl;
}

int my_string::getLength(const char* s) const
{
    if (s == 0) { return 0; }

    int i;
    //increment i until null character is reached
    for (i = 0; s[i] != '\0'; i++) { /* do nothing */ }
    return i;
}