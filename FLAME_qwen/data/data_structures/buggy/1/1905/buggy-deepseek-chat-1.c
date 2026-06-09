#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,}; // @@ Error: Missing 10 in the array. The problem requires permutations of integers from 1 to N, where N can be up to 10, so the array should include 10.
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ Error: Missing spaces between numbers. The output should have each integer separated by a space.
        }
        printf("\n");
    }
    else{
        int i=0;
        for(i=0;i<n;i++){ // @@ Error: The loop should iterate over all numbers from 1 to n, but it uses the fixed base array which may not match n. Also, the condition should be i < n, but base array size is fixed and may not contain all numbers if n is less than 10.
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