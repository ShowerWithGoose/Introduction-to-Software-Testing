#include<stdio.h>
#include<string.h>
char s[1000];
char a[1000];
int b[1000];
int main()
{
    gets(s);
    printf("%s\n",s); @@ [This debug print should not be present as per problem output requirement; however, the main logic error is elsewhere. But more critically, using gets() is unsafe but not the cause of WA here.]
    int i,j=1,k=0;
    int sum=0;
    int len=strlen(s);
    a[0]='+'; @@ [This assumes the first number is positive, which is okay, but indexing of operators and numbers gets misaligned later.]
    for(i=0;i<=len-1;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
        {
            b[k]=sum;
            sum=0;
            k++;
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                a[j]=s[i];
                j++;
            }
        }
        if(s[i]>=48&&s[i]<=57)
        {
            sum=10*sum+(s[i]-'0');
        }
    }
    int len1=strlen(a); @@ [strlen(a) is unreliable because a is not null-terminated properly. The array a is filled with operators but no '\0' is added, so strlen may read garbage.]
    for(i=0;i<=len1-1;i++)
    {
        if(a[i]=='*')
        {
            a[i]=a[i-1]; @@ [Incorrectly overwrites current operator with previous one; also modifies b[i] and b[i-1] in a way that breaks operand alignment. Should process * and / immediately on operands without shifting operators like this.]
            b[i]=b[i]*b[i-1];
            b[i-1]=0;
        }
        if(a[i]=='/')
        {
            a[i]=a[i-1]; @@ [Same issue as above: wrong handling of division precedence and operand indices. Also, integer division direction is reversed: should be b[i-1]/b[i], but code does b[i-1]/b[i] correctly here, but assignment to b[i] and zeroing b[i-1] messes up later addition/subtraction.]
            b[i]=b[i-1]/b[i];
            b[i-1]=0;
        }
    }
    for(i=0;i<=len1-1;i++)
    {
        if(a[i]=='+')
        {
            sum+=b[i]; @@ [Because b[i-1] was zeroed during * / processing, and b[i] now holds the result of multiplication/division, but the indexing is off: the first number is at b[0], but a[0]='+', so when i=0, it adds b[0]. However, after * / processing, some b entries are zeroed incorrectly, and the association between operator a[i] and operand b[i] is broken.]
        }
        if(a[i]=='-')
        {
            sum-=b[i]; @@ [Same indexing issue as above.]
        }
    }
    printf("%d",sum);
    
    return 0;
}