#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
    int a[100],b[100],i=0,j=0,n,m,n1,flag=0;
   while(scanf("%d",&n)!=-1){ // @@ The loop should terminate when the input value is -1, not based on scanf's return value. It should check n != -1.
       a[i]=n;
       i++;
       n1=i;
   }
   for(i=0;i<=n1;i++){ // @@ The loop bound i<=n1 processes the terminator -1 stored in the array and may access out-of-bounds memory. It should be i < n1.
       if(a[i]==1){
           b[j]=a[i+1]; // @@ Fails to check if the stack is full (max capacity 100) before pushing, and uses j which is not correctly maintained as the stack pointer.
           j++;
           flag++;
       }
    if(a[i]==0){
        flag--; // @@ Decrementing flag before checking if the stack is empty corrupts the stack size state. The check should happen before decrementing.
        if(flag<0){
            printf("error ");
        }
        else{
            printf("%d ",b[flag+1]); // @@ Incorrect array index for the top element. After decrementing flag, the top element is at b[flag], not b[flag+1].
            j=flag+1; // @@ Incorrectly resets j, which breaks the push logic for subsequent operations as j should track the next available position.
        }
    }
   }
    return 0;
}