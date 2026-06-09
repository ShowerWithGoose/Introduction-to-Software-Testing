#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>

int main(){
int stack[100]={0},outstack[500];
int a,item,i=0,j=0;

scanf("%d",&a);
while(a!=-1){
    if(a==1){
        scanf("%d",&item);
        if(i>99)outstack[j++]=-1; // @@ The condition should be i >= 100 to check if the stack is full, because i is the next index to push to. When i == 100, the stack is already full (indices 0-99 are occupied), so pushing should cause an error.
        else{
        stack[i++]=item;}
    }
    else if(a==0){
        if(i==0)outstack[j++]=-1;
        else{
            outstack[j++]=stack[--i];
        }
    }
    scanf("%d ",&a); // @@ The format string has a trailing space, which may cause issues with input reading. It should be "%d" without the space.
}
for(i=0;i<j;i++){
    if(outstack[i]==-1)printf("error ");
    else{
        printf("%d",outstack[i]); // @@ Missing a space after the integer output. The problem requires a space after each element, including the last one. Should be printf("%d ", outstack[i]);
    }
}
return 0;
}