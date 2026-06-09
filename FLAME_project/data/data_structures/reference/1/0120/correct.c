//
//  main.c
//  4
//
//  Created by  on 2021/9/22.
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
int b, min, max,tp;
int a[12];
int main()
{
    scanf("%d", &b);
    min = b, max = 0;
    for (int i = b; i > 0; i--)
        min += (b - i) * pow(10, i);
    for (int i = 0; i < b; i++)
        max += (i + 1) * pow(10, i);
    for (int i = min; i < max + 1; i++)
    {
        int t= i;
        for (int j = b - 1; j > -1; j--)
        {
            a[j] = t% 10;
            t/= 10;
        }
        for (int k = 0; k < b - 1; k++)
        {
            for (int m = k + 1; m < b; m++)
            {
                if (a[k] == a[m] || a[m] > b || a[k] > b || a[m] == 0)
                {
                    tp= 1;
                    break;
                }
            }
            if (tp== 1)
                break;
        }
        for (int count = 0; count < b; count++)
        {
            if (tp== 1)
                break;
            printf("%d ", a[count]);
        }
        if (tp== 0)
        {
            i += 8;
            printf("\n");
        }
        tp= 0;
    }
    return 0;
}
/*
 问题描述】输入整数N( 1 <= N <= 10 )，生成从1~N所有整数的全排列。
 【输入形式】输入整数N。
 【输出形式】输出有N!行，每行都是从1~N所有整数的一个全排列，各整数之间以空格分隔。各行上的全排列不重复。输出各行遵循“小数优先”原则, 在各全排列中，较小的数尽量靠前输出。如果将每行上的输出看成一个数字，则所有输出构成升序数列。具体格式见输出样例。
 */

