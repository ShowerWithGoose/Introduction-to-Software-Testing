#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,}; // @@ [Trailing comma in array initializer is allowed in C99+, but the real issue is missing space formatting; however, the actual critical error is elsewhere]
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ [Missing space between numbers as required by output format; should print space-separated values]
        }
        printf("\n");
    }
    else{
        int i=0;
        for(i=0;i<n;i++){ // @@ [This loop iterates over indices 0 to n-1, but uses 'rec' and 'base' globally; however, the main logic flaw is that it doesn't enforce lexicographical order because it iterates base[0..n-1] which is fixed, but since base is {1..9}, it actually does produce lex order. So this may not be the error.]
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