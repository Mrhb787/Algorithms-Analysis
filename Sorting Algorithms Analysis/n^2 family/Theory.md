# Bubble-Sort
## Theory
> Bubble sort proceeds the list by scanning the adjancent elements and if they are out of order with respect to each other it exchanges them.

### Main condition
`if arr[i+1] < arr[i]`<br>
`swap(arr[i],arr[i+1])`
 
### Algorithm
```
int arr[n]={...}; // given a list of size n
for i in range(0,n)
    for j in range(i,n-1)
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1])
    //- inner loop ended
// outer loop ended
```

### Implementation in C++
```
// header files
#include<iostream>
using namespace std;

// function prototyping
void Bubble_Sort(int arr[],int n);

// Driver code 
signed main()
{
    int arr[10] = {9,8,10,6,6,1,1,12,55,12};
    Bubble_Sort(arr,sizeof(arr));
}

// Bubble_Sort Function

void Bubble_Sort(int arr[],int n)
{
    // if list is sorted we will check in O(n) and break the loop
    bool alreadysorted = true;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                alreadysorted = false;
                swap(arr[j],arr[j+1]);
            }
        } // inner loop ends
        if(alreadysorted == true)
        break;
    } // outer loop ends
return;
}

```

### Time & Space Complexities
- #### Time Complexity
  - Best-Case    : O(n) 
  - Average-Case : O(n<sup>2</sup>)
  - Worst-Case   : O(n<sup>2</sup>)
- #### Space Complexity
  - It is a ***in-place*** sorting algorithm hence no extra space is allocated therefore Space-Complexity Remains constant
  - O(1) 

## Conclusion
- #### It is an easy to implement algorithm and works quite well for small datasets not more than 10<sup>4</sup> However its not a preferred algorithm for large datasets as its Time-Complexity is O(n<sup>2</sup>) in Average as well as worst cases.