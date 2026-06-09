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
    return 0; // @@ [The function lacks a default return statement, leading to undefined behavior when none of the conditions match. This can cause incorrect expansion decisions.]
}
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it includes the newline character in some environments or leaves it in the buffer, but here the real issue is that the input may contain a null terminator or extra characters causing output issues. However, the main bug is elsewhere.]
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){ // @@ [The while loop is incorrect: it assumes consecutive '-' should be processed together, but the problem only defines expansion for a single '-' between two valid characters. Also, after expanding, it skips two characters (i+=2), which may skip over non '-' characters or cause misalignment.]
                print(str,i);
                i+=2;
            }
        }
        printf("%c",str[i]);
    }
    if(i==strlen(str)-1){
        printf("%c",str[i]);
    }
    return 0;
}