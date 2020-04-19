#include <iostream>
#include <climits>

using namespace std;

long long silnia(int n)
{
    if (n < 2)
        return 1;

    return n * silnia(n - 1);
}

int main()
{
    int n = -1;
    long long res = 1;

    // Górny limit wynika z limitu typu long long: (21!) > (2^31 - 1)
    cout << "Program liczy silnie z n. Podaj n z przedzialu [0, 20]: ";
    cin >> n;

    while (n < 0 || n > 20)
    {
        cout << "Zmienna n musi zostac wybrana z przedzialu [0, 20]." << endl;
        cout << "Podaj n: ";
        cin >> n;
    }

    res = silnia(n);

    cout << "Silnia z n wynosi: " << res << endl;

    return 0;
}