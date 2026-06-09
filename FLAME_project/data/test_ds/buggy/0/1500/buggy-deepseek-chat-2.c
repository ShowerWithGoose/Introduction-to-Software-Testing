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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ [Error: The condition incorrectly checks ch[i+1] <= 'z' instead of ch[i+1] <= 'z' && ch[i+1] >= 'a' for lowercase, and similarly for uppercase and digits. This allows expansion when the characters are not of the same type, e.g., 'a' and 'g' with '-' in between, but also incorrectly treats cases like '0' and 'A' as valid. Additionally, the logic for checking same type is flawed; it should require both characters to be in the same range, not just one side. The condition should be: (ch[i-1]>='a' && ch[i-1]<='z' && ch[i+1]>='a' && ch[i+1]<='z') || (ch[i-1]>='A' && ch[i-1]<='Z' && ch[i+1]>='A' && ch[i+1]<='Z') || (ch[i-1]>='0' && ch[i-1]<='9' && ch[i+1]>='0' && ch[i+1]<='9')]
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');}
        }

    }printf("%c",ch[len-1]);
    return 0;
}