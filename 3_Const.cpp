#include <iostream>

class A
{
public:
    int getX() const //this will be const
    {
        y++; // mutable - good
        
        //work, but not good
        /*A* ptr = const_cast<A*>(this);
        ptr->x++;*/
        return x;
    }

private:
    mutable int y = 5;
    int x = 5;
};

int main()
{
    const int x = 5;
    //x++; error
    int y = 5;
    const int &refy = y;
    //refy++; error
    const int *ptry = &y;
    //(*ptry)++; error
    ptry = &x; //norm
    const int * const cptry = &y;
    //cptry = &x; error
    //(*cptry)++ error;
    A a;
    std::cout << a.getX();
}