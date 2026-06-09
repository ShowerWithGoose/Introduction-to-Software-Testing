#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1\n");
    }
    if (n == 2)
    {
        printf("1 2\n");
        printf("2 1\n");
    }
    if (n == 3)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    printf("%d %d %d\n", a1, a2, a3);
                }
            }
        }
    }
    if (n == 4)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        printf("%d %d %d %d\n", a1, a2, a3, a4);
                    }
                }
            }
        }
    }
    if (n == 5)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            printf("%d %d %d %d %d\n", a1, a2, a3, a4, a5);
                        }
                    }
                }
            }
        }
    }
    if (n == 6)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            for (a6 = 1; a6 <= n; a6++)
                            {
                                if (a6 == a5 || a6 == a4 || a6 == a3 || a6 == a2 || a6 == a1)
                                    continue;
                                printf("%d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6);
                            }
                        }
                    }
                }
            }
        }
    }
    if (n == 7)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            for (a6 = 1; a6 <= n; a6++)
                            {
                                if (a6 == a5 || a6 == a4 || a6 == a3 || a6 == a2 || a6 == a1)
                                    continue;
                                for (a7 = 1; a7 <= n; a7++)
                                {
                                    if (a7 == a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2 || a7 == a1)
                                        continue;
                                    printf("%d %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, a7);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (n == 8)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            for (a6 = 1; a6 <= n; a6++)
                            {
                                if (a6 == a5 || a6 == a4 || a6 == a3 || a6 == a2 || a6 == a1)
                                    continue;
                                for (a7 = 1; a7 <= n; a7++)
                                {
                                    if (a7 == a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2 || a7 == a1)
                                        continue;
                                    for (a8 = 1; a8 <= n; a8++)
                                    {
                                        if (a8 == a7 || a8 == a6 || a8 == a5 || a8 == a4 || a8 == a3 || a8 == a2 || a8 == a1)
                                            continue;
                                        printf("%d %d %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, a7, a8);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (n == 9)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            for (a6 = 1; a6 <= n; a6++)
                            {
                                if (a6 == a5 || a6 == a4 || a6 == a3 || a6 == a2 || a6 == a1)
                                    continue;
                                for (a7 = 1; a7 <= n; a7++)
                                {
                                    if (a7 == a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2 || a7 == a1)
                                        continue;
                                    for (a8 = 1; a8 <= n; a8++)
                                    {
                                        if (a8 == a7 || a8 == a6 || a8 == a5 || a8 == a4 || a8 == a3 || a8 == a2 || a8 == a1)
                                            continue;
                                        for (a9 = 1; a9 <= n; a9++)
                                        {
                                            if (a9 == a8 || a9 == a7 || a9 == a6 || a9 == a5 || a9 == a4 || a9 == a3 || a9 == a2 || a9 == a1)
                                                continue;
                                            printf("%d %d %d %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, a7, a8, a9);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (n == 10)
    {
        for (a1 = 1; a1 <= n; a1++)
        {
            for (a2 = 1; a2 <= n; a2++)
            {
                if (a2 == a1)
                    continue;
                for (a3 = 1; a3 <= n; a3++)
                {
                    if (a3 == a2 || a3 == a1)
                        continue;
                    for (a4 = 1; a4 <= n; a4++)
                    {
                        if (a4 == a3 || a4 == a2 || a4 == a1)
                            continue;
                        for (a5 = 1; a5 <= n; a5++)
                        {
                            if (a5 == a4 || a5 == a3 || a5 == a2 || a5 == a1)
                                continue;
                            for (a6 = 1; a6 <= n; a6++)
                            {
                                if (a6 == a5 || a6 == a4 || a6 == a3 || a6 == a2 || a6 == a1)
                                    continue;
                                for (a7 = 1; a7 <= n; a7++)
                                {
                                    if (a7 == a6 || a7 == a5 || a7 == a4 || a7 == a3 || a7 == a2 || a7 == a1)
                                        continue;
                                    for (a8 = 1; a8 <= n; a8++)
                                    {
                                        if (a8 == a7 || a8 == a6 || a8 == a5 || a8 == a4 || a8 == a3 || a8 == a2 || a8 == a1)
                                            continue;
                                        for (a9 = 1; a9 <= n; a9++)
                                        {
                                            if (a9 == a8 || a9 == a7 || a9 == a6 || a9 == a5 || a9 == a4 || a9 == a3 || a9 == a2 || a9 == a1)
                                                continue;
                                            for (a10 = 1; a10 <= n; a10++)
                                            {
                                                if (a10 == a9 || a10 == a8 || a10 == a7 || a10 == a6 || a10 == a5 || a10 == a4 || a10 == a3 || a10 == a2 || a10 == a1)
                                                    continue;
                                                printf("%d %d %d %d %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}


