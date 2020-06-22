#include <iostream>
#include <conio.h>

using namespace std;

int get_natural_number()
{
    int num = 0;
    cin >> num;
    while (num < 0)
    {
        cout << "Please enter _natural_ number: ";
        cin >> num;
    }
    return num;
}

void show_menu(int a, int b)
{
    system("clear");
    cout << "======================================================" << endl;
    cout << "                         MENU                         " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Calcualte sum of numbers from " << a << " to " << b << endl;
    cout << "2. Calcualte sum of squares of numbers from " << a << " to " << b << endl;
    cout << "3. Calcualte average of numbers from " << a << " to " << b << endl;
    cout << "4. Exit" << endl;
    cout << endl;
    cout << "------------------------------------------------------" << endl;
}

int calc_sum(int a, int b)
{
    int elem = a;
    int sum = 0;

    while (elem <= b)
    {
        sum += elem;
        elem++;
    }

    return sum;
}

int calc_sqrs_sum(int a, int b)
{
    int elem = a;
    int sum = 0;

    while (elem <= b)
    {
        sum += elem * elem;
        elem++;
    }

    return sum;
}

float calc_avg(int a, int b)
{
    int elem = a;
    int sum = 0;
    int quantity = 0;

    while (elem <= b)
    {
        sum += elem;
        elem++;
        quantity++;
    }

    float avg = (float)sum / quantity;
    return avg;
}

void swap(int *a, int *b)
{
    int buff = *a;
    *a = *b;
    *b = buff;
}

int main()
{
    system("clear");
    cout << "======================================================================" << endl;
    cout << "This programm will calculate some values based on numbers from a to b." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please enter two natural numbers (a and b)" << endl;
    cout << endl;
    int a;
    int b;

    cout << "Enter a: ";
    a = get_natural_number();
    cout << "Enter b: ";
    b = get_natural_number();

    if (a > b)
        swap(a, b);

    int choice = 0;
    while (choice != 4)
    {
        show_menu(a, b);
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Sum : " << calc_sum(a, b) << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 2:
            cout << "Sum of squares : " << calc_sqrs_sum(a, b) << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 3:
            cout << "Avg : " << calc_avg(a, b) << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        }
    }

    return 0;
}