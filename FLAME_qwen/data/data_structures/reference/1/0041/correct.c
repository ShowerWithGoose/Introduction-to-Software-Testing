#include<stdio.h>

int a[10],book[10]={0};
int n;
int main(){
    scanf("%d",&n);
    cur(0);
    return 0;
}

void cur(int step) {
    int i=0;
    if(step==n){
        while(i<n){
            printf("%d",a[i]);
            printf(" ") ;
            i++;
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(book[i]==0){           
            a[step]=i+1;
            book[i]=1;             
            cur(step+1);
            book[i]=0;              
        }
    }
}




