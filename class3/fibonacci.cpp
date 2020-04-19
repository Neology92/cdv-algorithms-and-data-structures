#include <iostream>
#include <string>

using namespace std;

int getNumberFromRange(int downLim, int upperLim)
{
    int number;
    cin >> number;

    while (number < downLim || number > upperLim)
    {
        cout << "Number must be from range <" << downLim << ", " << upperLim << "> Try again: ";
        cin >> number;
    }

    return number;
}

long long fibonacci(int n)
{
    long long a = 0;
    long long b = 1;

    while (n > 0)
    {
        a += b;
        b = a - b;
        n--;
    }

    return a;
}

int main()
{
    int n;

    cout << "This program will calculates fibonacci n'th value.\n";
    cout << "Please enter n from range <0, 92>: ";
    n = getNumberFromRange(0, 92);

    string nth;
    if (n == 1)
    {
        nth = "1st";
    }
    else if (n == 2)
    {

        nth = "2nd";
    }
    else
    {
        nth = to_string(n) + "th";
    }

    cout << "Fibonacci " << nth << " value is: " << fibonacci(n) << endl;

    return 0;
}