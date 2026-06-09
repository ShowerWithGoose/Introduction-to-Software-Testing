#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Error: a[0] is declared as int array, but scanf reads a character into it. This causes undefined behavior. Should read into a char variable or use proper conversion.]
    a[0]=a[0]-'0'; // @@ [Error: a[0] is an integer, subtracting '0' from an integer that was not properly read as a character digit leads to incorrect value.]
    while((c=getchar())!='=')
    {
        if(c==' ')
        {
            continue;
        }
        else
        {
            if(c>='0'&&c<='9')
            {
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Error: a[k-1] is an integer, but it is compared with character constants. This comparison is invalid because a[k-1] stores numeric values, not character codes. For example, if a[k-1] is 0, it will not equal '+' (43), causing logic errors.]
                {
                    a[k-1]=a[k-1]*10+c-'0';
                }
                else
                {
                    a[k]=c-'0';
                    k++;
                }
            }
            else
            {
                a[k]=c; // @@ [Error: a[k] is an integer, but it is assigned a character value. This mixes numeric and character data in the same array, causing incorrect comparisons later.]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ [Error: a[i] is an integer, but compared with character '*'. Since a[i] stores numeric values or character codes inconsistently, this comparison may fail.]
        {
            j--;
            b[j]=b[j]*a[i+1];
            i++;
        }
        else if(a[i]=='/') // @@ [Error: Same issue as above; a[i] is compared with character '/'.]
        {
            j--;
            b[j]=b[j]/a[i+1];
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ [Error: b[i] is an integer, but compared with character '+'. b[i] stores numeric values, not character codes, so this comparison is incorrect.]
        {
            r+=b[i+1];
        }
        else if(b[i]=='-') // @@ [Error: Same issue; b[i] compared with character '-'.]
        {
            r-=b[i+1];
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}