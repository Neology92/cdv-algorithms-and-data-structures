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
    int answer = -1;

    while (answer != 1 && answer != 2)
    {
        cin >> answer;
        if (answer != 1 && answer != 2)
        {
            cout << "Enter 1 or 2. Try again: ";
        }
    }

    return answer;
}

float calculateWeeklyPayment(float workedHours, float hourlyRate)
{
    const short FULL_TIME_HOURS = 40;
    float payment = 0;

    if (workedHours <= FULL_TIME_HOURS)
    {
        payment = workedHours * hourlyRate;
    }
    else
    {
        payment = FULL_TIME_HOURS * hourlyRate;
        payment += (workedHours - FULL_TIME_HOURS) * (hourlyRate * 2);
    }

    return payment;
}

float calculateAnnualPayment(float weeklyPayment)
{
    // DAYS_IN_YEAR     ->  366;
    // ALL_FREE_DAYS    ->  113;
    const int WORKING_DAYS_IN_YEAR = 366 - 113;
    float weeks = WORKING_DAYS_IN_YEAR / 5.0;

    return weeks * weeklyPayment;
}

float getTaxRate(float annualPayment)
{
    if (annualPayment <= 20000)
        return 0.19;
    else if (annualPayment <= 30000)
        return 0.21;
    else
        return 0.28;
};

float calculateTax(float taxRate, float annualPayment)
{
    return taxRate * annualPayment;
}

float calculateIncome(float taxRate, float annualPayment)
{
    return annualPayment * (1 - taxRate);
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
    float workedHours = getPositiveNumber();
    cout << "| Enter Your hourly rate: ";
    float hourlyRate = getPositiveNumber();

    float weeklyPayment = calculateWeeklyPayment(workedHours, hourlyRate);

    cout << "-    -    -    -    -    -    -    -    -" << endl;
    cout << "| Hours worked in week: " << workedHours << endl;
    cout << "| Payment:              " << weeklyPayment << " PLN " << endl;
    cout << "-----------------------------------------" << endl;
    cout << "| Do You want me to calculate your annual earnings, tax and income?" << endl;
    cout << "| Calculations will be based on your weekly earnings (including extra hours)." << endl;
    cout << "| 1 - Yes" << endl;
    cout << "| 2 - No" << endl;
    cout << "| Your answer: ";
    int answer = get1Or2();

    if (answer == 1)
    {
        float annualPayment = calculateAnnualPayment(weeklyPayment);
        float taxRate = getTaxRate(annualPayment);
        float tax = calculateTax(taxRate, annualPayment);
        float income = calculateIncome(taxRate, annualPayment);
        cout << "-    -    -    -    -    -    -    -    -" << endl;
        cout << "| Annual payment: " << annualPayment << " PLN" << endl;
        cout << "| Tax rate:       " << taxRate * 100 << "%" << endl;
        cout << "| Tax:            " << tax << " PLN" << endl;
        cout << "| Annual income:  " << income << " PLN" << endl;
    }
    cout << "-----------------------------------------" << endl;
    cout << "| Thank You for using this application!" << endl;
    cout << "=========================================" << endl
         << endl;

    return 0;
}
