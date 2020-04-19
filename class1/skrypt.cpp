#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int n = 0;

    cout << "Hi mate, this program will sum of some next digits from 1 to n. \n";
    while (n <= 1)
    {

        cout << "Please enter n (greather than 1): ";
        cin >> n;

        if (n <= 1)
        {
            cout << "n must be grater than 1. Please try again. \n";
        }
    }

    int b = n;
    long long int sum = 0;

    while (a <= b)
    {

        sum += a;
        a++;
    }

    cout << "Sum of all digits between 1 and " << n << " is " << sum << "\n";
    cout << "Have a nice day!";

    return 0;
}