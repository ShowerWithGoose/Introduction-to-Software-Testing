#include<stdio.h>
#include<string.h>
char s[1000];
int getnumber(int*);

int main()
{
    int ans=0,part=0,fac,j=0;
    gets(s);
    for(int i=0;i<strlen(s);i++)
        if(s[i]!=' ')s[j++]=s[i];
    s[j]='\0';
    j=0;
    int flag=0;
    char sym='\0',pm='\0';
    while(sym!='=')
    {
        part=getnumber(&j);
        fac=0;
        while (s[j]=='*'||s[j]=='/')
        {
            sym=s[j];
            j++;
            fac=getnumber(&j);
            switch (sym)
            {
            case '*':part*=fac;break;
            case '/':part/=fac;break;
            default:
                break;
            }
        }
        switch (pm)
        {
        case '+': ans+=part;break;
        case '-': ans-=part;break;
        case '\0':ans=part;break;
        default:
            break;
        }
        sym=s[j];
        pm=sym;
        j++;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;

}

int getnumber(int* n)
{
    int re;
    sscanf(s+*n,"%d",&re);
        int flag=0;
        while (0==flag)
        {
            if (s[*n]>='0'&&s[*n]<='9')
            {
                 flag=0;
                 (*n)++;
            }
            else
            flag=1;
        }
    return re;
}
