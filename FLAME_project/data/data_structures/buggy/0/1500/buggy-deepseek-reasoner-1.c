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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ Error: `w` is only reset when this condition is true, but it should be reset at the start of handling each `-`. Additionally, the condition is incorrect: it checks left lower bound and right upper bound separately, but does not ensure both characters belong to the same character class (lowercase, uppercase, or digit) nor that left < right. For example, it treats `'g'` and `'0'` as valid expansion, which is wrong. The correct condition should check, e.g., `(ch[i-1]>='a' && ch[i-1]<='z' && ch[i+1]>='a' && ch[i+1]<='z')` and `ch[i-1] < ch[i+1]`.
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');}
        }

    }printf("%c",ch[len-1]);
    return 0;
}