#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Incorrect range checks: should verify both ends are in same category, e.g., str[i]>='0' && str[i]<='9' && str[i+2]>='0' && str[i+2]<='9', not mixed bounds like str[i]>='0' && str[i+2]<='9']
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){
                        printf("%c",str[i]+j); // @@ [This prints the starting character again and misses the last character; should start from str[i]+1 and go up to str[i+2]-1, or print full inclusive range correctly per problem]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [If string length is less than 2, this accesses invalid indices; also fails to handle cases where loop doesn't cover last characters properly, especially when '-' is at end]
}