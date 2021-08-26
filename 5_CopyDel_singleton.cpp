class A
{
public:
    A(const A &ref) = delete;
    A(A &&ref) = delete;
    A &operator=(const A &ref) = delete;
    A &operator=(const A &&ref) = delete;

    static A &getA()
    {
        static A a;
        return a;
    }

private:
    A() = default;
};

int main()
{
    A &ptr = A::getA(); //singleton

    //copy not copied

    char *buff = new char[sizeof(ptr)];
    for (int i = 0; i < sizeof(ptr); ++i)
    {
        buff[i] = ((char *)&ptr)[i];
    }
    A *newPtr = (A *)buff;

    delete buff;
}