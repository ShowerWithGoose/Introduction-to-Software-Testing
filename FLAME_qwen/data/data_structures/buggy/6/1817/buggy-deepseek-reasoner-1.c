#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ Error: Removes last character of input, likely the '1' from the terminating "-1", so the program will never see the complete "-1" token.
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){ // @@ Error: This condition incorrectly treats any '1' digit as a push operation. For example, the digit '1' inside the number "15" will trigger this check. Also, after printing error, it still proceeds to push.
            printf("error ");
         }
         if(s[i]=='1'){ // @@ Error: Same issue as above; this condition matches any '1' character, not just the push operation token. It should only treat '1' as a push when it appears as a standalone token.
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ Error: Assumes there is exactly one space after the '1'. If the '1' is part of a multi-digit number (e.g., "15"), there is no space and j goes out of bounds.
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1; // @@ Error: The '-' character is included in building res on the next line, causing res to be corrupted (e.g., '-' ASCII 45 minus '0' 48 gives -3, which is added to res).
                    res=res*10+s[j]-'0'; // @@ Error: This line processes all characters, including the '-' sign, leading to an incorrect numeric value.
                }
                else{
                    if(flag==1) num[++num_tt]=-res; // @@ Error: Because res was corrupted by including the '-' character, the pushed value is wrong.
                    else num[++num_tt]=res;
                    i=j;
                    res=0;
                    break;
                }
            }
         }
         else if(s[i]=='0'){ // @@ Error: This condition matches any '0' character, including those inside numbers like 10, incorrectly treating them as pop operations.
            if(num_tt==0){
                printf("error ");
            }
            else{
            printf("%d ",num[num_tt]);
            num_tt--;
            }
            i++; // @@ Error: Extra increment causes i to skip two characters (one here and one in the loop increment), leading to misaligned parsing.
         }
         else{
            break; // @@ Error: This break triggers on any character that is not '1' or '0', including the '-' of "-1" and also any '-' from negative numbers like -5, causing premature termination.
         }
    }
    return 0;
}