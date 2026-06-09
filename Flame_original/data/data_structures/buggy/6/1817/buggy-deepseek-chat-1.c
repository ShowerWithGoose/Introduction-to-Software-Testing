#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [This line incorrectly removes the last character of the input string, which may be a valid part of the operation sequence (e.g., a digit or space), causing parsing errors.]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){ // @@ [This should be 'else if' to avoid double-checking the same character; as written, after printing "error", it will still attempt to parse the push operation, leading to incorrect behavior.]
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