#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define large 1000000007
#define small 1e-10

char s[10000];
int num[1000];
int op[1000];
int i, j;
int num1, num2, num3, num4;
int main(int argc, const char * argv[])
{
    gets(s);
    int a = 0;
    int all = 1;

    while (s[i]!='=' ) {
        if (isdigit(s[i])) {
            a = a*10+s[i]-'0';
        } else if (s[i]=='*') {
            num[all] = a;
            op[all] = 1;
            all++;
            a = 0;
            num1++;
        } else if (s[i]=='/') {
            num[all] = a;
            op[all] = 2;
            all++;
            a = 0;
            num2++;
        } else if (s[i]=='+') {
            num[all] = a;
            op[all] = 3;
            all++;
            a = 0;
            num3++;
        } else if (s[i]=='-') {
            num[all] = a;
            op[all] = 4;
            all++;
            a = 0;
            num4++;
        }
        i++;
    }
    num[all] = a;
    all--;
    
    while (num1+num2>0) {
        for (i=1; i<=all; i++) {
            if (op[i]==1 || op[i]==2) {
                break;
            }
        }
        if (op[i]==1) {
            num[i] = num[i]*num[i+1];
            for (j=i; j<all; j++) {
                num[j+1] = num[j+2];
                op[j] = op[j+1];
            }
            all--;
            num1--;
        } else if (op[i]==2) {
            num[i] = num[i]/num[i+1];
            for (j=i; j<all; j++) {
                num[j+1] = num[j+2];
                op[j] = op[j+1];
            }
            all--;
            num2--;
        }
    }
    
    while (num3+num4>0) {
        if (op[1]==3) {
            num[1] = num[1]+num[2];
            for (j=1; j<all; j++) {
                num[j+1] = num[j+2];
                op[j] = op[j+1];
            }
            all--;
            num3--;
        } else if (op[1]==4) {
            num[1] = num[1]-num[2];
            for (j=1; j<all; j++) {
                num[j+1] = num[j+2];
                op[j] = op[j+1];
            }
            all--;
            num4--;
        }
    }


    printf("%d\n", num[1]);
    
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



