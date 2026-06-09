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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; // @@ The condition checks if characters are within the broad ranges but fails to verify they are of the *same* type (e.g., allows 'a' and 'Z' or '0' and 'b'). It also fails to check if the start character is strictly less than the end character.
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} // @@ The variable w is not reset to 0 at the beginning of each '-' processing block, so if a previous expansion set w > 0, this condition might fail incorrectly for subsequent non-expanding hyphens. Additionally, logic for same-type check is missing above.
        }

    }printf("%c",ch[len-1]);
    return 0;
}