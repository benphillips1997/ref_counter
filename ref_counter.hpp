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
    ref_counter(T* t) : pRefCount(new int(1)), pType(t) {}  // normal constructor
    ref_counter(const ref_counter& r) : pType(r.pType), pRefCount(r.pRefCount) { *pRefCount += 1; }  // copy constructor

    ref_counter& operator=(const ref_counter& r)  // overload assignment operator
    {
        // if object is the same or pointing to the same allocated data
        if (&r == this || r.pType == pType) {
            cout << "Same reference" << endl;
            return *this;
        }

        // if object is pointing to different allocated data
        if (r.pType != pType) {
            cout << "Reassigned";
            *pRefCount -= 1;
            // if there are no references left then free the memory
            if (getRefCount() == 0) { 
                cout << ", ref count now 0.";
                delete pRefCount;
                delete pType;
            }
            cout << endl;
        }

        // copy the references and increment the ref count
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

        // if there are no references left then free the memory
        if (getRefCount() == 0){
            cout << ", ref count now 0. ";
            delete pRefCount;
            delete pType;
        }
        cout << endl;
    }

    T& operator*() { return *pType; }  // dereference operator overload
    T* operator->() { return pType; }  // member access operator overload

    int getRefCount() const { return *pRefCount; }
    void printRefCount() const { cout << " [" << getRefCount() << "]" << endl; }
};