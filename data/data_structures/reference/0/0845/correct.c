#include <stdio.h>

int Type(char a){
    if(a >= '0' && a <= '9'){
        return 0;
    } else if(a >= 'a' && a <= 'z'){
        return 1;
    } else{
        return 2;
    }
}

void Expend(char string[]){
    for(int i = 0; string[i]; i++){
        if(string[i] == '-'){
            if(Type(string[i - 1]) == Type(string[i + 1])){
                for(char c = (char)(string[i - 1] + 1); c < string[i + 1]; c++){
                    printf("%c", c);
                }
            } else{
                printf("%c", string[i]);
            }
        } else{
            printf("%c", string[i]);
        }
    }
}

int main(){
    char string[1000000];

    scanf("%s", string);

    Expend(string);

    return 0;
}


