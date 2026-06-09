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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [This line incorrectly prints the last two characters unconditionally, even if the last '-' was part of a valid expansion. For example, in "a-uB-F", after expanding "B-F" to "BCDEF", this line still prints "-F", causing duplication of 'F' and an extra '-'. Additionally, the loop condition stops at leng-2, so if the string ends with a valid expansion like "B-F", the final character 'F' is printed twice: once in the expansion loop and once here.]
}