#include <iostream>

using namespace std;

int getPositiveNumber()
{
    int number = -1;

    while (number < 1)
    {
        cin >> number;
        if (number < 1)
        {
            cout << "Number must be positive. Try again: ";
        }
    }

    return number;
}

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;

        else
            b = b - a;
    }
    return a;
}

int main()
{
    int a;
    int b;

    cout << "This program will calculate GCD for positive numbers using Euclidean algorithm.\n";
    cout << "Please enter first number: ";
    a = getPositiveNumber();
    cout << "Please enter second number: ";
    b = getPositiveNumber();

    cout << "GCD(" << a << ", " << b << "): " << gcd(a, b) << endl;

    return 0;
}