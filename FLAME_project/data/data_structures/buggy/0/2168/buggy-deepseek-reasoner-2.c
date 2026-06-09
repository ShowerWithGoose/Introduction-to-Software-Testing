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
} // @@ Missing return statement; not all control paths return a value, leading to undefined behavior.
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
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){
                print(str,i);
                i+=2; // @@ Modifies loop variable i; after expansion, i points past the right character, causing the next printf to print str[i] which may be the null terminator.
            }
        }
        printf("%c",str[i]); // @@ Prints the character at the current i after possible modification; for the last dash, i becomes strlen, printing a null character.
    }
    if(i==strlen(str)-1){
        printf("%c",str[i]);
    }
    return 0;
}