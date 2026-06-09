#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [This assumes input ends with a newline; if not, it corrupts valid data. Also, if input is empty, strlen(s)-1 is negative, causing undefined behavior]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ [Assumes there's always at least one space and digit after '1'; fails if input format is invalid or at end of string]
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0'; // @@ [Doesn't handle multi-digit numbers correctly when '-' appears in middle; also accumulates digits even after space if loop condition fails]
                }
                else{
                    if(flag==1) num[++num_tt]=-res;
                    else num[++num_tt]=res;
                    i=j;
                    res=0;
                    break;
                }
            }
         }
         else if(s[i]=='0'){
            if(num_tt==0){
                printf("error ");
            }
            else{
            printf("%d ",num[num_tt]);
            num_tt--;
            }
            i++; // @@ [Incrementing `i` here skips the next character, which may cause misalignment in parsing, especially if multiple operations are adjacent without spaces]
         }
         else{
            break;
         }
    }
    return 0;
}