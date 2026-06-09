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
            }if(w==0){printf("%c",'-');} // @@ The variable w is not reset to 0 before checking the next '-' if the previous block was not entered or if logic flows incorrectly, but more importantly, the logic above is flawed. However, the primary error causing the specific failure "0-A" being expanded is the condition above. Also, w needs to be reset properly for each '-' check. In the current code, if the first if is false, w retains its previous value. If w was > 0 from a previous expansion, it won't print '-'. But here w is only set inside the if. If the if is skipped, w is unchanged. If w was 0 initially, it stays 0. If a previous expansion happened, w > 0. So if we have a valid expansion then an invalid one, the invalid one might not print '-'. We need to ensure w is reset for every iteration involving '-'.
        }

    }printf("%c",ch[len-1]);
    return 0;
}