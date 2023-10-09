#include <iostream>
#include <assert.h>

using namespace std;

class my_string {
private:
    char *pStr;
    int refCount;
    int *pRefCount = &refCount;
public:
    my_string();
    my_string(const char* s);
    my_string(my_string const& s);
    my_string& operator=(my_string const& s);
    ~my_string();
    
    char getChar(const int& i) const;
    void setChar(const int& i, const char& c);
    void print() const;

    int getLength(const char* str) const;
};