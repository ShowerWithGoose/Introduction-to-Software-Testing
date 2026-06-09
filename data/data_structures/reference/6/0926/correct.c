#include <stdio.h>
#include <string.h>
#include <ctype.h>
int a[1000],i,j,num,d[1000];
char b[1000],c[1000];
int main() {
    for(i=0;;i++){
        scanf("%d",&a[i]);
        scanf("%c",&b[i]);
        if(b[i]=='\n')
            break;
    }
    num=i+1;
for(i=0,j=0;i<num;i++){
    if(a[i]==1){
        if(j<=100) {
            d[j] = a[i + 1];
            j++;
        }
        if(j>100){
            printf("error ");
        }
    }
    if(a[i]==0){
        if(j>0) {
            printf("%d ", d[j-1]);
            j = j - 1;
        }
        else{
            printf("error ");
        }
    }
}
    return 0;
}

