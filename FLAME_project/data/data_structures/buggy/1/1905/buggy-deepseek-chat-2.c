#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,};
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ Missing space between numbers; should be "%d " to match expected output format
        }
        printf("\n");
    }
    else{
        int i=0;
        for(i=0;i<n;i++){ // @@ The loop should iterate over all numbers from 1 to n, but base array is fixed size 10 and rec array is not reset for each call; also the logic uses base[i] which assumes base contains 1..n, but base is hardcoded for 10 elements, causing issues when n < 10
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