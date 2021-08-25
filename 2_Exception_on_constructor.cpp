#include <iostream>

class B
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};

class A
{
public:
    A()
    {
        //destructor will not be called - leak memory
        ptr = new B();
        throw 1;
        // solution - smart pointer
        // ptr = std::make_unique<B>();
    }
    ~A()
    {
        delete ptr;
    }

private:
    //std::unique_ptr<B> ptr;
    B *ptr;
};

int main()
{
    try
    {
        A a;
    }
    catch (...)
    {
    }       
}