#include <stdio.h>
#include <stdlib.h>
int symbol[10] ,array[10] ;
int n;
void zidian(int index){
    int i;
    if(index>= n){ // @@ [The condition should be 'index == n' or 'index > n-1', but using 'index >= n' is acceptable; however, the real issue is in output formatting and indexing consistency. But the main error causing wrong answer is missing space between numbers in output.]
        for(i = 0; i < n; i++){
            printf("%d",array[i]); // @@ [Missing space after each number; should be "%d " to match expected output format which requires space-separated integers.]
        }
        printf("\n");
        return ;
    }
    for(i = 0;i < n; i++){
        if(symbol[i] == 0){
            array[index] = i+1;
            symbol[i] = 1;
            zidian(index+1);
            symbol[i] = 0;
        }
    }
}
int main(){
    int i;
    scanf("%d",&n);
    zidian(0);
    return 0;
}