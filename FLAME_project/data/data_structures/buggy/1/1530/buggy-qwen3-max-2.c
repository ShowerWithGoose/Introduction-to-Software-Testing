#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>
#include<ctype.h>
#include<stdlib.h>
int s[11],x[11]={0},flag[11]={0};
void sort(int n,int k){
    if(k>n){
        for(int i=1;i<n;i++)
        printf("%d",x[i]); // @@ [Missing space after each number except the last one; should print "%d " to match expected output format]
        printf("%d\n",x[n]);
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(flag[i]!=1){
                flag[i]=1;
                x[k]=i;
                sort(n,k+1);
                flag[i]=0;
                x[k]=0;
            }
        }
        
    }
}
int main(void)
{
    int n;
    scanf("%d",&n);
    sort(n,1);
return 0;
}