#include<stdio.h>
#include<string.h>
int num[105];
int num_tt; // @@ [Error: Variable 'num_tt' is not initialized to 0. In C, global variables are zero-initialized, but relying on this without explicit initialization can be risky if moved to local scope. However, the main logic error is below.]
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [Error: This line incorrectly truncates the last character of the input string. If the input does not end with a newline or if it's the last token, this removes valid data (e.g., the '-1' terminator or the last digit). It should be removed or handled differently.]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){
            int flag=0;
            for(int j=i+2;j<LEN;j++){
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
            i++;
         }
         else{
            break;
         }
    }
    return 0;
}