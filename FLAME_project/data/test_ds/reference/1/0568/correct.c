#include <stdio.h>
#include <stdlib.h>
int main ()
{char s[100];
char c;
int i,flag;
gets(s);
for(i=0;i<strlen(s);i++){flag=0;
    if(s[i]=='-'&&i>=1&&i<=strlen(s)-1){
        if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'){
           for(c=s[i-1]+1;c<s[i+1];c++){
            printf("%c",c);
            flag=1;
           }
        }

        if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'){
           for(c=s[i-1]+1;c<s[i+1];c++){
            printf("%c",c);
            flag=1;
           }
    }

        if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'){
           for(c=s[i-1]+1;c<s[i+1];c++){
            printf("%c",c);
            flag=1;
           }
    }
    if(flag==0){printf("-");}

    }
    else printf("%c",s[i]);}
return 0;}

