#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ARR_SIZE 20

void swap(int &a, int &b)
{
    int buff = a;
    a = b;
    b = buff;
}

void bubble_sort(int arr[])
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int elem = 0; elem < ARR_SIZE - 1 - i; elem++)
        {
            if (arr[elem] > arr[elem + 1])
            {
                swap(arr[elem], arr[elem + 1]);
            }
        }
    }
}

void fill_array(int arr[])
{
    srand(time(NULL));

    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

void print_arr_content(int arr[])
{
    cout << "Array: [ ";
    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

int main()
{
    int arr[ARR_SIZE];

    fill_array(arr);

    system("clear");
    cout << "======================================================================" << endl;
    cout << "This program will sort array using bubble sort" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Before sort:" << endl;
    print_arr_content(arr);

    cout << endl
         << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    bubble_sort(arr);
    cout << "After sort:" << endl;
    print_arr_content(arr);

    cout << endl
         << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << endl
         << "Done! Press any key to exit ...";
    getch();

    return 0;
}