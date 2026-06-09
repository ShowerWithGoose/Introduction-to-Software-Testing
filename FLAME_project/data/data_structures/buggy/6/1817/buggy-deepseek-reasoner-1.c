#include<stdio.h>
#include<string.h>
int num[105];
int num_tt; // @@ error: num_tt not initialized, leads to undefined behavior when used as stack pointer.
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ error: incorrectly removes last character, may truncate input (e.g., last digit of -1).
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){ // @@ error: push operation should be skipped when stack full; currently executes regardless.
            int flag=0;
            for(int j=i+2;j<LEN;j++){
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1;
                    res=res*10+s[j]-'0'; // @@ error: includes '-' character as digit, causing incorrect parsing of negative numbers.
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
            i++; // @@ error: outer loop already increments i, causing double increment and skipping characters (e.g., the space after '0').
         }
         else{
            break; // @@ error: breaks on first non-'1','0' character, including '-' from -1, causing premature termination.
         }
    }
    return 0;
}