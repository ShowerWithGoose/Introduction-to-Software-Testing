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
    return 0; // @@ [The function 'check' does not return a value in all control paths. If none of the conditions match, it falls through without returning, leading to undefined behavior.]
}
void print (char* str ,int i){
    char c=str[i-1]+1;
    for(;c<=str[i+1];c++){
        printf("%c",c);
    }
}

int main(){
    int i=1;
    gets(str); // @@ [Use of unsafe function 'gets' which is deprecated and removed in modern C standards due to buffer overflow risk. Also, may cause compilation error if compiler enforces secure functions.]
    printf("%c",str[0]);
    for(;i<strlen(str)-1;i++){
        if(str[i]=='-'){
            while(str[i]=='-'&&check(str,i)){
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