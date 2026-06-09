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
            { // @@ [The condition checks only the lower bound of the first char and upper bound of the second char, but does not ensure both chars are of the same type (e.g., 'a' and '9' would incorrectly pass). Also, it should check that both characters belong to the same category: both digits, both uppercase, or both lowercase.]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [This prints the last two characters unconditionally, which fails when the last '-' was part of a valid expansion (e.g., in "B-F", after expanding B-E, 'F' is printed again here, causing duplication or incorrect output). It also doesn't handle cases where the string ends with a '-' or has no trailing characters properly.]
}