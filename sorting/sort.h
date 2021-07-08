#include <iostream>
#include <vector>

class Sort
{

public:
    Sort()
    {
    }

private:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void printBinary(std::vector<int> &v)
    {

        for (auto x : v)
        {

            std::cout << x << ":";
            for (int bitplace = 6; bitplace >= 0; bitplace--)
            {
                std::cout << ((x & 1 << bitplace) != 0);
            }
            std::cout << std::endl;
        }
    }

    void printArray(std::vector<int> &arr)
    {
        for (auto x : arr)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    void merge(std::vector<int> &arr, int start, int mid, int end)
    {

        std::vector<int> sortArr;

        int first = start, second = mid;

        while (first < mid && second <= end)
        {
            if (arr[first] < arr[second])
            {
                sortArr.push_back(arr[first]);
                first++;
            }
            else
            {
                sortArr.push_back(arr[second]);
                second++;
            }
        }

        while (first < mid)
        {
            sortArr.push_back(arr[first]);
            first++;
        }

        while (second <= end)
        {
            sortArr.push_back(arr[second]);
            second++;
        }

        for (int i = start; i <= end; i++)
        {
            arr[i] = sortArr[i - start];
        }
    }

    void mergeSort(std::vector<int> &arr, int start, int end)
    {

        if (start == end)
        {
            return;
        }

        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid + 1, end);
    }

    int partition(std::vector<int> &arr, int start, int end)
    {

        int pivot = arr[end];

        int left = start, right = end - 1;
        while (left < right)
        {
            if (arr[left] > pivot)
            {
                swap(arr[left], arr[right]);
                right--;
            }
            else
            {
                left++;
            }
        }

        if (arr[left] < pivot)
        {
            left++;
        }

        swap(arr[left], arr[end]);

        return left;
    }

    void quickSort(std::vector<int> &arr, int start, int end)
    {

        if (start >= end)
        {
            return;
        }

        int pivotIdx = partition(arr, start, end);
        quickSort(arr, start, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, end);

        return;
    }

    void radixSort(std::vector<int> &v, int start, int end, int sig_bit)
    {
        // Step 1) Segregate all the numbers with zero highest significant bit at the start of the array
        // Step 2) Apply this process for next significant bit as well
        // Step 3) Continue this until least significant bit reached.

        if (sig_bit < 0 || start == end)
        {
            return;
        }
        int left = start, right = end;

        while (left < right)
        {

            if (v[left] & 1 << sig_bit)
            {

                swap(v[left], v[right]);
                right--;
            }
            else
            {
                left++;
            }
        }

        if (v[left] & 1 << sig_bit)
        {
            left--;
        }

        radixSort(v, start, left, sig_bit - 1);
        radixSort(v, left + 1, end, sig_bit - 1);
    }

public:
    void selectionSort(std::vector<int> &arr)
    {

        for (int i = 0; i < arr.size() - 1; i++)
        {
            int minIdx = i;

            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }

            swap(arr[i], arr[minIdx]);
        }
    }

    void insertionSort(std::vector<int> &arr)
    {

        for (int i = 1; i < arr.size(); i++)
        {

            for (int j = i - 1; j >= 0; j--)
            {

                if (arr[j] <= arr[j + 1])
                {
                    break;
                }

                swap(arr[j], arr[j + 1]);
            }
        }

        printArray(arr);
    }

    void quickSort(std::vector<int> &arr)
    {
        quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    void mergeSort(std::vector<int> &arr)
    {
        mergeSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    void radixSort(std::vector<int> &arr)
    {

        radixSort(arr, 0, arr.size() - 1, 13);
        printArray(arr);
    }
};