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
    scanf("%d ",&a); // @@ The trailing space in scanf causes it to wait for non-whitespace after the integer, leading to incorrect input reading and potential hang. Should be "%d" without a space.
}
for(i=0;i<j;i++){
    if(outstack[i]==-1)printf("error ");
    else{
        printf("%d",outstack[i]); // @@ Missing space after number, should be "%d " to ensure spaces between outputs and a trailing space as per output format.
    }
}
return 0;
}