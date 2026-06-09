#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a1[BUFSIZ][2];
int a2[BUFSIZ][2];
int r[BUFSIZ][2];
int result[BUFSIZ][2];
int INdex,ratio;   // index 指数  ratio 系数
char c;
int i,j,k,o,n,N;

int cmp(const void *p1, const void *p2);

int main(){
    while (c != '\n'){
        scanf("%d %d%c",&INdex,&ratio,&c);
        a1[i][0] = INdex;
        a1[i++][1] = ratio;
    }
    c = ' ';
    while (c != '\n'){
        scanf("%d %d%c",&INdex,&ratio,&c);
        a2[j][0] = INdex;
        a2[j++][1] = ratio;
    }
    for (k = 0; k < i; k++)
    {
        for (o = 0; o < j; o++)
        {
            r[n][0]=a1[k][0] * a2[o][0];
            r[n++][1]=a1[k][1] + a2[o][1];
        }
    }
    qsort(r, n, (sizeof(int))*2,cmp);
    result[0][0]=r[0][0];
    result[0][1]=r[0][1];
    for (i = 1; i < n; i++)
    {
        if (r[i][1]==result[N][1]) result[N][0] += r[i][0];
        else{
            printf("%d %d ",result[N][0],result[N][1]);
            N++;
            result[N][0]=r[i][0];
            result[N][1]=r[i][1];
        }
    }
    printf("%d %d",result[N][0],result[N][1]);
    /*
    for (i = 1; i <= N; i++)
    {
        //printf("%d %d ",result[N][0],result[N][1]);
    }
    */
}

int cmp(const void *p1, const void *p2) {

 if(((int *)p1)[1] > ((int *)p2)[1])return -1;
 else if(((int *)p1)[1] < ((int *)p2)[1])return 1;
 else return 0;
}
