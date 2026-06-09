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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ The loop condition i < leng-2 causes the last two characters to be printed separately here, but when the last character is part of an expansion (e.g., 'F' after 'u' in "a-uB-F"), the expansion loop may have already consumed the '-' and the character after it, leaving the last character to be printed incorrectly. In the test case "a-uB-F", after processing "u-", i becomes 2 (pointing to 'B'), then the loop prints 'B' and 'F' separately, but the expansion of "B-F" should have been handled earlier. The issue is that the loop only goes to leng-2, so the last expansion "B-F" is not processed correctly; instead, 'B' is printed as part of the loop, and then 'F' is printed by this line, missing the expansion of 'C', 'D', 'E'.
}