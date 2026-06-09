#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define large 1000000007
#define small 1e-10
int used[11];
int ans[11];
int n;

void dfs(int i)
{
    if (i>n) {
        for (int j=1; j<n; j++)
            printf("%d ", ans[j]);
        printf("%d\n", ans[n]);
        return;
    } else {
        for (int j=1; j<=n; j++) {
            if (used[j]==0) {
                used[j] = 1;
                ans[i] = j;
                dfs(i+1);
                used[j] = 0;
            }
        }
    }
    
    
    
}

int main(int argc, const char * argv[])
{
    scanf("%d", &n);
    dfs(1);
    
    return 0;
}
























//int cmp(const void*a, const void*b)
//{
//    return *(int*)b-*(int*)a;
//} ACS[3NKN]NIKS[2[2DAD]]A

//
//int nearestIndex1(int key ,int L, int R){
//        int index = 0;
//        while(L<=R){
//            int mid=L+((R-L)>>1);
//            if(num(mid)){
//                index = mid;
//                L = mid+1;
//            } else {
//                R = mid-1;
//            }
//        }
//        return index;
//    }

//void scan(int* num)
//{
//    char ch;
//
//    ch = getchar();
//    while (!(('0' <= ch) && (ch <= '9')))
//        ch = getchar();
//    *num = 0;
//    while (('0' <= ch) && (ch <= '9'))
//    {
//        *num = (*num) * 10 + ch - '0';
//        ch = getchar();
//    }
//}



