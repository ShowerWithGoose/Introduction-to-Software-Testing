#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [This line incorrectly removes the last character of the input string, which may be a valid digit or space, corrupting the input. The input does not necessarily end with a newline that needs trimming.]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){ // @@ [This should be an else if to avoid double-checking the same character; also, the push logic does not handle the case where the number after '1' is a multi-digit number correctly, and it fails to skip the space after '1' properly.]
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ [Starting from i+2 assumes there is always a space after '1', but the input may have no space (e.g., "12" meaning push 2). This will skip the actual digit.]
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0';
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
            i++; // @@ [This increments i unnecessarily, skipping the next character after '0', which may be a space or part of the next operation.]
         }
         else{
            break;
         }
    }
    return 0;
}