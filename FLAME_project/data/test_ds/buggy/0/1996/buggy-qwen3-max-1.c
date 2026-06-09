#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
int main(){
    int i=0,m=0,j=0;
    char ch[10000]={0};
    char c=0;
    gets(ch); // @@ [Using 'gets' is unsafe and may cause buffer overflow; however, the main logic error is elsewhere.]
    m=strlen(ch);
    for(i=1;i<m;i++){
        if(ch[i]!='-'&&ch[i-1]!='-'){
        printf("%c",ch[i-1]);
        }
        else if(ch[i]=='-'){
            printf("%c",ch[i-1]);
            if(isupper(ch[i-1])&&isupper(ch[i+1])){
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(islower(ch[i-1])&&islower(ch[i+1])){
                for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'){
                    for(j=1;j<ch[i+1]-ch[i-1];j++){
                printf("%c",ch[i-1]+j);
                }
            }
            else if (ch[i] != '-') // @@ [This condition is always false because we are inside 'else if(ch[i]=='-')', so this block never executes. Instead, when expansion conditions fail, the '-' should be printed, but it isn't handled correctly.]
            printf("%c", ch[i]);
            }
            
    }
    printf("%c",ch[m-1]); // @@ [This prints the last character unconditionally, which causes duplication or omission in certain cases. For example, in "B-e", the 'e' is printed here, but the '-' was not printed earlier when expansion failed, leading to "Be" instead of "B-e". Also, if the string ends with '-', this may access beyond valid logic.]
    return 0;
}