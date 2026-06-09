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
    return 0; // @@ [The function 'check' does not return a value in all control paths. If none of the conditions match, the function falls through without returning anything, leading to undefined behavior.]
}
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11. Its use can lead to buffer overflow vulnerabilities. Additionally, some compilers may not support it, which could contribute to compilation issues depending on compiler settings.]
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){ // @@ [The loop condition uses 'while' which is incorrect. It should be an 'if' because each '-' should be processed only once. Using 'while' here may cause skipping characters or infinite loops when multiple consecutive '-' are present and valid. Also, after expanding, 'i' is incremented by 2 inside the loop, but the for-loop also increments 'i', leading to skipped characters.]
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