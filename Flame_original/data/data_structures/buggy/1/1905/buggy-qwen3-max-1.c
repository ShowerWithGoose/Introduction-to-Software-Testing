#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,}; // @@ [Trailing comma in array initializer is allowed in C99+, but the real issue is missing space between numbers and comma may cause confusion; however, the main error is elsewhere]
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ [Missing space between numbers in output; problem requires space-separated integers]
        }
        printf("\n");
    }
    else{
        int i=0;
        for(i=0;i<n;i++){ // @@ [This loop iterates over indices 0 to n-1, but uses global `rec` and `base`; however, the logic incorrectly allows reuse of numbers because it doesn't enforce ordering or proper backtracking relative to position]
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
    permutation(n,0,n,save); // @@ [Calling permutation with end = n, but base only has values 1..9 and for n=10, base[9] is uninitialized (since base has 9 elements due to trailing comma creating size 9 array), leading to undefined behavior; also, output not in lexicographical order due to iteration order over base indices rather than values]
    return 0;
}