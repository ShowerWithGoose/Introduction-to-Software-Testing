#include<stdio.h>
#include<string.h>
int num[105];
int num_tt;
char s[10000];
int main(){
    int res=0,LEN=0;
    gets(s);
    LEN=strlen(s);
    s[strlen(s)-1]='\0'; // @@ [This line incorrectly assumes input ends with a newline and removes the last character unconditionally, which may corrupt the last number if input doesn't end with '\n'. However, the main logic errors are elsewhere.]
    for(int i=0;i<LEN;i++){
         if(s[i]=='1'&&num_tt==100){
            printf("error ");
         }
         if(s[i]=='1'){ // @@ [This condition is checked again even after handling full stack above; also, it processes '1' as a character, not as part of parsed integers, leading to misinterpretation of multi-digit numbers and negative signs.]
            int flag=0;
            for(int j=i+2;j<LEN;j++){ // @@ [Assumes the number starts at i+2 (skipping space after '1'), but doesn't validate that s[i+1] is a space; also fails to handle cases where the number has more than one digit correctly due to flawed parsing logic.]
                if(s[j]!=' ') {
                    if(s[j]=='-') flag=1; // @@ [This sets flag=1 when encountering '-', but continues to process subsequent digits as positive, then negates the whole result. However, '-' may appear in the middle of parsing if previous characters were digits, leading to incorrect sign handling. Also, it doesn't reset 'res' properly for negative numbers.]
                    res=res*10+s[j]-'0'; // @@ [This accumulates digits even when s[j] is '-', resulting in garbage values (e.g., '-' becomes 45-'0'= -3), corrupting 'res'.]
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