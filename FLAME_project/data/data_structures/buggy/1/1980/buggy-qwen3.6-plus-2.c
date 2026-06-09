#include <stdio.h>
#include <stdlib.h>
int symbol[10] ,array[10] ;
int n;
void zidian(int index){
    int i;
    if(index>= n){ // @@ The condition should be index == n to correctly identify when a full permutation of length n is formed. Using >= might work logically here but combined with the loop logic, it's safer to be precise. However, the main error is in the output format below.
        for(i = 0; i < n; i++){
            printf("%d",array[i]); // @@ The output format requires integers to be separated by a space. This line prints numbers without spaces (e.g., "12" instead of "1 2"). It should be printf("%d ", array[i]); or similar handling for the last element.
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