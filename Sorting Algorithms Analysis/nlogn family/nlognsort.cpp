// Header Files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
//---------------------------------------------
using namespace std;

// Functions Prototyping
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void merge(int arr[], int l, int mid, int r);
int partition(int arr[], int l, int r);
void mergesort(int arr[], int l, int r);
void quicksort(int arr[], int l, int r);
//----------------------------------------------
// code-driver
int main()
{
    ofstream output;
    output.open("report.txt");
    int tester[13] = {10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 100000, 200000, 300000, 400000, 500000};
    while (1)
    {
        cout << "Press : 1 for Quick Sort | 2 for Merge Sort | 3 for Heap Sort" << endl;
        cout << endl;
        int p, k;
        cin >> p;
        clock_t Time;
        cout << "Select : 1 for Best case | 2 for Average case | 3 for Worst case" << endl;
        cin >> k;
        string s;
        if (k == 1)
            s = "best-case.txt";
        if (k == 2)
            s = "average.txt";
        if (k == 3)
            s = "worst-case.txt";
        cout << "Insert n : 1 - 500005" << endl;
        int n;
        cin >> n;
        if (p == 1)
        {
            cout << "Generating Quick Sort Report into report.txt ..." << endl;
            output << s << " REPORT for Quick Sort" << endl;
            ifstream input;
            input.open(s);
            int arr[n];
            for (int i = 0; i < n; i++)
                input >> arr[i];
            Time = clock();
            quicksort(arr, 0, n - 1);
            Time = clock() - Time;
            for (int i = 0; i < n; i++)
                output << arr[i] << " ";
            output << endl;
            output << "Test case-size : " << tester[n] << endl;
            output << "Time : " << fixed << setprecision(9) << (double)Time / CLOCKS_PER_SEC << " s" << endl;
            input.close();
            cout << "Report Generated successfully" << endl;
            output.close();
            return 0;
        }
        else if (p == 2)
            return 0;
        else if (p == 3)
            return 0;
        else
            cout << "Please select valid input ... " << endl;
    }
}
// Functions--------------------------------

//====== HEAP-SORTING =================================
// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int Max = i;           // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (left < n && arr[left] > arr[Max])
        Max = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[Max])
        Max = right;
    // If largest is not root
    if (Max != i)
    {
        swap(arr[i], arr[Max]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, Max);
    }
}
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//==================== MERGE SORT =============================
void mergesort(int arr[], int l, int r)
{
    int mid; // partition
    if (r > l)
    {
        mid = (l + r) / 2;      // partitioning the array
        mergesort(arr, l, mid); // recursively calling for smaller segments
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
// merging two subarrays in nlogn via two pointer method
void merge(int arr[], int l, int mid, int r)
{
    int size1 = mid - l + 1;
    int size2 = r - mid;
    int size = size1 + size2;

    int temp1[size1], temp2[size2];
    for (int i = 0; i < size1; i++)
        temp1[i] = arr[l + i];
    for (int i = 0; i < size2; i++)
        temp2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < size1 && j < size2)
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k++] = temp1[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
        }
    }
    while (i < size1)
        arr[k++] = temp1[i++];
    while (i < size2)
        arr[k++] = temp2[j++];
    return;
}

//==================== QUICK SORT =============================
// function to find the partition index
int partition(int arr[], int l, int r)
{
    int pivot = arr[l]; // pivot
    int i = l, j = r;   // Index of smaller element
    while (i < j)
    {
        while (arr[j] > pivot)
            j--;
        while (arr[i] <= pivot)
            i++;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    return j;
}
void quicksort(int arr[], int l, int r)
{
    if (r > l) // until left index is not greater than right index
    {
        int pivot = partition(arr, l, r); // partition index
        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, r);
    }
}