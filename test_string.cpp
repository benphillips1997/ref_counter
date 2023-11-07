#include "my_string.hpp"
#include "ref_counter.hpp"


int main() 
{  
    //int ref_counter tests

    /*ref_counter<int> i(new int(55));
    cout << *i;
    i.printRefCount();
    {
        ref_counter<int> j(new int(10));
        cout << *j;
        j.printRefCount();
        {
            ref_counter<int> k = j;
            cout << *k;
            k.printRefCount();
            cout << *j;
            j.printRefCount();
        }
        cout << *j;
        j.printRefCount();
        j = j;
        j = i;
        cout << *i;
        i.printRefCount();
        cout << *j;
        j.printRefCount();
    }
    cout << *i;
    i.printRefCount();
    *i = 40;
    cout << *i;
    i.printRefCount();*/




    //my_string ref_counter tests

    /*ref_counter<my_string> s(new my_string("Hello world"));
    s->print();
    s.printRefCount();
    {
        ref_counter<my_string> t = s;
        s->print();
        s.printRefCount();
        t->print();
        t.printRefCount();
        cout << s->getChar(1) << endl;
        s->print();
        s.printRefCount();
        t->print();
        t.printRefCount();
    }
    s->setChar(1, 'E');
    s->print();
    s.printRefCount();*/


    ref_counter<my_string> s(new my_string("First object"));
    s->print();
    s.printRefCount();
    {
        ref_counter<my_string> t(new my_string("Second object"));
        s->print();
        s.printRefCount();
        t->print();
        t.printRefCount();
        s = t;
        s->print();
        s.printRefCount();
        t->print();
        t.printRefCount();
        s = s;
        s = t;
    }
    s->print();
    s.printRefCount();




    //my_string tests

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

    /*my_string s("First object");
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
    s.print();*/

}
