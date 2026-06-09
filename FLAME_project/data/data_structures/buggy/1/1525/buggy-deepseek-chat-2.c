#include <stdio.h>

int MARK[11];
int permutation[11];

void full_permutation(int num,int NUM){
    //printf("Ooops\n");
    if (num == 0){
        for (int i=1; i<=NUM; i++) {
            printf("%d",permutation[i]); // @@ Error: Missing space between numbers. The expected output requires each integer to be separated by a space (e.g., "1 2"), but this prints them concatenated (e.g., "12").
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
    for (int i=0; i<num; i++) MARK[i] = 0; // @@ Error: The loop initializes MARK[0] to MARK[num-1] to 0, but the array is indexed from 1 to NUM in full_permutation. MARK[0] is unused, and MARK[num] (which is needed when i=num) is not initialized, leading to undefined behavior. Should initialize MARK[1] to MARK[num] instead.

    full_permutation(num,num);
    
    return 0;
}