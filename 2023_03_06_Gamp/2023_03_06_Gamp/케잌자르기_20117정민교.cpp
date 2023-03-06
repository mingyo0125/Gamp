#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    int big, small;
    cin >> a >> b;
    cin >> c >> d;

    if (a > b)
    {
        big = a;
        small = b;
    }
    else
    {
        big = b;
        small = a;
    }

    if ((small < c && c < big) && !(small < d && d < big))
    {
        cout << "cross";
    }
    else if ((small < d && d < big) && !(small < c && c < big))
    {
        cout << "cross";
    }
    else
    {
        cout << "not cross";
    }
    
}