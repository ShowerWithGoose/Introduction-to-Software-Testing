#include<stdio.h>
#include<ctype.h>

char in[100000],ans[100000];
int can(char a,char b)
{
    if(a>=b) return 0;
    if(isdigit(a)&&isdigit(b)) return 1;
    if(islower(a)&&islower(b)) return 1;
    if(isupper(a)&&isupper(b)) return 1;
    return 0;
}
int main()
{
    scanf("%s",in);
    int i,j,k;
    int l=strlen(in);
    for(i=0,j=0;i<l;i++)
    {
        if(in[i]!='-') ans[j++]=in[i];
        else if(i>=1&&i<l-1&&can(in[i-1],in[i+1]))
        {
            for(int k=in[i-1]+1;k<in[i+1];k++)
                ans[j++]=k;
        }
        else ans[j++]=in[i];
    }
    ans[j]='\0';
    printf("%s",ans);
}


