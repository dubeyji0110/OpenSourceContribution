#include <stdio.h>
void print_array(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void merge(int a[], int p, int q, int r)
{
    int n1, n2, i, j;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    for (i = 1; i <= n1; i++)
    {
        L[i] = a[p + i - 1];
    }
    for (j = 1; j <= n2; j++)
    {
        R[j] = a[q + j];
    }
    L[n1 + 1] = 2147483647;
    R[n2 + 1] = 2147483647;
    i = 1;
    j = 1;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
    }
}
void merge_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
int main()
{
    int n = 0;
    printf("Size of array : ");
    scanf("%d", &n);
    int a[n], k = 0;
    printf("Kth element : ");
    scanf("%d", &k);
    printf("Elements of array : ");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 1, n);
    printf("Sorted array : ");
    print_array(a, n);
    printf("Kth largest : %d , Kth smallest : %d\n", a[n - k + 1], a[k]);
    return 0;
}
