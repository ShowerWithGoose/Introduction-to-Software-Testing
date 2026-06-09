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
        printf("%d\n",i); // @@ Debug output not required and produces extra line; also branch missing final printf for scientific notation
        for(j=0;i<=strlen(s);j++,i++){ // @@ No decimal point inserted in base; indices wrong (should start after placing first digit and '.'), no null terminator
            c[j]=s[i];
        }
    } // @@ Missing printf statement to output scientific notation for this branch; program ends without output
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