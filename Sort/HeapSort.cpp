#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
private:
    vector<int> data;

    // Function to turn a subtree into a max heap
    void heapify(int n, int i) {
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left child
        int r = 2 * i + 2; // right child

        // If left child is larger than root
        if (l < n && data[l] > data[largest])
            largest = l;

        // If right child is larger than the largest so far
        if (r < n && data[r] > data[largest])
            largest = r;

        // If largest is not root
        if (largest != i) {
            swap(data[i], data[largest]);

            // Recursively heapify the affected subtree
            heapify(n, largest);
        }
    }

    // Function to perform heap sort
    void heapSort() {
        int n = data.size();

        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(n, i);

        // One by one extract an element from heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(data[0], data[i]);

            // Call max heapify on the reduced heap
            heapify(i, 0);
        }
    }

public:
    // Function to set data
    void setData(const vector<int>& newData) {
        data = newData;
    }

    // Function to initiate heap sort
    void sort() {
        heapSort();
    }

    // Function to print data
    void printData() {
        for (int i : data) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    HeapSort sorter;
    sorter.setData({38, 27, 43, 3, 9, 82, 10});
    cout << "Original array:" << endl;
    sorter.printData();

    sorter.sort();
    cout << "Sorted array:" << endl;
    sorter.printData();

    return 0;
}
