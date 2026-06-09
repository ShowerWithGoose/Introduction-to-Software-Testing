#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [This incorrectly truncates the last character of input even if it's not a newline; for example, if input ends with "-1", it becomes "-". This corrupts parsing.]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ [Assumes the number starts at i+2, but after '1', there may be only one space before the number (e.g., "1 5"), so should start at i+1 and skip spaces properly. Also fails to handle negative numbers correctly because it checks s[j]=='-' inside digit accumulation loop.]
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1; // @@ [This sets flag when '-' is encountered, but then still adds '-' as a digit via 's[j]-'0'', which yields negative ASCII offset, corrupting 'res'. Also, '-' may appear at start of number, but this logic runs for every non-space char.]
                    res=res*10+s[j]-'0'; // @@ [This line executes even when s[j] is '-', leading to res = res*10 + ('-' - '0') = res*10 - 5, which is wrong. Should only process digits.]
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