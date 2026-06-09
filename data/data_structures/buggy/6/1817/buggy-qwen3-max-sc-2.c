#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [Assumes input ends with newline; if not, this corrupts last character. Also, if input is empty, strlen(s)-1 is -1 → undefined behavior]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ [Assumes space after '1', but input format doesn't guarantee two-character lookahead; may skip or misread digits]
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0'; // @@ [Doesn't handle negative numbers correctly: '-' is processed but digits after it are added as positive then negated later, but loop continues reading beyond '-' without skipping it properly]
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
            i++; // @@ [Incrementing 'i' here skips next character unnecessarily; loop already increments 'i', causing missed operations]
         }
         else{
            break;
         }
    }
    return 0;
}