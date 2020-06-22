#include <iostream>
#include <conio.h>

using namespace std;

int get_positive_number()
{
    int num = 0;
    cin >> num;
    while (num <= 0)
    {
        cout << "Please enter number greater than 0: ";
        cin >> num;
    }
    return num;
}

int get_number_between(int low, int high)
{
    int num = 0;
    cin >> num;
    while (num > high || num < low)
    {
        cout << "Please enter number between " << low << " and " << high << ": ";
        cin >> num;
    }
    return num;
}

void show_menu()
{
    system("clear");
    cout << "======================================================" << endl;
    cout << "                         MENU                         " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "1. Show first element" << endl;
    cout << "2. Show array's content" << endl;
    cout << "3. Calculate difference of the last and the 1st element " << endl;
    cout << "4. Calculate sum of all elements in the array" << endl;
    cout << "5. Show choosen element" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "------------------------------------------------------" << endl;
}

void show_array_content(int arr[], int size)
{
    cout << "Your array: [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
            cout << ", ";
    }

    cout << " ]" << endl;
}

int calc_sum_of_elems(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

void show_choosen_elem(int arr[], int size)
{
    int index = 0;
    cout << "Choose index of element to show: ";
    index = get_number_between(0, size - 1);
    cout << "Number at index " << index << " is: " << arr[index];
}

int main()
{
    int size = 0;

    system("clear");
    cout << "======================================================================" << endl;
    cout << "This program allows you to do some actions on array created by yourself" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter size of the array: ";
    size = get_positive_number();

    system("clear");
    cout << "======================================================================" << endl;
    cout << "Let's fill the array..." << endl;
    cout << "----------------------------------------------------------------------" << endl;

    int arr[size];
    for (int i = 0; i < size; i++)
    {

        cout << "Enter " << i + 1 << ". number: ";
        cin >> arr[i];
    }

    system("clear");
    cout << "======================================================================" << endl;
    cout << "Done! You've created the beautiful array." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << endl
         << "Press any key to continue ...";
    getch();

    int choice = -1;
    while (choice != 0)
    {
        show_menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "First element of array: " << arr[0] << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 2:
            show_array_content(arr, size);
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 3:
            cout << "DIfference of last and first element is: " << arr[size - 1] - arr[0] << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 4:
            cout << "Sum of all elems in array is equal to: " << calc_sum_of_elems(arr, size) << endl;
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        case 5:
            show_choosen_elem(arr, size);
            cout << endl
                 << "Press any key to continue ...";
            getch();
            break;
        }
    }

    return 0;
}