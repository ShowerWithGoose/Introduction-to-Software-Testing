#include <stdio.h>
#include<string.h>

int main() {
    char ch[100]={'0'};
    int len=0;
    int i=0,j=0,w=0;
    scanf("%s",ch);//scanf不存入换行符
    len=strlen(ch);
    printf("%c",ch[0]);
    for(i=1;i<len-1;i++){//到倒数第二位结束
        if(ch[i]!='-'){
            printf("%c",ch[i]);
        }
        if(ch[i]=='-'){
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ The condition incorrectly checks that the second character is less than or equal to 'z', 'Z', or '9', but does not ensure both characters are in the same range (e.g., 'a' to 'z' for lowercase). It also does not check that the character after '-' is greater than the one before, and the logic for checking same type is flawed (e.g., 'a' and 'z' are both lowercase, but the condition should be ch[i-1]>='a' && ch[i-1]<='z' && ch[i+1]>='a' && ch[i+1]<='z').
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');}
        }

    }printf("%c",ch[len-1]);
    return 0;
}