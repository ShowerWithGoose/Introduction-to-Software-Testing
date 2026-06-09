#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define large 1000000007
#define small 1e-10

char s[10000];
int i, j;
int location, length;

int main(int argc, const char * argv[])
{
    scanf("%s", s);
    length = strlen(s);
    int have_point = 0;
    // 判断有没有小数点
    for (i=0; s[i]!='\0'; i++) {
        if (s[i]=='.') {
            have_point = 1;
            location = i;
            break;
        }
    }
    
    // 没有小数点
    if (have_point == 0) {
        printf("%c", s[0]);
        if (length>1) {
            // 找一下最后一位非零的数
            int last_location = length-1;
            while (s[last_location]=='0') {
                last_location--;
            }
            if (last_location>0)
                printf(".");
            for (i=1; i<=last_location; i++) {
                printf("%c", s[i]);
            }
        }
        printf("e%d\n", length-1);
        return 0;
    }
    
    // 小数点不移动
    if (s[1]=='.' && s[0]!='0') {
        printf("%se0", s);
        return 0;
    }
    
    
    // 小数点左移动
    if (location>1) {
        printf("%c.", s[0]);
        for (i=1; s[i]!='\0'; i++) {
            if (s[i]!='.') {
                printf("%c", s[i]);
            }
        }
        printf("e%d", location-1);
        return 0;
    }
    
    // 小数点右移动
    i = location+1;
    while (s[i]=='0') {
        i++;
    }
    printf("%c", s[i]);
    i++;
    // 只有一个数字
    if (s[i]=='\0') {
        printf("e-%d", i-location-1);
    } else {
        printf(".");
        int k = i-location-1;
        while (s[i]!='\0') {
            printf("%c", s[i]);
            i++;
        }
        printf("e-%d", k);
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



