#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s); // @@ gets is removed in the C11 standard and causes compilation errors in modern compilers; it is also unsafe for buffer overflows.
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ Unconditionally removes the last character of the input string, which may corrupt valid data (e.g., removing '1' from '-1'), and causes out-of-bounds access if the string is empty.
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error "); // @@ Missing a 'continue' or 'else' statement, causing the program to proceed with parsing and pushing the number even after detecting a full stack.
         }
         if(s[i]=='1'){
            int flag=0;
            for(int j=i+2;j<LEN;j++){
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0'; // @@ Executes even when s[j] is '-', incorrectly updating 'res' with the ASCII value of '-'; it should only process digit characters.
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
            i++; // @@ Incorrectly increments the loop counter, causing the parser to skip the next character (typically a space or the start of the next number).
         }
         else{
            break;
         }
    }
    return 0;
}