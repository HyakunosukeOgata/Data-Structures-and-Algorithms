#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
private:
    vector<int> data;

    // Function to merge two subarrays of data[]
    void merge(int left, int middle, int right) {
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temp arrays
        vector<int> L(n1), R(n2);

        // Copy data to temp arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = data[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = data[middle + 1 + j];

        // Merge the temp arrays back into data[left..right]
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                data[k] = L[i];
                i++;
            } else {
                data[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            data[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            data[k] = R[j];
            j++;
            k++;
        }
    }

    // Function to perform merge sort on data[]
    void mergeSort(int left, int right) {
        if (left < right) {
            // Find the middle point
            int middle = left + (right - left) / 2;

            // Sort first and second halves
            mergeSort(left, middle);
            mergeSort(middle + 1, right);

            // Merge the sorted halves
            merge(left, middle, right);
        }
    }

public:
    // Function to set data
    void setData(const vector<int>& newData) {
        data = newData;
    }

    // Function to initiate merge sort
    void sort() {
        if (!data.empty()) {
            mergeSort(0, data.size() - 1);
        }
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
    MergeSort sorter;
    sorter.setData({38, 27, 43, 3, 9, 82, 10});
    cout << "Original array:" << endl;
    sorter.printData();

    sorter.sort();
    cout << "Sorted array:" << endl;
    sorter.printData();

    return 0;
}
