#include<stdio.h>
 #include<string.h>
 #include<math.h>
 #include<stdlib.h>
 #include<ctype.h>

 int main(){
    int i,ele;
    int a[105];
    int sum=0;
    while(1){
        scanf("%d",&i);
        if(i==-1){
            break;
        }
        else if(i==1){
            scanf("%d",&ele);
            if(sum==100){
                printf("error ");
            }
            else{
                a[sum]=ele;
                sum++;
            }
        }
        else{
            if(sum==0){
                printf("error ");
            }
            else{
                printf("%d ",a[sum-1]);
                sum--;
                if(sum<0){
                    sum=0;
                }
            }
        }
    }
    return 0;
 }
