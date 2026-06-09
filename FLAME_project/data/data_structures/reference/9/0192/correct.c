#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

int main(void)
{
    typedef struct zz{
        int z[10][10];
        int cnt;
        int flag;
    }zuobiao;
    int n,i,j;
    scanf("%d",&n);
    zuobiao a[n+2];
    for(int k=0;k<n;k++){
        a[k].cnt=1;
        a[k].flag=1;
        scanf("%d%d%d%d",&a[k].z[1][1],&a[k].z[1][2],&a[k].z[2][1],&a[k].z[2][2]);
        a[k].z[3][1]=a[k].z[2][1];a[k].z[3][2]=a[k].z[2][2];
    }
    for(i=0;i<n;i++){
        j=0;
        while(j<n&&a[i].flag)
        for(j=0;j<n;j++){
            if(a[j].z[1][1]==a[i].z[3][1]&&a[j].z[1][2]==a[i].z[3][2]){
                a[i].z[3][1]=a[j].z[2][1];a[i].z[3][2]=a[j].z[2][2];
                a[i].cnt++;
                a[j].flag=0;
                break;
            }
        }
    }
    int max=0,maxi=0,l;
    for(l=0;l<n;l++){
        if(a[l].cnt>max){
            max=a[l].cnt;
            maxi=l;
        }
    }
    printf("%d %d %d",max,a[maxi].z[1][1],a[maxi].z[1][2]);
    return 0;
}
