#include <iostream>

using namespace std;

#define ARR_SIZE 20

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

void find_first(int arr[], int to_find)
{

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (arr[i] == to_find)
        {
            cout << "Found " << arr[i] << ", at index: " << i << endl;
            break;
        }
    }
}

void find_all(int arr[], int to_find)
{

    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (arr[i] == to_find)
        {
            cout << "Found " << arr[i] << ", at index: " << i << endl;
        }
    }
}

int main()
{
    int arr[ARR_SIZE] = {2, 5, 6, 1, 3, 2, 90, 3, 2, 5, 4, 3, 2, 1, 4, 3, 2, 5, 7, 4};
    int to_find = 0;

    system("clear");
    cout << "======================================================================" << endl;
    cout << "This program will find number in array" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter number to find: ";
    to_find = get_number_between(1, 100);
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\"Find first alg\" result:" << endl;
    find_first(arr, to_find);
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "\"Find all alg\" result:" << endl;
    find_all(arr, to_find);
    cout << endl;
    return 0;
}