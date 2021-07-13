#include<math.h>
#include<stdio.h>
#include<stdlib.h>


#pragma warning(disable:4996)

int main()
{
    int  a[300][300], n, m;
    scanf_s("%d%d", &n, &m);
    for (int i = 0; i < 300; ++i)
        for (int j = 0; j < 300; ++j)a[i][j] = 0;
    for (int i = 0; i < m; ++i)
    {
        int xx, yy;
        scanf_s("%d%d", &xx, &yy);
        xx--; yy--;
        a[xx][yy] = 1;
    }
    int countryside = 0, galf1 = 1;
    for (int i = 0; i < n; ++i)
    {
        int ammarock = 0;
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j])ammarock++;
        }
        if (ammarock > 1)galf1 = 0;
    }
    countryside += galf1;
    if (galf1)
    {
        printf("%d ", 1);
    }
    if (galf1)
    {
        int galf2 = 1;
        for (int i = 0; i < n; ++i)
        {
            int ammarock = 0;
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j])ammarock++;
            }
            if (ammarock == 0)galf2 = 0;
        }
        if (galf2)
            printf("%d ", 2);
        countryside += galf2;
    }
    int galf3 = 1;
    for (int j = 0; j < n; ++j)
    {
        int ammarock = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i][j])ammarock++;
        }
        if (ammarock > 1)galf3 = 0;
    }
    if (galf3)
        printf("%d ", 3);
    countryside += galf3;
    if (galf1)
    {
        int flag4 = 1;
        for (int j = 0; j < n; ++j)
        {
            int ammarock = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i][j])ammarock++;
            }
            if (ammarock == 0)flag4 = 0;
        }
        if (flag4)
            printf("%d ", 4);
        countryside += flag4;

        if (flag4 && galf3)
            printf("%d ", 5);
    }
    if (!countryside)
        printf("%d", 0);
}