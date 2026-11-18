
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    cout << "Name: Rohit Kumar" << endl;
    cout << "URN: 2514169" << endl;
    cout << "CRN: 2515244" << endl;

    cout << "Enter number of elements: ";
    cin >> n;

    if(n <= 0 || n > 100)
    {
        cout << "Invalid array size!";
        return 0;
    }

    int arr[100];

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    cout << "Sorted list: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
