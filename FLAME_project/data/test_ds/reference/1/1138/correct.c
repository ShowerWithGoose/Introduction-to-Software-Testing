#include <stdio.h>
#include <string.h>
#include <ctype.h>

char ch[10000+7];

int main()
{
    gets(ch);
    int len=strlen(ch);
    for (int i=0; i<len; i++)
    {
        if(ch[i]!='-') printf("%c",ch[i]);
        else{
            if(islower(ch[i-1]) && islower(ch[i+1])) {for(int j=1;j<ch[i+1]-ch[i-1];j++) printf("%c",ch[i-1]+j);}
            else if(isupper(ch[i-1]) && isupper(ch[i+1])) {for(int j=1;j<ch[i+1]-ch[i-1];j++) printf("%c",ch[i-1]+j);}
            else if(isdigit(ch[i-1]) && isdigit(ch[i+1])) {for(int j=1;j<ch[i+1]-ch[i-1];j++) printf("%c",ch[i-1]+j);}
            else {printf("%c",ch[i]);}
        }
    }
    
    return 0;
}
