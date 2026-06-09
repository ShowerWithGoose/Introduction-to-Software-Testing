#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2])
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){
                        printf("%c",str[i]+j);
                    }
                    i++;
            }
            else{
                printf("%c",str[i]);
                printf("-");
                i++;
            }
        }
    }
    printf("%c%c",str[leng-2],str[leng-1]); // @@ The loop condition i < leng-2 causes the last two characters to be printed separately, but when the last '-' is processed, the loop ends before handling the character after it correctly. For input "a-uB-F", after processing "a-u", i becomes 2, then the loop continues to process "B-F". When i=3 (pointing to 'B'), the else branch prints 'B' and '-', then i becomes 4, and the loop condition i < leng-2 (4 < 5) is true, so it prints 'F' as str[i] in the next iteration? Actually, the logic fails because after the else branch, i is incremented to 4, then the loop prints str[4] which is 'F', but then the final printf prints str[4] and str[5] again, causing duplication and missing the correct expansion of "B-F". The error is that the loop does not handle the expansion of the last '-' correctly, and the final printf adds extra characters.

}