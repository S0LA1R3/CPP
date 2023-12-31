#include <iostream>
using std::cout;
using std::endl;

void useLocal();
void useStaticLocal();
void useGlobal();

int x = 1;

int main()
{
    int x = 5;
    cout << "local x in main's outer scope is " << x << endl;

    {
        int x = 7;
        cout << "local x in main's inner scope is " << x << endl;
    }

    cout << "local x in main's inner scope is " << x << endl;

    useLocal();
    useStaticLocal();
    useGlobal();
    useLocal();
    useStaticLocal();
    useGlobal();

    cout << "\nlocal x in main is " << x << endl;
    return 0;
}

inline void useLocal()
{
    int x = 25;
    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    x++;
    cout << "local x is " << x << " on exiting useLocal" << endl;
}

inline void useStaticLocal()
{
    static int x = 50;
    cout << "\nlocal static x is " << x << " on entering useStaticLocal"
         << endl;
    x++;
    cout << "local static x is " << x << " on exiting useStaticLocal"
         << endl;
}

inline void useGlobal()
{
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}
