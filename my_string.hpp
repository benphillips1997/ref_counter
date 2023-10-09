#include <iostream>
#include <assert.h>

using namespace std;

template <class C>
class RefCounter
{
private:
    int refCount;
    int *pRefCount = &refCount;
public:
    RefCounter() : refCount(1) {}

    void IncrementRef(C const& s) 
    { 
        pRefCount = s.pRefCount;
        *pRefCount += 1;
    }
    void DecrementRef() { *pRefCount -= 1; }

    int GetRefCount() const { return *pRefCount; }
};


class my_string : public RefCounter<my_string>
{
private:
    char *pStr;
    /*int refCount;
    int *pRefCount = &refCount;*/
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