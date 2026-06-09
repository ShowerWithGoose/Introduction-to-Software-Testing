#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int a[101];
int main(){
    int c,d=0,e=0,f=0;
    while(scanf("%d",&c)){ // @@ [The loop condition should check for !=EOF to properly detect end of input; current condition treats EOF as 0 (false), but also treats read failure the same as reading 0, which is incorrect.]
        if(c==1){
            if(d<=99){scanf("%d",&a[d]);d++;}
            else printf("error ");
        }
        else if(c==0){
            if(d>=0){printf("%d ",a[d]);d--;} // @@ [When d==0 (stack empty), this accesses a[0] and then decrements d to -1, causing invalid access and wrong behavior. Should check d>0 instead of d>=0.]
            else printf("error ");
        }
        else if(c==-1)break;
        getchar();
    }
    return 0;
}