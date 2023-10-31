#include "my_string_ref_count.hpp"
//#include "ref_counter.hpp"


int main() 
{  
    /*my_string s("Hello world");
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
    s.print();*/

    my_string s("First object");
    s.print();
    {
        my_string t("Second object");
        s.print();
        t.print();
        s = t;
        s.print();
        t.print();
        s = s;
        s = t;
    }
    s.print();

}
