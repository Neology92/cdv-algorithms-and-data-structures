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

int main()
{
    int size_x = 0;
    system("clear");
    cout << "======================================================================" << endl;
    cout << "This program allows you to do some actions on array created by yourself" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter size x of the array: ";
    size_x = get_positive_number();

    int size_y = 0;
    cout << "Enter size y of the array: ";
    size_y = get_positive_number();

    system("clear");
    cout << "======================================================================" << endl;
    cout << "Let's fill the array..." << endl;
    cout << "----------------------------------------------------------------------" << endl;

    int arr[size_x][size_y];
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            cout << "Enter [" << i << "][" << j << "]. number: ";
            cin >> arr[i][j];
        }
    }

    system("clear");
    cout << "======================================================================" << endl;
    cout << "Done! You've created the beautiful array. That's it:" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    int sum = 0;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            cout << arr[i][j] << "\t";
            sum += arr[i][j];
        }
        cout << endl;
    }

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Sum of all elements: " << sum << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << endl
         << "Press any key to continue ...";
    getch();

    int index_x = 0;
    system("clear");
    cout << "======================================================================" << endl;
    cout << "Now you can choose element of array to display." << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter index x of the element: ";
    index_x = get_number_between(0, size_x - 1);

    int index_y = 0;
    cout << "Enter index y of the element: ";
    size_y = get_number_between(0, size_y - 1);

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Your element: " << arr[index_x][index_y] << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << endl
         << "Press any key to finish ...";
    getch();
    return 0;
}