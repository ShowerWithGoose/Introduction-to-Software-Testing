#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define large 1000000007
#define small 1e-10

char s[99999];
int check(int i)
{
    if (s[i]=='-' && isupper(s[i-1]) && isupper(s[i+1]) && s[i-1]<s[i+1]) {
        return 1;
    }
    if (s[i]=='-' && islower(s[i-1]) && islower(s[i+1]) && s[i-1]<s[i+1]) {
        return 1;
    }
    if (s[i]=='-' && isdigit(s[i-1]) && isdigit(s[i+1]) && s[i-1]<s[i+1]) {
        return 1;
    }
    return 0;
}

int main(int argc, const char * argv[])
{
    scanf("%s", s);
    int i = 1;
    char j;
    printf("%c", s[0]);
    while (s[i]!='\0') {
        if (check(i)) {
            for (j=s[i-1]+1; j<=s[i+1]-1; j++) {
                printf("%c", j);
            }
        } else
            printf("%c", s[i]);
        i++;
    }
    
    
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





