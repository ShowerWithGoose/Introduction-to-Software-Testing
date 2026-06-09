#include <stdio.h>

int MARK[11];
int permutation[11];

void full_permutation(int num,int NUM){
    //printf("Ooops\n");
    if (num == 0){
        for (int i=1; i<=NUM; i++) {
            printf("%d",permutation[i]); // @@ The output format requires spaces between integers, but this line prints them consecutively without separators.
        }
        printf("\n");
        return;
    }
    for (int i=1; i<=NUM; i++){
        if (MARK[i] == 0){
            MARK[i] = 1;
            permutation[NUM - num + 1] = i;
            full_permutation(num-1,NUM);
            MARK[i] = 0;
        }
    }
}

int main()
{
    int num;
    scanf ("%d",&num);
    for (int i=0; i<num; i++) MARK[i] = 0;

    full_permutation(num,num);
    
    return 0;
}