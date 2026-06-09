#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,};
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ [Error: Missing space separator between integers. The output format requires each integer to be separated by a space.]
        }
        printf("\n");
    }
    else{
        int i=0;
        for(i=0;i<n;i++){
            if(rec[i]==0){
                rec[i]=1;
                save[begin]=base[i];
                permutation(n,begin+1,end,save);
                rec[i]=0;
            }
        }
    }
}
int main (){
    int save[100];
    int n;
    scanf("%d",&n);
    permutation(n,0,n,save);
    return 0;
}