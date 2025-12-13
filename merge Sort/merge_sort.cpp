#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[i + l];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = a[i + m+1];
    }
    int j = 0, i = 0, k = l;
    while (i<n1 && j<n2)
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
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
int main()
{
    int a[] = {7, 2, 4, 5, 3, 0, 7, 2, 5, 4, 8};
    int n = sizeof(a) / sizeof(a[0]);

    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}