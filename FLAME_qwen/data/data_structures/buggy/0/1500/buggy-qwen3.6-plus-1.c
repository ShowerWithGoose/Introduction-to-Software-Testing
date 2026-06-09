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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ The condition fails to verify that both characters are of the same type (e.g., 'a' and 'Z' would incorrectly pass) nor does it check if ch[i-1] < ch[i+1]. It should check ranges for both ch[i-1] and ch[i+1] and ensure ch[i-1] < ch[i+1].
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} // @@ The variable w is not reset for each '-' encountered. If a previous '-' was expanded, w remains >0, causing subsequent '-' that should not be expanded to be skipped. w should be reset to 0 before processing each '-'.
        }

    }printf("%c",ch[len-1]);
    return 0;
}