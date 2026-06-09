#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
struct x{
    int a[2];
    int b[2];
}x[101],temp; // @@ Using 'x' as both the struct tag and the array name can cause compilation errors or warnings in strict compiler modes due to identifier shadowing/conflict.
int main(){
    int n,flag=0,l=1,max=0,c,d,k,i=0,j; // @@ Variable 'j' is declared but not initialized. If n=1, the inner loop never executes, leaving 'j' with an indeterminate value, which causes undefined behavior when used later.
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&x[i].a[0],&x[i].a[1],&x[i].b[0],&x[i].b[1]);
    }        
    for(i=0;i<n;i++){        
    flag=0;
    for(j=i+1;j<n;j++){
        if(x[j].a[0]<x[i].a[0]){
            temp=x[j];
            x[j]=x[i];
            x[i]=temp;
            flag=1;
            }        
        }
        if(flag==0)break;
    }
    for(i=0;i<n;i++){
        l=1;
        k=i;
        for(j=i+1;j<n;j++){
            if(x[j].a[0]==x[k].b[0]&&x[j].a[1]==x[k].b[1]){
                l++;
                k=j;
            }else break;
        }
        if(l>max){
            max=l;
            c=x[i].a[0];
            d=x[i].a[1];
        }
        i=j-1; // @@ Modifying the loop control variable 'i' inside the loop body is error-prone and relies on 'j' being properly initialized. It can lead to incorrect iteration counts or out-of-bounds access.
    }
printf("%d %d %d",max,c,d);
return 0;
}