#include<stdio.h>
int base[10]={1,2,3,4,5,6,7,8,9,}; // @@ Error: base array is missing the number 10, but N can be up to 10. Also, the trailing comma after 9 is syntactically allowed but the array should include 10 for N=10.
int rec[10];
void permutation(int n,int begin,int end,int *save){
    if(begin==end){
        int i=0;
        for(i=0;i<n;i++){
            printf("%d",save[i]); // @@ Error: Missing spaces between numbers in output. Should print a space before each number except the first.
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