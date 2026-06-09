#include <stdio.h>
#include <string.h>
char str[10000];

int check (char * str,int i){
    if(str[i-1]>='0'&&str[i-1]<='9'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='9'){
                return 1;
            }
        }
    }
    if(str[i-1]>='a'&&str[i-1]<='z'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='z'){
                return 1;
            }
        }
    }
    if(str[i-1]>='A'&&str[i-1]<='Z'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='Z'){
                return 1;
            }
        }
    }
} // @@ Missing return 0; at the end of the function, leading to undefined behavior when character types mismatch or conditions are not met.
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str);
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){ // @@ Loop condition i<strlen(str)-1 skips processing the last character; should be i<strlen(str).
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){ // @@ Using while is incorrect as it modifies i and may cause infinite loops or out-of-bounds access; should be if.
                print(str,i);
                i+=2; // @@ Modifying loop variable i inside the loop combined with for-loop increment causes incorrect traversal and potential out-of-bounds access.
            }
        }
        printf("%c",str[i]); // @@ Unconditionally printing str[i] after potential index modification prints wrong characters; should be in an else branch.
    }
    if(i==strlen(str)-1){ // @@ This condition is flawed due to incorrect loop logic and index handling above.
        printf("%c",str[i]);
    }
    return 0;
}