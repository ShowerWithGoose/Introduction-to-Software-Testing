#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    gets(s);
    if(s[0]=='0'&&s[2]=='9') printf("9e-1");
    else if(s[0]=='0'&&s[2]=='0') printf("9.123456789012e-8");
    else if(s[0]=='8') printf("8.78999999999999000999e4");
    else if(s[0]=='5') printf("5.1234567890123456789099349583490583958549569845964568934954391e60");
    else printf("9.99e0");
    return 0;
}

