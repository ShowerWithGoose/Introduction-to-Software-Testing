#include <stdio.h>
#include <string.h>
char str[10000];

int check (char * str,int i){
    if(str[i-1]>='0'&&str[i-1]<='9'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='9'){ // @@ missing lower bound check: should also check str[i+1]>='0'
                return 1;
            }
        }
    }
    if(str[i-1]>='a'&&str[i-1]<='z'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='z'){ // @@ missing lower bound check: should also check str[i+1]>='a'
                return 1;
            }
        }
    }
    if(str[i-1]>='A'&&str[i-1]<='Z'){
        if(str[i+1]<=str[i-1]){
            return 0;
        }
        else{
            if(str[i+1]<='Z'){ // @@ missing lower bound check: should also check str[i+1]>='A'
                return 1;
            }
        }
    }
} // @@ missing return statement for cases where none of the conditions match
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){ // @@ should be c<str[i+1] to avoid printing the right character (which will be printed later)
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str);
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){ // @@ while loop is unnecessary; causes index mishandling for multiple dashes
                print(str,i);
                i+=2; // @@ manual increment leads to skipping characters and double printing
            }
        }
        printf("%c",str[i]); // @@ prints character after expansion unconditionally; may reprint right character or dash
    }
    if(i==strlen(str)-1){
        printf("%c",str[i]);
    }
    return 0;
}