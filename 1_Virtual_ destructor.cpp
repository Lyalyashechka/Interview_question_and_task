#include <iostream>

class A
{
public:
    virtual ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

int main()
{
    std::cout << "The same types, all good:" << std::endl;
    B* b = new B();
    delete b;
    std::cout << "If destructor not virtual, will called only ~A(): "<<std::endl;
    A* a = new B();
    delete a;

}