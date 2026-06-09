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
        if(i>99)outstack[j++]=-1;
        else{
        stack[i++]=item;}
    }
    else if(a==0){
        if(i==0)outstack[j++]=-1;
        else{
            outstack[j++]=stack[--i];
        }
    }
    scanf("%d ",&a); // @@ [The format string "%d " has a trailing space, which causes scanf to consume the next integer after the last input, leading to incorrect reading of the end-of-operations marker -1. Change to "%d" without the space.]
}
for(i=0;i<j;i++){
    if(outstack[i]==-1)printf("error ");
    else{
        printf("%d",outstack[i]); // @@ [Missing space after the integer output. The expected output requires a space after each popped element, but this prints the number without a trailing space. Add a space in the format string, e.g., "%d ".]
    }
}
return 0;
}