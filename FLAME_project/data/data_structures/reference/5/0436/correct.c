#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

struct an{
    int ax;
    int xn;
};

void print(struct an x[], int n);
void multi(struct an x1[], struct an x2[], struct an x[], int n1, int n2);

int main()
{
    struct an x1[10000], x2[10000], x[80000];
    int i=0,n1,n2;
    char c='0';
    while(1){
        scanf("%d%d%c", &x1[i].ax, &x1[i].xn, &c);
        i++;
        if(c == '\n')
            break;
    }
    n1 = i;
    i=0;c='0';
    while(1){
        scanf("%d%d%c", &x2[i].ax, &x2[i].xn, &c);
        i++;
        if(c == '\n')
            break;
    }
    n2 = i;
    //读入两个多项式
    multi(x1,x2,x,n1,n2);
	return 0;
}

void multi(struct an x1[], struct an x2[], struct an x[], int n1, int n2){
    int i=0,j=0,k=0;
    struct an p[5];
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            x[k].ax = x1[i].ax * x2[j].ax;
            x[k++].xn = x1[i].xn + x2[j].xn;
        }
    }//做乘法
    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            if(x[i].xn == x[j].xn){
                x[i].ax += x[j].ax;
                x[j].ax = 0;
            }
        }
    }//系数合并
    for(i=0;i<k;i++){
        for(j=i+1;j<k;j++){
            if(x[i].xn < x[j].xn){
                p[0] = x[i];
                x[i] = x[j];
                x[j] = p[0];

            }
        }
    }//倒序输出
    print(x,k);
}

void print(struct an x[], int n){
    int i;
    for(i=0;i<n;i++)
        if(x[i].ax!=0)
            printf("%d %d ", x[i].ax, x[i].xn);
}

