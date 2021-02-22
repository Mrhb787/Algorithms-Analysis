// Header Files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <time.h>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib> // for generating random float numbers
//---------------------------------------------
using namespace std;
using namespace std::chrono;
// Functions Prototyping
void count_sort(int arr[], int n, int maxx);
void RadixcountSort(int arr[], int n, int exp);
void radixsort(int arr[], int n, int maxx);
void bucketSort(float arr[], int n);
void generate_random(float arr2[], int n);
//----------------------------------------------
// code-driver
int main()
{
    cout << "Press : 1 for Count Sort | 2 for Radix Sort | 3 for Bucket Sort" << endl;
    int p, k;
    string s, g;
    cin >> p;
    if (p == 1)
        g = "Count Sort";
    if (p == 2)
        g = "Radix Sort";
    if (p == 3)
        g = "Bucket Sort";
    cout << "Select : 1 for Best case | 2 for Average case | 3 for Worst case" << endl;
    cin >> k;
    if (k == 1)
        s = "best-case.txt";
    if (k == 2)
        s = "average.txt";
    if (k == 3)
        s = "worst-case.txt";
    cout << "Insert n : 1 - 50005 to test" << endl;
    int n;
    cin >> n;
    ifstream input;
    input.open(s);
    int arr[n];
    float arr2[n];
    int maxx = 0;
    generate_random(arr2, n);
    for (int i = 0; i < n; i++)
    {
        input >> arr[i];
        maxx = max(maxx, arr[i]);
    }
    cout << maxx << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
        maxx = max(maxx, arr[i]);
    if (p == 1)
        count_sort(arr, n, maxx);
    if (p == 2)
        radixsort(arr, n, maxx);
    if (p == 3)
        bucketSort(arr2, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    double Time = ((double)duration.count()) / 1000000000.0;
    cout << "Test case-size : " << n << endl;
    cout << "Time taken : " << fixed << setprecision(9) << Time << endl;
    input.close();
    cout << "Report Generated successfully" << endl;
    return 0;
}
// Functions--------------------------------
void count_sort(int arr[], int n, int maxx)
{
    int hash[maxx + 1] = {0}; // creating the hash array to store frequency values
    for (int i = 0; i < n; i++)
        hash[arr[i]] += 1;
    for (int i = 0, j = 0; i <= maxx; i++)
    {
        while (hash[i]--)
        {
            arr[j++] = i;
        }
    }
    return;
}
void RadixcountSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, c[10] = {0};
    for (i = 0; i < n; i++)
        c[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        c[i] += c[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[c[(arr[i] / exp) % 10] - 1] = arr[i];
        c[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n, int maxx)
{
    for (int exp = 1; maxx / exp > 0; exp *= 10)
        RadixcountSort(arr, n, exp);
}
void bucketSort(float arr2[], int n)
{
    vector<float> b[n];
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr2[i]; // Index in bucket
        b[bi].push_back(arr2[i]);
    }
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr2[index++] = b[i][j];
}
void generate_random(float arr2[], int n)
{
    srand((unsigned int)time(NULL));
    float a = 5.0;
    for (int i = 0; i < n; i++)
        arr2[i] = (float(rand()) / float((RAND_MAX)) * a);
}