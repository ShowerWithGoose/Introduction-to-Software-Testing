#include <stdio.h>
#include <string.h>

char s[2000];
int len,pos_d,pos_fi;

int get_d(char c[])
{
    for(int i=0;i<len;i++)
    {
        if(c[i]=='.') return i;
    }
    return len;
}

int get_fi(char c[])
{
    for(int i=0;i<len;i++)
    {
        if(c[i]=='0'||c[i]=='.') continue;
        return i;
    }
    return len;
}

void pr()
{
    printf("%c",s[pos_fi]);
    int i=len-1;
    while(i>pos_fi)
    {
        if(s[i]!='0'&&s[i]!='.') break;
        i--;
    }
    if(i!=pos_fi)
    {
        printf(".");
        for(int k=pos_fi+1;k<=i;k++) 
        {
            if(s[k]=='.') continue;
            printf("%c",s[k]);
        }
    }
    printf("e");
    int ind=pos_d-pos_fi;
    if(ind>0) ind--;
    printf("%d",ind);
    return ;
}

int main()
{
    scanf("%s",s);
    len=strlen(s);
    pos_d=get_d(s);
    pos_fi=get_fi(s);
    //printf("^^^ %d %d\n", pos_d ,pos_fi);

    pr();
    return 0;
}
