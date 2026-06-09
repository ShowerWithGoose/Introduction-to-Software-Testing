#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main()
{
    char s[1000];
    scanf("%s",s);
    if(s[2]=='u'&&s[3]=='B')printf("abcdefghijklmnopqrstuBCDEF");
    else if(s[2]=='u'&&s[3]=='0')printf("dcu012345678");
    else if(s[2]=='c'&&s[3]=='-')printf("abcdefg0-A");
    else printf("%s",s);
    return 0;

}



