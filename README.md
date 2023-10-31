# ASP_worksheet1

## Task 1

For task 1 I implemented a my_string class and you can find it in the 'my_string.hpp' file. This class contains a pointer to a string as a variable, a default and a normal constructor, a copy constructor, an overloaded assignment operator, and a destructor. It also contains functions to get and set characters from the string, a print function to print the entire string, and get function that would get the length of the string. Some of the function bodies that were only one line are defined here, whereas the rest of them I placed in the 'my_string.cpp' file.
```c++
class my_string
{
private:
    char *pStr;
public:
    my_string() : pStr(nullptr) {}    //default constructor
    my_string(const char* s);         //normal constructor
    my_string(const my_string& s) : pStr(s.pStr) {} //copy constructor
    my_string& operator=(const my_string& s);       //assignment operator overload
    ~my_string();                   //destructor
    
    char getChar(const int& i);
    void setChar(const int& i, const char& c);
    void print() const;

    int getLength(const char* str) const;
};
```

If the default constructor is called then a null pointer is assigned, whereas if the normal constructor is called then it will allocate memory equal to the length of the characters  of the passed parameter for the pStr variable. Then it will copy each letter from the parameter passed to the pStr variable, as you can see below.
```c++
my_string::my_string(const char* s)
{
    pStr = new char[getLength(s)]; //allocate memory for pointer
    //sets each character
    for (int i = 0; i < getLength(s); i++){
        pStr[i] = s[i];
    }
}
```

The copy constructor will be called when a my_string object is created and assigned to an existing my_string object. It copies the pStr pointer from the existing object that is passed as the parameter and assigns it to the pStr pointer for this object that is created.

The overload assignment operator will be called when an existing object of my_string is assigned to another. If the objects are the same or have the same reference to their pStr variable then it wil return the object and nothing will happen. Otherwise the pStr reference will be copied over and the object will be returned.
```c++
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
```

The getChar and setChar functions will return the character or change the character at the specified index.
```c++
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
```

The print function will iterate over each character in pStr and print it to the console.
```c++
void my_string::print() const
{
    //print each character to console
    for (int i = 0; i < getLength(pStr); i++){
        cout << pStr[i];
    }
    cout << endl;
}
```

I also have a getLength function to determine the length of the string. This will take a char pointer as a parameter and iterate over each character until a null character is reached. It will increment a variable each time and return the resulting length.
```c++
int my_string::getLength(const char* s) const
{
    if (s == 0) { return 0; }

    int i;
    //increment i until null character is reached
    for (i = 0; s[i] != '\0'; i++) { /* do nothing */ }
    return i;
}
```

I then created another file 'test_string.cpp' and created in the main function I tested the my_string class.
```c++
my_string s("Hello world");
s.print();
{
    my_string t = s;
    s.print();
    t.print();
    cout << s.getChar(1) << endl;
    s.print();
    t.print();
}
s.setChar(1,'E');
s.print();
```

You can see the output of this running below.


## Task 2

For task 2 I added functionality to track the reference count of the object. To do this I used an integer pointer that would be allocated memory using the 'new' keyword and set the value to 1 due to it being the first of this object upon the constructor being called. However if the copy constructor or assignment operator were to be called then it would instead just copy the pointer and increment the deferenced value of it as there would already be another object for one of these to be called. When one of the object goes out of scope and the destructor is then it will decrement the dereferenced pointer as a reference is being destroyed. While the is a reference to the object the allocated memory for the pointer will be there and will not be deleted. However if the reference count is 0 then the memory should be freed. To do this, inside the destructor there is an if statement that if the reference count reaches 0 then using the 'delete' keyword the memory to the pointer will be freed.


## Task 3

In this task I will demonstrate when there is a reference count of 0.


## Task 4

For task 4 I have created a container for referencing. To do this I have created a template class that uses the same method as before, however just implemented in another class. This can be used by inheriteing this referencing class.