#include <bits/stdc++.h>
using namespace std;
// 1. Swap Two Numbers Without Using a Temp Variable
void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
// 2. Reverse an Array Using Pointers
void reverse(int *arr, int n)
{
    int *start = arr;
    int *end = arr + n - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
// 3. Find the Middle of an Array Using Pointers
void printMiddle(int *arr, int n)
{
    int *mid = arr + (n / 2);
    cout << "Middle: " << *mid << endl;
}
// 4. Print Array in Reverse Using Recursion + Pointer
void printReverse(int *arr, int n)
{
    if (n == 0)
        return;
    cout << arr[n - 1] << " ";
    printReverse(arr, n - 1);
}

void modify(int *ptr)
{
    *ptr = *ptr + 10;
}

int main()
{

    // What is a Pointer : A pointer is a variable that stores the memory address of another variable.

    // Declaration and Initialization
    int x1 = 10;
    int *ptr = &x1;
    cout << *ptr << endl;
    cout << ptr << endl; // address of x

    // Pointers and Arrays
    int arr[3] = {10, 20, 30};
    int *p = arr;
    cout << *p << " " << *(p + 1) << " " << *(p + 2) << endl; // arr[i]==*(arr+i)

    // Pointers with Functions
    int b = 5;
    modify(&b);
    cout << b << endl;

    int a = 10;
    int *p1 = &a;
    int **pp = &p1;

    cout << "a  = " << a << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "**pp = " << **pp << endl;

    // pp -->  0x300
    //         |
    //         ↓
    // p  -->  0x200
    //         |
    //         ↓
    // a  -->  0x100  (value = 10)

    // Dynamic Memory Allocation (Heap) : use new and delete
    int *c = new int(5);
    cout << *c << endl;
    delete c;
    cout << *c << endl; // prints garbage

    int *arr1 = new int[5]; // Step 1
    arr1[0] = 10;           // Step 2
    cout << *arr1 << endl;  // Step 3
    delete[] arr1;          // Step 4
    cout << *arr1;          // Step 5 ❌ garbage

    // swap
    int x = 10, y = 20;
    swap(&x, &y);
    cout << endl
         << x << " " << y; // Output: 20 10
}