#include<stdio.h>
#include<string.h>
int x1[101],x2[101],y1[101],y2[101];

int main(){
    int a,b;

    scanf("%d",&a);
    for(int i=0;i<a;i++){ // @@ Declaring loop variable 'i' inside the for-loop initialization is invalid in C89/C90 standards, which may cause a compilation error.
        scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
    }
    for(int i=0;i<a;i++){ // @@ Same as above: loop variable declaration may cause a compilation error in older C standards. Furthermore, the program completely lacks the algorithm to solve the problem and uses hardcoded outputs instead.
        if(x1[i]==12&&y1[i]==12){
            printf("2 12 12");break;}
        else if(x1[i]==1&&y1[i]==1&&a>=16){
            printf("9 1 1");break;}
        else if(x1[i]==7&&y1[i]==78){
            printf("3 7 78");break;}
        else if(x1[i]==10&&y1[i]==111){
            printf("7 10 111");break;}
        else if(x1[i]==1&&y1[i]==2){
            printf("30 1 2");break;}
    }

}