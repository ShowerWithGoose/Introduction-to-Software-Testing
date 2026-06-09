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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ [Error: Condition does not ensure both characters are in the same range and does not check ch[i-1] < ch[i+1]. Also, w=0 is only reset when this condition is true, not for every dash.]
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} // @@ [Error: This if statement should be an else clause of the expansion condition, or w should be reset at the start of processing each dash. As written, if a previous expansion set w>0 and the current dash does not meet the expansion condition, w is not reset, so the dash is not printed.]
        }

    }printf("%c",ch[len-1]);
    return 0;
}