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
            if(((str[i]>='0'&&str[i]<='9'&&str[i+2]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i]<='Z'&&str[i+2]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i]<='z'&&str[i+2]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [The original condition checks types incorrectly, e.g., str[i]>='0' && str[i+2]<='9' allows mixing digits and letters or invalid ranges. It must ensure both characters are of the SAME type (both digits, both upper, or both lower).]
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
    printf("%c%c",str[leng-2],str[leng-1]);

}