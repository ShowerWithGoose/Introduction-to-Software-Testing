#include<stdio.h>
#include<string.h>
char str[10086];
int main(){
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; however, the primary error here is logic-related, not compilation. But note: the actual compilation error in the test output suggests 'gcc not found', which is environment-related, not code-related. However, per problem context, we focus on logical/semantic errors causing wrong output. The real issue is in expansion logic and loop bounds.]
    int leng=strlen(str);
    for(int i=0;i<leng-2;i++){ // @@ [Loop condition 'i < leng - 2' skips processing when string length is less than 3, and also mishandles cases where '-' appears at the end or near the end. Additionally, it fails to handle single-character or two-character inputs properly.]
        if(str[i+1]!='-')
        printf("%c",str[i]);
        else{
            if(((str[i]>='0'&&str[i+2]<='9')||(str[i]>='A'&&str[i+2]<='Z')||(str[i]>='a'&&str[i+2]<='z'))&&str[i]<str[i+2]) // @@ [Condition is incorrect: it checks str[i] >= '0' but doesn't ensure str[i] <= '9' for digits; similarly for letters. Also, it doesn't verify that both characters are of the same category (e.g., '0' and 'z' could pass if str[i]='0' and str[i+2]='z' because '0'>='0' and 'z'<='z', which is wrong).]
            {
                int flag=str[i+2]-str[i];
                    for(int j=0;j<flag;j++){ // @@ [This prints from str[i] to str[i+2]-1 inclusive, but should print from str[i]+1 to str[i+2]-1. It incorrectly includes the starting character again.]
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
    printf("%c%c",str[leng-2],str[leng-1]); // @@ [This blindly prints last two characters regardless of whether they were already processed or if the string is shorter than 2 characters, leading to undefined behavior or duplication.]
}