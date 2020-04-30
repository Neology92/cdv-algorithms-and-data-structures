#include <iostream>
#include <iomanip>
using namespace std;

float getPositiveNumber()
{
    float number = -1;

    while (number <= 0)
    {
        cin >> number;
        if (number <= 0)
        {
            cout << "Number must be positive. Try again: ";
        }
    }

    return number;
}

int get1Or2()
{
    int ODP = -1;

    while (ODP != 1 && ODP != 2)
    {
        cin >> ODP;
        if (ODP != 1 && ODP != 2)
        {
            cout << "Enter 1 or 2. Try again: ";
        }
    }

    return ODP;
}

float calculateWeeklyPayment(float LG, float SG)
{
    const short ETAT = 40;
    float PL = 0;

    if (LG <= ETAT)
    {
        PL = LG * SG;
    }
    else
    {
        PL = ETAT * SG;
        PL += (LG - ETAT) * (SG * 2);
    }

    return PL;
}

float calculateAnnualPayment(float PL)
{
    // DAYS_IN_YEAR     ->  366;
    // ALL_FREE_DAYS    ->  113;
    const int WORKING_DAYS_IN_YEAR = 366 - 113;
    float TYG = WORKING_DAYS_IN_YEAR / 5.0;

    return TYG * PL;
}

float getTaxRate(float WR)
{
    if (WR <= 20000)
        return 19;
    else if (WR <= 30000)
        return 21;
    else
        return 28;
};

float calculateTax(float SP, float WR)
{
    float PODATEK = 0;

    if (SP == 19)
    {

        PODATEK = WR * 0.19;
    }
    else if (SP == 21)
    {
        PODATEK = 20000 * 0.19;
        PODATEK += (WR - 20000) * 0.21;
    }
    else
    {
        PODATEK = 20000 * 0.19;
        PODATEK += 10000 * 0.21;
        PODATEK += (WR - 30000) * 0.28;
    }

    return PODATEK;
}

float calculateIncome(float WR, float PODATEK)
{
    return (WR - PODATEK);
}

int main()
{
    cout << setprecision(2) << fixed;
    cout << "\n=========================================" << endl;
    cout << "| This program will calculate: " << endl;
    cout << "| - Weekly earnings" << endl;
    cout << "| - If You want to: Annual earnings, tax and income." << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Enter number of hours worked in week: ";
    float LG = getPositiveNumber();
    cout << "| Enter Your hourly rate: ";
    float SG = getPositiveNumber();

    float PL = calculateWeeklyPayment(LG, SG);

    cout << "-    -    -    -    -    -    -    -    -" << endl;
    cout << "| Hours worked in week: " << LG << endl;
    cout << "| Payment:              " << PL << " PLN " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Do You want me to calculate your annual earnings, tax and income?" << endl;
    cout << "| Calculations will be based on your weekly earnings (including extra hours)." << endl;
    cout << "| 1 - Yes" << endl;
    cout << "| 2 - No" << endl;
    cout << "| Your answer: ";
    int ODP = get1Or2();

    if (ODP == 1)
    {
        float WR = calculateAnnualPayment(PL);
        float SP = getTaxRate(WR);
        float PODATEK = calculateTax(SP, WR);
        float DOCHOD = calculateIncome(WR, PODATEK);
        cout << "-    -    -    -    -    -    -    -    -" << endl;
        cout << "| Annual payment: " << WR << " PLN" << endl;
        cout << "| Tax rate:       " << SP << "%" << endl;
        cout << "| Tax:            " << PODATEK << " PLN" << endl;
        cout << "| Annual income:  " << DOCHOD << " PLN" << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "| Thank You for using this application!" << endl;
    cout << "=========================================" << endl
         << endl;

    return 0;
}
