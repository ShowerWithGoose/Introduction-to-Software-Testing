#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s);
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i); // @@ [Extra debug output not required; prevents correct output because no output after this for if branch]
        for(j=0;i<=strlen(s);j++,i++){ // @@ [Loop copies digits without inserting decimal point after first digit; also missing output after loop]
            c[j]=s[i]; // @@ [Copy statement does not handle decimal point insertion; base should have '.' after first digit if more digits follow]
        } // @@ [Missing printf for the scientific notation result; program should output base and exponent after constructing them]
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){
            c[i]=s[i];
        }
        printf("%se%d",c,n);
        return 0;
    }
}