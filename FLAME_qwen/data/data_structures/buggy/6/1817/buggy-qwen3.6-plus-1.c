#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ Incorrectly truncates the last character of the input string, potentially removing valid data like the '1' in '-1' or the last digit of a number.
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error "); // @@ Prints error for a full stack but does not skip the subsequent push logic, leading to an invalid push operation.
         }
         if(s[i]=='1'){ // @@ Should be 'else if' to prevent executing the push block when the stack is full; also, matching '1' alone can incorrectly trigger on digits inside multi-digit numbers.
            int flag=0;
            for(int j=i+2;j<LEN;j++){
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0'; // @@ This line executes even when s[j] is '-', incorrectly adding the ASCII value of '-' to res instead of skipping the sign character.
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
            i++;
         }
         else{
            break;
         }
    }
    return 0;
}