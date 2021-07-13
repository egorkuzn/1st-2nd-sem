#include <stdio.h>
#include <malloc.h>
#pragma warning (disable:4996)
int binsearch(int*, int, int, int);

int main() {
    int n;
    scanf("%d", &n);
    int* a = (int*)malloc((n) * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int q;
    scanf("%d", &q);
    int* r = (int*)malloc((q) * sizeof(int));
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        if (i == 0) {
            r[i] = binsearch(a, 0, n - 1, x);
        }
        else {
            r[i] = binsearch(a, 0, n - 1, x + r[i - 1]);
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", r[i]);
    free(a);
    free(r);
    return 0;
}
int binsearch(int* a, int l, int r, int x)
{
    int result = -1, m;
    if ((r == 0) && (a[0] == x))
        result = 0;
    else {
        while (l < r) {
            m = (l + r) / 2;
            if (a[m] > x) {
                r = m;
            }
            else {
                l = m;
            }
            if ((l == r) && (a[m] == x)) {
                result = m;
                break;
            }
            else if ((r - l == 1) && ((a[r] == x) || (a[l] == x))) {
                if (a[r] == x) {
                    result = r;
                    break;
                }
                else {
                    result = l;
                    break;
                }
            }
            else if ((r - l == 1) && ((a[r] != x) || (a[l] != x))) {
                break;
            }
        }
    }
    return result;
}