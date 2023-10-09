#include "my_string.hpp"
#include "my_string.cpp"


int main() 
{
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
}
