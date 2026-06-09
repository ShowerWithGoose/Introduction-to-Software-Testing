#include<stdio.h>
#include<string.h>
int main()
{
    char a[1005],a1[1005],a2[1005];
    gets(a);
    int b1[1005]={0},b2[1005]={0};
    int i,j,sum;
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
        {
            a[j++]=a[i];
        }
    }
    a[j]='\0';
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b1[j]=10*b1[j]+(a[i]-'0');
        }
        else
        {
            j++;
        }
    } // @@ [This loop incorrectly increments j after every non-digit, causing misalignment between operators and operands. For example, after reading '10', when '+' is encountered, j increments to 1, but then next digit starts at b1[1], which is correct. However, the final number after '=' will also cause an extra j++, leading to an unused zero at the end. More critically, the number parsing assumes that numbers are separated by exactly one non-digit, but doesn't account for the '=' properly.]
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            a1[j++]=a[i];
        }
    }
    a1[j]='\0';
    for(i=0,j=0;a[i]!='\0';i++)
    {
        if(a[i]=='+'||a[i]=='-')
        {
            a2[j++]=a[i];
        }
    }
    a2[j]='\0';
    for(i=0;a1[i]!='\0';i++)
    {
        if(a1[i]=='*')
        {
            b1[i+1]=b1[i]*b1[i+1];
            b1[i]=-10001;
        }
        else if(a1[i]=='/')
        {
            b1[i+1]=b1[i]/b1[i+1];
            b1[i]=-10001;
        }
    } // @@ [This loop processes * and / left-to-right but only handles one operation per operator. It fails to handle consecutive * and / correctly (e.g., 20*30/5). Also, it modifies b1 in place but doesn't shift indices, so later operations may use already-marked (-10001) values or skip operands.]
    for(i=0,j=0;i<(int)strlen(b1);i++) // @@ [strlen(b1) is invalid because b1 is an integer array, not a null-terminated char array. This leads to undefined behavior; it may read beyond valid data or stop too early.]
    {
        if(b1[i]!=-10001)
        {
            b2[j++]=b1[i];
        }
    }
    sum=b2[0];
    for(i=0;a2[i]!='\0';i++)
    {
        if(a2[i]=='+')
        {
            sum+=b2[i+1];
        }
        else if(a2[i]=='-')
        {
            sum-=b2[i+1];
        }
    } // @@ [The logic assumes that b2 has exactly one more element than a2, but due to earlier errors in parsing and filtering, b2 may have incorrect length or content. Also, if the expression starts with a negative number (not applicable here per problem), this would fail, but more importantly, the indexing b2[i+1] may go out of bounds if b2 is shorter than expected.]
    printf("%d",sum);
    return 0;
}