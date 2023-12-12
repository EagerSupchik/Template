#include <iostream>
using namespace std;

template <typename T>
T Max(const T e[], int size) 
{
    T max = e[0];
    for (int i = 1; i < size; i++) 
    {
        if (e[i] > max)max = e[i];
    }
    return max;
}



template <typename T>
T Min(const T e[], int size) 
{
    T min = e[0];
    for (int i = 1; i < size; i++) 
    {
        if (e[i] < min)min = e[i];
    }
    return min;
}


template <typename T>
void Sort(T e[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (e[j] > e[j + 1])swap(e[j], e[j + 1]);
        }
    }
}

template <typename T>
int Search(const T e[], int size, const T& k) 
{
    int l = 0;
    int r = size - 1;

    while (l <= r) 
    {
        int mid = l + (r - l) / 2;

        if (e[mid] == k)return mid;

        if (e[mid] < k)l = mid + 1;

        else r = mid - 1;
    }
    return 404;
}

template <typename T>
void Replace(T e[], int size, const T& first, const T& second) 
{
    for (int i = 0; i < size; i++) 
    {
        if (e[i] == first)e[i] = second;
    }
}

int main()
{
    int size = 0;
    int element;
    cout << "Type a size: ";
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        element = 0;
        cout << "Type the " << i << " element: ";
        cin >> element;
        arr[i] = element;

    }

    cout << Max(arr, size) << std::endl;
    cout << Min(arr, size) << std::endl;

    Sort(arr, size);
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << "; ";
    }
    cout << endl;

    int key = 0;
    cout << "Type a key: ";
    cin >> key;
    int el = Search(arr, size, key);
    cout << "key: " << key << " index: " << el << endl;

    int first = 0;
    cout << "Type the old value: ";
    cin >> first;
    int second = 0;
    cout << "Type the new value: ";
    cin >> second;
    Replace(arr, size, first, second);

    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << "; ";
    }
    cout << endl;

    delete[] arr;
    arr = nullptr;
}