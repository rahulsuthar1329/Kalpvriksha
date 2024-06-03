#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 4;
    int cols = 4;

    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        *(matrix + i) = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            *(*(matrix + i) + j) = i * cols + j + 1;
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    int left = 0, right = rows - 1, top = 0, bottom = rows - 1;
    while (top < bottom && left < right)
    {
        int temp = *(*(matrix + top) + left);
        *(*(matrix + top) + left) = *(*(matrix + top) + right);
        *(*(matrix + top) + right) = temp;

        temp = *(*(matrix + bottom) + left);
        *(*(matrix + bottom) + left) = *(*(matrix + bottom) + right);
        *(*(matrix + bottom) + right) = temp;

        top++, left++, bottom--, right--;
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }

    return 0;
}
