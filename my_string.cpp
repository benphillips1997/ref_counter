// default constructor
my_string::my_string()
{
    refCount = 1;
    pStr = new char;
}

// normal constructor
my_string::my_string(const char* s)
{
    refCount = 1;
    pStr = new char[getLength(s)];
    for (int i = 0; i < getLength(s); i++){
        *(pStr+i) = *(s+i);
    }
}

// copy constructor  
my_string::my_string(my_string const& s)
{
    pStr = s.pStr;
    pRefCount = s.pRefCount;
    *pRefCount += 1;
}

// copy operator constructor
my_string& my_string::operator=(my_string const& s)
{
    pStr = s.pStr;
    pRefCount = s.pRefCount;
    *pRefCount += 1;
    return *this;
}

// destructor
my_string::~my_string()
{
    *pRefCount -= 1;

    if (*pRefCount == 0){
        delete pStr;
        cout << "Ref count is now: " << *pRefCount << endl;
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
    cout << " [" << *pRefCount << "]" << endl;
}

int my_string::getLength(const char* s) const
{
    int i;
    for (i = 0; *(s+i) != '\0'; i++) { /* do nothing */}
    return i;
}