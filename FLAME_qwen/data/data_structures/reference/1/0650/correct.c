#include<stdio.h>
#include<string.h>
int a[10];
int n,i,j;
int flag[10];
void sort(int q);
int main(){
    scanf("%d",&n);
    sort(0);
    return 0;
}
void sort(int q) {
    int i;
    if(q==n){
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    else{
      for(i=0;i<n;i++){
          if(flag[i]==0){             
            a[q]=i+1;
            flag[i]=1;              
            sort(q+1);
            flag[i]=0;              
        }
      }
    }
}





