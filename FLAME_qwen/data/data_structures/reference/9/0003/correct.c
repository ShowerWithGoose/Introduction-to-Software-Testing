#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int a[BUFSIZ][6];
int N;
int i,j,k;
int max,now;
int maxp[2];

int main(){
    scanf("%d",&N);
    for (i = 0; i < N; i++)scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if(j==i) continue;
            else if (a[i][2]==a[j][0]&&a[i][3]==a[j][1]){
                a[i][4]=1;
                a[i][5]=j;
            }
        }
    }
    max = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i,now=1; a[j][4]==1&&j < N; j = a[j][5],now++);
        if (now > max)
        {
            max = now;
            maxp[0]=a[i][0];
            maxp[1]=a[i][1];
        }
    }
    printf("%d %d %d",max,maxp[0],maxp[1]);
}
