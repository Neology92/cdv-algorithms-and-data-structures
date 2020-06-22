#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define ARR_SIZE 10

class Rectangle
{
public:
    int start_x, start_y, end_x, end_y;

    Rectangle(int s_x = 0, int e_x = ARR_SIZE - 1, int s_y = 0, int e_y = ARR_SIZE - 1)
    {
        start_x = s_x;
        end_x = e_x;
        start_y = s_y;
        end_y = e_y;
    }

    void organize()
    {
        if (start_x > end_x)
        {
            int buff = end_x;
            end_x = start_x;
            start_x = buff;
        }
        if (start_y > end_y)
        {
            int buff = end_y;
            end_y = start_y;
            start_y = buff;
        }
    }
};

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

void find_all(int arr[][ARR_SIZE], int to_find, Rectangle borders)
{
    for (int i = borders.start_x; i <= borders.end_x; i++)
    {
        for (int j = borders.start_y; j <= borders.end_y; j++)
        {
            if (arr[i][j] == to_find)
            {
                cout << "Found " << arr[i][j] << ", at: [" << i << "][" << j << "]" << endl;
            }
        }
    }
}

void fill_array(int arr[][ARR_SIZE])
{
    srand(time(NULL));

    for (int i = 0; i < ARR_SIZE; i++)
    {
        for (int j = 0; j < ARR_SIZE; j++)
        {
            arr[i][j] = rand() % 100 + 1;
        }
    }
}

int main()
{
    int arr[ARR_SIZE][ARR_SIZE];
    int to_find = 0;

    fill_array(arr);

    system("clear");
    cout << "======================================================================" << endl;
    cout << "This program will find number in 2d array" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter number to find [1-100]: ";
    to_find = get_number_between(1, 100);

    Rectangle borders;

    system("clear");
    cout << "======================================================================" << endl;
    cout << "Time to read boundaries" << endl;
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Enter start x border [0-" << ARR_SIZE - 1 << "]: ";
    borders.start_x = get_number_between(0, ARR_SIZE - 1);
    cout << "Enter end x border [0-" << ARR_SIZE - 1 << "]: ";
    borders.end_x = get_number_between(0, ARR_SIZE - 1);
    cout << "Enter start y border [0-" << ARR_SIZE - 1 << "]: ";
    borders.start_y = get_number_between(0, ARR_SIZE - 1);
    cout << "Enter end y border [0-" << ARR_SIZE - 1 << "]: ";
    borders.end_y = get_number_between(0, ARR_SIZE - 1);

    borders.organize();

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << "Finding algorithm results (searching for " << to_find << " ):" << endl;
    find_all(arr, to_find, borders);
    cout << endl
         << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    cout << endl
         << "Done! Press any key to exit ...";
    getch();

    return 0;
}