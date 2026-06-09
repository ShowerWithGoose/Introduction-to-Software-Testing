#include <stdio.h>
#include <string.h>

int range(int a,int b){
    if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
        return 1;
    }
    else if(a>='a'&&a<='z'&&b>='a'&&b<='z'){
        return 1;
    }
    else if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char str[100];
    scanf("%s",str);
    int i;
    char j;
    for(i=0;i<=strlen(str)-2;i++){ // @@ Starting at i=0 causes out-of-bounds access to str[i-1]; loop condition strlen(str)-2 causes unsigned integer underflow for short strings and omits the last character from output.
        if(str[i]=='-'&&str[i-1]<str[i+1]&&range(str[i-1],str[i+1])==1){ // @@ Missing boundary checks i>0 and i<strlen(str)-1 leads to undefined behavior when accessing str[i-1] at i=0.
            for(j=str[i-1]+1;j<=str[i+1]-1;j++){
                printf("%c",j);
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
}