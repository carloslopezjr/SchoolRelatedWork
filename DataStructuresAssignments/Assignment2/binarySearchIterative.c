#include <stdio.h>
#include <time.h>

int main()
{

    clock_t start_t, end_t;
    double total_t;

    printf("Lopez, nvu267\n");

    int key;
    int arr[5];

    printf("Binary Search (Iterative Approach)\n");
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

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else if (key < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            printf("Element found at index: %d\n", mid);
            break;
        }

        if (low > high)
        {
            printf("Element not found: -1\n");
            break;
        }
    }

    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("Total time taken by CPU (End Time - Start Time)/clock_per_second: %f\n", total_t);

    return 0;
}