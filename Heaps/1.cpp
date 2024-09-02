#include<bits/stdc++.h>
using namespace std;

class Heap {
public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {
        size = size + 1; // For 1-based indexing
        int index = size;
        arr[index] = value;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] < arr[index]) {
                // Swap with parent if the parent is smaller
                swap(arr[parent], arr[index]);
                index = parent; // Move up to the parent index
            } else {
                break;
            }
        }
    }

    int deleteV() {
        if (size == 0) return -1; // Edge case: empty heap

        int ans = arr[1]; // Root value to return
        arr[1] = arr[size]; // Move last element to root
        size--;

        int index = 1;
        while (index <= size) {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[largest] < arr[left]) {
                largest = left;
            }

            if (right <= size && arr[largest] < arr[right]) {
                largest = right;
            }

            if (largest == index) {
                break;
            } else {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }

        return ans;
    }

    void heapify(int arr[], int n, int i) {
        int index = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = index;

        if (left <= n && arr[largest] < arr[left]) {
            largest = left;
        }

        if (right <= n && arr[largest] < arr[right]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(arr, n, largest); // Recursively heapify the affected sub-tree
        }
    }

    void buildHeap(int arr[], int n) {
        for (int i = n / 2; i > 0; i--) {
            heapify(arr, n, i);
        }
    }
};

int main() {
    Heap heap;

    // Inserting multiple values into the heap
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(30);
    heap.insert(40);

    // Printing the heap array
    cout << "Heap elements after insertions: ";
    for (int i = 1; i <= heap.size; i++) {
        cout << heap.arr[i] << " ";
    }
    cout << endl;

    // Deleting the root element
    int deletedValue = heap.deleteV();
    cout << "Deleted root value: " << deletedValue << endl;

    // Printing the heap array after deletion
    cout << "Heap elements after deletion: ";
    for (int i = 1; i <= heap.size; i++) {
        cout << heap.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
