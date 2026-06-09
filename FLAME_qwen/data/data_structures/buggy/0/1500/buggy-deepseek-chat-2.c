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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ Error: The condition only checks if both characters are within the same general range (e.g., both in a-z) but does not ensure they are of the same type (e.g., both lowercase, both uppercase, or both digits). For example, 'a' and 'z' are both lowercase, but 'A' and 'Z' are both uppercase; the condition should separately check each type. Additionally, it does not verify that ch[i-1] < ch[i+1] as required by the problem.
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} // @@ Error: This line is outside the else block, so it will always execute after the if block, even when expansion occurs. It should be inside an else clause to only print '-' when no expansion is performed.
        }

    }printf("%c",ch[len-1]);
    return 0;
}