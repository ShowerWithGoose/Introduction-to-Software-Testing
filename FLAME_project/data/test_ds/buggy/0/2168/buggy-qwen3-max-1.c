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
    return 0; // @@ [The function does not return a value in all control paths. If none of the conditions match, it falls through without returning, leading to undefined behavior.]
}
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str); // @@ [Using gets() is unsafe and can cause buffer overflow. More importantly, it includes the newline character in some environments or may leave it in the buffer, but here the real issue is that the input may contain a trailing newline which becomes part of str, causing an extra null or garbage output. However, the main bug is elsewhere.]
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){ // @@ [The while loop is incorrect. It assumes multiple consecutive '-' should be processed together, but the problem only defines expansion for a single '-' between two valid characters. Also, after expanding, it skips two characters (i+=2), but then the for-loop increments i again, causing skipping of the next character. This leads to missing characters or incorrect processing. Moreover, if check returns false, it breaks out and prints the '-', which is correct, but the loop structure is flawed.]
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