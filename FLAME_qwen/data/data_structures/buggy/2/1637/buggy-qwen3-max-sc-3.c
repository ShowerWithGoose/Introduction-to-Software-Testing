#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [a[0] is of type int, but %c expects a char*; also, storing char in int array without proper handling leads to type confusion]
    a[0]=a[0]-'0'; // @@ [if the first character is not a digit (e.g., '-'), this subtraction is invalid and causes incorrect value]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [a[k-1] is an int that may hold a numeric value, but comparing it directly to char literals like '+' is invalid because earlier digits were converted to integers, not stored as characters]
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
                a[k]=c; // @@ [storing operator character directly into int array a, but later logic treats some elements as numbers and others as chars, causing type confusion]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [a[i+1] might be a char code if it's an operator, or a number; but due to mixed storage, this multiplication may use garbage or wrong values]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [same issue: a[i+1] may not be a valid integer operand due to inconsistent storage in array a]
            i++;
        }
        else
        {
            b[j]=a[i];
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++) // @@ [loop condition should likely be i < j-1 since we access b[i+1]; accessing b[j] leads to out-of-bounds read]
    {
        if(b[i]=='+')
        {
            r+=b[i+1];
        }
        else if(b[i]=='-')
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