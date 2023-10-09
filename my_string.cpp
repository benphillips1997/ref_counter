/*
    my_string methods
*/

// default constructor
my_string::my_string()
{
    //refCount = 1;
    pStr = new char;
}

// normal constructor
my_string::my_string(const char* s)
{
    //refCount = 1;
    pStr = new char[getLength(s)];
    for (int i = 0; i < getLength(s); i++){
        *(pStr+i) = *(s+i);
    }
}

// copy constructor  
my_string::my_string(my_string const& s)
{
    pStr = s.pStr;
    //pRefCount = s.pRefCount;
    //*pRefCount += 1;
    IncrementRef(s);
}

// copy operator constructor
my_string& my_string::operator=(my_string const& s)
{
    pStr = s.pStr;
    //pRefCount = s.pRefCount;
    //*pRefCount += 1;
    IncrementRef(s);
    return *this;
}

// destructor
my_string::~my_string()
{
    assert(GetRefCount() > 0);

    //*pRefCount -= 1;
    DecrementRef();

    if (GetRefCount() == 0){
        delete pStr;
        cout << "Ref count is now: " << GetRefCount() << endl;
    }
}

char my_string::getChar(const int& i) const
{
    char c = *(pStr+i);
    return c;
}

void my_string::setChar(const int& i, const char& c)
{
    *(pStr+i) = c;
}

void my_string::print() const
{
    for (int i = 0; *(pStr+i) != '\0'; i++){
        cout << *(pStr+i);
    }
    cout << " [" << GetRefCount() << "]" << endl;
}

int my_string::getLength(const char* s) const
{
    int i;
    for (i = 0; *(s+i) != '\0'; i++) { /* do nothing */}
    return i;
}