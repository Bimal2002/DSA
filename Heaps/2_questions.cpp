#include<bits/stdc++.h>
using namespace std;

int findKthSmallest(int arr[], int n, int k) {
    // Create a max-heap
    priority_queue<int> pq;

    // Insert the first k elements of the array into the heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        if (pq.top() > arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // The top of the heap is the k-th smallest element
    return pq.top();
}

int findKthLargest(int arr[], int n, int k) {
    // Create a min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert the first k elements of the array into the heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        if (pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // The top of the heap is the k-th largest element
    return pq.top();
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int smallest = findKthSmallest(arr, n, k);
    cout << "The " << k << "-th smallest element is " << smallest << endl;

    int largest = findKthLargest(arr, n, k);
    cout << "The " << k << "-th largest element is " << largest << endl;

    return 0;
}
