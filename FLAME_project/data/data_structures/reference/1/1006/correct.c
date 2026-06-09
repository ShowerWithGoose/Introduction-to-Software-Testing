#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define LL long long
#define ULL unsigned long long

int i,j,n,jc[11],out[10];
void find(void);
void print(void);
int main(void)
{
    int i=0;
    jc[0]=1;
    for(i=1;i<10;i++){
        jc[i]=i*jc[i-1];
    }

    scanf("%d",&n);

    i=0;
    while(i<n){
        out[i]=i+1;
        i++;
    }

    print();

    i=1;
    while(i<jc[n]){
        find();
        print();
        i++;
    }

    return 0;
}

void find(void){
    int i,j;
    i=n-2;
    while(i>=0){
        if(out[i+1]>out[i]){
            break;
        }
        i--;
    }

    int m=i,p=i+1,q;
    for(i=m+1;i<n;i++){
        if(out[m]<out[i]&&out[p]>out[i]){
            p=i;
        }
    }

    q=out[m];
    out[m]=out[p];
    out[p]=q;

    j=m+1;
    i=n-1;
    while(i>j){
        q=out[i];
        out[i]=out[j];
        out[j]=q;
        i--;
        j++;
    }
}

void print(void){
    int i;
    for(i=0;i<n-1;i++)
        printf("%d ",out[i]);
    printf("%d\n",out[i]);
}
