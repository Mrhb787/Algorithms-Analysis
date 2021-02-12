#include <iostream>
#include <time.h>
#include <ctime>
#include <fstream>
using namespace std;
void Insertion_sort(int arr[], int n);
void Selection_sort(int arr[], int n);
void Bubble_sort(int arr[], int n);
int main()
{
    cout << "Enter n in between 1 - 5000000\n";
    int n;
    cin >> n;
    // Opening Test case files
    ifstream best;
    best.open("best-case.txt");
    ifstream worst;
    worst.open("worst-case.txt");
    ifstream random;
    random.open("random-case.txt");

    cout << "Enter : 1 to Insertion Sort | 2 for Selection Sort | 3 for Bubble Sort \n";
    int p;
    cin >> p;
    if (p == 1)
    {
        int arr[n];
        // for best case
        for (int i = 0; i < n; i++)
            best >> arr[i];
        // starting the clock
        clock_t Time;
        Time = clock();
        Insertion_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Insertion_sort :- \n";
        cout << "Best-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for worst case
        for (int i = 0; i < n; i++)
            worst >> arr[i];
        Time = clock();
        Insertion_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Insertion_sort :- \n";
        cout << "Worst-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for random case
        for (int i = 0; i < n; i++)
            random >> arr[i];
        Time = clock();
        Insertion_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Insertion_sort :- \n";
        cout << "Random-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // closing files
        best.close();
        worst.close();
        random.close();
    }
    if (p == 2)
    {
        // starting the clock
        int arr[n];
        // for best case
        for (int i = 0; i < n; i++)
            best >> arr[i];
        clock_t Time;
        Time = clock();
        Selection_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Selection_sort :- \n";
        cout << "Best-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for worst case
        for (int i = 0; i < n; i++)
            worst >> arr[i];
        Time = clock();
        Selection_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Selection_sort :- \n";
        cout << "Worst-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for random case
        for (int i = 0; i < n; i++)
            random >> arr[i];
        Time = clock();
        Selection_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Selection_sort :- \n";
        cout << "Random-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // closing files
        best.close();
        worst.close();
        random.close();
    }
    if (p == 3)
    {

        int arr[n];
        // for best case
        for (int i = 0; i < n; i++)
            best >> arr[i];
        // starting the clock
        clock_t Time;
        Time = clock();
        Bubble_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Bubble_sort :- \n";
        cout << "Best-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for worst case
        for (int i = 0; i < n; i++)
            worst >> arr[i];
        Time = clock();
        Bubble_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Bubble_sort :- \n";
        cout << "Worst-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // for random case
        for (int i = 0; i < n; i++)
            random >> arr[i];
        Time = clock();
        Bubble_sort(arr, n);
        Time = clock() - Time;
        cout << "Time Taken for Bubble_sort :- \n";
        cout << "Random-case : " << (double)Time / CLOCKS_PER_SEC << " seconds" << endl;

        // closing files
        best.close();
        worst.close();
        random.close();
    }
    return 0;
}
void Insertion_sort(int arr[], int n) // Insertion sort function
{
    int curr;
    for (int i = 1, j; i < n; i++)
    {
        curr = arr[i];
        j = i - 1;
        while (arr[j] > curr && j > -1)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = curr;
    }
    return;
}
void Selection_sort(int arr[], int n) // Selection_sort function
{
    for (int i = 0, k; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[k])
                k = j;
        swap(arr[k], arr[i]);
    }
    return;
}
void Bubble_sort(int arr[], int n) // bubble sorting function
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    return;
}