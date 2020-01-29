#include "RestaurantOrganizer.h"

using namespace std;

int tree_array_size = 1000000;

int get_parent(int index)
{
    if ((index > 0) && (index < tree_array_size))
    {
        return (index - 1) / 2;
    }
    return -1;
}

void heapify(int arr[], int n, int i, int arr2[])
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (arr[l] == arr[i])
    {
        if (arr2[l] < arr2[i])
        {
            swap(arr2[l], arr2[i]);
        }
    }

    if (arr[l] == arr[r])
    {
        if (l <= 100000 || r <= 100000)
            if (arr2[l] > arr2[r])
            {
                swap(arr2[l], arr2[r]);
            }
    }

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        swap(arr2[i], arr2[largest]);
        heapify(arr, n, largest, arr2);
    }
}

RestaurantOrganizer::RestaurantOrganizer(const vector<int> &tableCapacityInput)
{
    numberOfTables = tableCapacityInput.size();
    for (int i = 0; i < numberOfTables; i++)
    {
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
        heapUp(i);
    }
}

void RestaurantOrganizer::addNewGroup(int groupSize, ofstream &outFile)
{
    int new_table = tableCapacity[0] - groupSize;

    if (new_table < 0)
    {
        outFile << -1 << endl;
        return;
    }

    outFile << heap[0] << endl;

    int heap_last = heap[numberOfTables - 1];
    int temp = heap[0];
    heap[0] = heap_last;
    heap[numberOfTables - 1] = temp;

    int lastElement = tableCapacity[numberOfTables - 1];

    tableCapacity[0] = lastElement;
    tableCapacity[numberOfTables - 1] = new_table;
    heapify(tableCapacity, numberOfTables, 0, heap);
}

void RestaurantOrganizer::heapUp(int index)
{
    if (index > 0 && tableCapacity[get_parent(index)] < tableCapacity[index])
    {
        swap(tableCapacity[get_parent(index)], tableCapacity[index]);
        swap(heap[get_parent(index)], heap[index]);
        heapUp(get_parent(index));
    }
}

void RestaurantOrganizer::heapDown(int index)
{
}

void RestaurantOrganizer::printSorted(ofstream &outFile)
{
    for (int i = numberOfTables; i > 0; i--)
    {
        outFile << tableCapacity[0] << " ";
        swap(tableCapacity[0], tableCapacity[numberOfTables - 1]);
        numberOfTables--;
        heapify(tableCapacity, numberOfTables, 0, heap);
    }
}
