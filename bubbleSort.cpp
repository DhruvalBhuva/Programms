#include <iostream>
using namespace std;

void printArray(int array[], int total)
{
    for (int i = 0; i < total; i++)
    {
        cout << array[i] << " ";
    }
}

void bubbleSort(int array[], int total)
{

    int temp;
    for (int i = 0; i < total; i++)
    {
        for (int j = i + 1; j < total; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
}

int main()
{
    int i, number;
    cout << "Enter Size of array: ";
    cin >> number;

    int array[number];

    for (i = 0; i < number; i++)
    {
        cout << "Enter " << i << " Number :";
        cin >> array[i];
    }
    bubbleSort(array, number);
    printArray(array, number);

    return 0;
}