#include <stdio.h>
// function to sort the subsection a[i .. j] of the array a[]
void merge_sort(int i, int j, int a[], int aux[])
{
    if (j <= i)
    {
        return; // subsection kosong atau hanya satu elemen
    }
    int mid = (i + j) / 2;
    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    merge_sort(i, mid, a, aux); // mengurutkan left sub-array secara rekursif
    merge_sort(mid + 1, j, a, aux); // mengurutkan right sub-array secara rekursif
    int pointer_left = i; // pointer_left menunjuk ke awal left sub-array
    int pointer_right = mid + 1; // pointer_right menunjuk ke awal right sub-array
    int k; // k adalah counter loop

    // loop dari i hingga j untuk mengisi setiap elemen dari array merged final
    for (k = i; k <= j; k++)
    {
        if (pointer_left == mid + 1)
        { // pointer kiri telah mencapai batas
            aux[k] = a[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == j + 1)
        { // pointer kanan telah mencapai batas
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        else if (a[pointer_left] < a[pointer_right])
        {
            // pointer kiri menunjuk ke elemen yang lebih kecil
            aux[k] = a[pointer_left];
            pointer_left++;
        }
        else
        { // pointer kanan menunjuk ke elemen yang lebih kecil
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++)
    {
        a[k] = aux[k];
    }
}

int main()
{
    int a[100], aux[100], n, i, d, swap;
    printf("Masukan jumlah elemen didalam array:\n");
    scanf("%d", &n);
    printf("Masukan %d bilangan integer\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(0, n - 1, a, aux);
    printf("Menampilkan array yang telah diurutkan:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", a[i]);
    return 0;
}

