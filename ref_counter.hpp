#include <iostream>
#include <assert.h>
 
using namespace std;

template <class T>
class ref_counter
{
private:
    int *pRefCount;
    T *pType;
public:
    ref_counter() : pRefCount(new int(1)), pType(new T) {}  // default constructor
    ref_counter(const T* t) : pRefCount(new int(1)) // normal constructor
    { 
        T s(t);
        pType = s;
    }
    ref_counter(const ref_counter& r) : pType(r.pType), pRefCount(r.pRefCount) { *pRefCount += 1; }  // assignment constructor
    ref_counter& operator=(const ref_counter& r)  // overload assignment operator
    {
        // if object is the same or pointing to the same allocated data
        if (&r == this || r.pType == pType) {
            return *this;
        }

        // if object is pointing to different allocated data
        if (r.pType != pType) {
            *pRefCount -= 1;
            if (getRefCount() == 0) { 
                cout << "No references left" << endl;
                delete pRefCount;
                delete pType;
            }
        }

        pRefCount = r.pRefCount;
        pType = r.pType;
        *pRefCount += 1;
        return *this;
    }
    ~ref_counter()  // destructor
    {
        cout << "Destructor called";
        
        assert(getRefCount() > 0);

        *pRefCount -= 1;

        if (getRefCount() == 0){
            cout << ", ref count now 0. ";
            delete pRefCount;
            delete pType;
        }
        cout << endl;
    }

    int getRefCount() const { return *pRefCount; }
};