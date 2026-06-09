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
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Error: The condition checks if str[i+2] is within the range, but does not verify that str[i] and str[i+2] are of the same type (e.g., both digits, both lowercase, or both uppercase). For example, '0' and '9' are both digits, but 'A' and 'Z' are both uppercase; however, the condition allows mixing types like '0' and 'Z' because it uses OR (||) across different ranges. Additionally, the condition should check that both characters are of the same type, not just that str[i+2] falls within a range. Also, the condition for digits should be str[i]>='0' && str[i]<='9' and str[i+2]>='0' && str[i+2]<='9', but here it incorrectly uses str[i+2]<='9' without checking str[i+2]>='0' for the digit case, and similarly for letters.]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [Error: This line prints the last two characters after the loop, but the loop only goes up to i < leng-2, so it may miss handling the case where the last character is part of an expansion or a dash. For example, if the string ends with a dash, this will incorrectly print the dash and the last character without processing. Also, if the string has an odd length or the last two characters are part of an expansion, this approach is flawed.]

}