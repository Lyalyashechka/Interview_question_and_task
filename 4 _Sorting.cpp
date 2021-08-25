#include <iostream>

namespace MergeSort
{
    void merge(int *arr, int left, int right, int mid)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *leftArray = new int[n1];
        int *rightArray = new int[n2];
        for (int i = 0; i < n1; ++i)
        {
            leftArray[i] = arr[left + i];
        }
        for (int i = 0; i < n2; ++i)
        {
            rightArray[i] = arr[mid + 1 + i];
        }
        int indexSubFirst = 0;
        int indexSubSecond = 0;
        int indexOfMerged = left;

        while (indexSubFirst < n1 && indexSubSecond < n2)
        {
            if (leftArray[indexSubFirst] <= rightArray[indexSubSecond])
            {
                arr[indexOfMerged] = leftArray[indexSubFirst];
                indexSubFirst++;
            }
            else
            {
                arr[indexOfMerged] = rightArray[indexSubSecond];
                indexSubSecond++;
            }
            indexOfMerged++;
        }

        while (indexSubFirst < n1)
        {
            arr[indexOfMerged] = leftArray[indexSubFirst];
            indexSubFirst++;
            indexOfMerged++;
        }

        while (indexSubSecond < n2)
        {
            arr[indexOfMerged] = rightArray[indexSubSecond];
            indexSubSecond++;
            indexOfMerged++;
        }
    }

    void merge_sort(int *arr, int end, int begin = 0)
    {
        if (begin >= end)
        {
            return;
        }
        int mid = begin + (end - begin) / 2;
        merge_sort(arr, mid, begin);
        merge_sort(arr, end, mid + 1);
        merge(arr, begin, end, mid);

    }
}

void bubble_sort(int *a, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int ar[10] = {4, 56, 7, 3, 2, 6, 7, 5, 99, 100};
    bubble_sort(ar, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << ar[i] << " ";
    }
    std::cout << std::endl;

    int ar1[10] = {4, 56, 7, 3, 2, 6, 7, 5, 99, 100};
    MergeSort::merge_sort(ar1, 10);
    for (int i = 0; i < 10; i++)
    {
        std::cout << ar1[i] << " ";
    }
    std::cout << std::endl;
}