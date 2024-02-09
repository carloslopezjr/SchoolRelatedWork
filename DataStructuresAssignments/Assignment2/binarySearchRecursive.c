#include <stdio.h>
#include <time.h>



int binarySearch(int *arr, int low, int high, int key) {
    while (low <= high) {

        int mid = (low + high) / 2;

        if (key > arr[mid])
        {
            return binarySearch(arr, mid + 1, high, key);

        }
        else if (key < arr[mid])
        {
            return binarySearch(arr, low, mid - 1, key);

        }
        else
        {
           return mid;
        }

        if (low > high)
        {
            return -1;
        }
    }
}

int main()
{

    clock_t start_t, end_t;
    double total_t;

    printf("Lopez, nvu267\n");

    int key;
    int arr[5];

    printf("Binary Search (Recursive Approach)\n");
    printf("Enter 5 elements:\n\n");

    int i = 0;
    while (i < 5)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    printf("\n");

    printf("Enter key element to search:\n");
    scanf("%d", &key);

    int low = 0;
    int high = 5 - 1;

    start_t = clock();

    int index = binarySearch(arr, low, high, key);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Element found at index: %d\n", index);

    printf("Total time taken by CPU (End Time - Start Time)/clock_per_second: %f\n", total_t);

    return 0;
}