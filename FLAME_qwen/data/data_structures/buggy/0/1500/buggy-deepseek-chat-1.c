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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ Error: The condition only checks if both characters are within the same broad range (e.g., both are letters or both are digits), but does not ensure they are of the same specific type (lowercase, uppercase, or digit). For example, 'a' and 'Z' would pass the first condition, but they are different types and should not be expanded. Also, it does not check that ch[i-1] < ch[i+1] as required.
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} // @@ Error: This should be an else if or else block, not a separate if. As written, if the expansion condition is true and w becomes non-zero, this if still executes because w==0 is false, so it's fine. But if the expansion condition is false, w remains 0, and this prints '-', which is correct. However, the logic is fragile; using else would be clearer and avoid potential issues if w is modified elsewhere.
        }

    }printf("%c",ch[len-1]);
    return 0;
}