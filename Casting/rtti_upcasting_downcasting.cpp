/*
    SYNTAX: dynamic_cast <new_type>(expression)

    * Dynamic_cast is used at runtime to find correct down-cast
    * Need at least one virtual function in base class
    * If the cast is successful, dynamic_cast returns a value of type new_type.
    * If the cast fails and new_type is a pointer type, it returns a null pointer of that type
    * If the cast fails and new_type is a reference type, it throws an exception that
    *  matches a handler of type std::bad_cast

    * Work only on polymorphic base class (at least one virtual function in base class)
    *  because it uses this info to decide about wrong down-cast
    * It is used for up-cast (Derived->Base) and down-case (Base->Derived), but it is mainly
    *  used for correct downcast
    * Using this cast has runtime overhead, because it checks object types at run time using
    *  RTTI (Run Time Type Information)
    * If we are sure that we will never cast to wrong object then we should always avoid
    *  this cast and use static_cast
*/

#include <bits/stdc++.h>
using namespace std;

class Base
{
    virtual void print() { cout << "BASE" << endl; }
};

class Derived1 : public Base
{
    void print() { cout << "DERIVED1" << endl; }
};

class Derived2 : public Base
{
    void print() { cout << "DERIVED2" << endl; }
};

int main()
{
    Derived1 D1;

    Base *ptr = dynamic_cast<Base *>(&D1); // upcast

    Derived2 *D2Ptr = dynamic_cast<Derived2 *>(ptr);
    // Derived1 *D2Ptr = dynamic_cast<Derived1 *>(ptr);

    if (D2Ptr == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        cout << "NOT NULL" << endl;
    }

    try
    {
        Derived1 &refe = dynamic_cast<Derived1 &>(D1);
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
    }
}