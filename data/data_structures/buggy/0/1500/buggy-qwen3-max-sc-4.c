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
            if((ch[i-1]>='a'&&ch[i+1]<='z')||(ch[i-1]>='A'&&ch[i+1]<='Z')||(ch[i-1]>='0'&&ch[i+1]<='9')){w=0; @@ [The condition incorrectly checks only one side of the range (e.g., 'a' <= left but right <= 'z'), which allows mixed-type cases like 'a-Z' to pass. It should ensure both characters are in the same category and that the left < right.]
                for(j=ch[i-1]+1;j<=ch[i+1]-1;j++){
                    printf("%c",j);
                    w++;
                }
            }if(w==0){printf("%c",'-');} @@ [Variable 'w' is only reset inside the if-block; if the condition fails, 'w' retains its previous value from earlier iterations, causing incorrect '-' output or omission. Also, this logic doesn't handle non-expansion cases correctly when '-' appears but shouldn't expand.]
        }

    }printf("%c",ch[len-1]);
    return 0;
}