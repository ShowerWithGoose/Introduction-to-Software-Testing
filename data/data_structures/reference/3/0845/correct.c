#include <stdio.h>

int main(){
    char number[150];
    int counter;

    scanf("%s", number);

    if(number[0] == '0'){
        for(counter = 0; number[counter] == '0' || number[counter] == '.'; counter++);
        if(*(number + counter + 1)){
            printf("%c.%se-%d", *(number + counter), number + counter + 1, counter - 1);
        } else{
            printf("%se-%d", number + counter, counter - 1);
        }
    } else{
        for(counter = 0; number[counter] != '.'; counter++){
            printf("%c", number[counter]);
            if(!counter){
                printf(".");
            }
        }
        printf("%se%d", number + counter + 1, counter - 1);
    }


    return 0;
}
