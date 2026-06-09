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
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Error: The condition checks if str[i+2] is within the range, but does not verify that str[i] is also within the same character type range. For example, 'a' >= '0' is true, so 'a-R' would incorrectly trigger expansion. Also, the condition should check both characters are of the same type (e.g., both digits, both lowercase, or both uppercase), not just that str[i+2] is in a range.]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [Error: This prints the last two characters regardless of whether they were part of an expansion. For example, if the string ends with "a-d", it will print 'd' twice (once from the loop's last iteration and once here). Also, the loop condition i < leng-2 skips processing the last two characters, so this line attempts to handle them but may produce incorrect output for cases like "a-d" where the last character is already printed by the expansion logic.]

}