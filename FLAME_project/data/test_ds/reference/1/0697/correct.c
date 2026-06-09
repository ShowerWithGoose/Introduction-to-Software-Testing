#include<stdio.h>
#include<string.h>

int typ(char x)
{
    if(x>='0'&&x<='9')return 1;
    if(x>='a'&&x<='z')return 2;
    if(x>='A'&&x<='Z')return 3;
}
void ex(char a,char b)
{
    if(typ(a)!=typ(b)){printf("-");return;}
    // printf("!!!!%c %c\n",a,b);
    if(b<=a){printf("-");return;}
    for(char x=a+1;x<b;x++)printf("%c",x);
}
char s[100010];

signed main()
{
    // freopen("data.in","r",stdin);

    scanf("%s",s+1);int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    if(s[i]=='-')ex(s[i-1],s[i+1]);
    else printf("%c",s[i]);
}


