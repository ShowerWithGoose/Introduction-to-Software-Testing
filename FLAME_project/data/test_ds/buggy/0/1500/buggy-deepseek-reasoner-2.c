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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ [Error: w=0 is set inside the condition block, so for non‑expanding dashes w retains its previous non‑zero value, causing the dash to not be printed. Should be placed before the condition check.]
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){ // @@ [Error: The condition does not properly ensure both characters are of the same type (e.g., missing lower bounds for right side). This can cause incorrect expansions or failure to detect valid expansions.]
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');}
        }

    }printf("%c",ch[len-1]);
    return 0;
}