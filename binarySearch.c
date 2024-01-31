#include <stdio.h>

int main()
{

    int n = 0;
    int key;

    printf("Give the size of the array: ");
    scanf("%d", &n);
    printf("\n");

    int arr[n];

    printf("Enter the elements for the array from biggest to smallest: \n");

    int i = 0;
    while (i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }

    printf("Give the key value: ");
    scanf("%d", &key);
    printf("\n");

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (key < arr[mid])
        {
            low = mid + 1;
        }
        else if (key > arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            printf("%d\n", mid);
            break;
        }

        if (low > high)
        {
            printf("-1\n");
            break;
        }
    }

    return 0;
}