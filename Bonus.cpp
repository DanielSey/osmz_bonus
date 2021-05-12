#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(vector<int> arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    srand(time(NULL));
    vector<int> arr;
    int a = 0;

    cout << "\tHistogram\t\n";
    while (true) {
        auto start = chrono::high_resolution_clock::now();
        arr.clear();
        for (int i = 0; i < 10; i++)
        {
            arr.push_back(rand() % 100 + 1);
        }
        bubbleSort(arr, arr.size());
        auto finish = chrono::high_resolution_clock::now();
        cout << std::chrono::duration_cast<chrono::nanoseconds>(finish - start).count() << "ns\t\t";
        for (int j = 0; j < (finish - start).count(); j += 100)
        {
            cout << "*";
        }
        cout << endl;
    }
}