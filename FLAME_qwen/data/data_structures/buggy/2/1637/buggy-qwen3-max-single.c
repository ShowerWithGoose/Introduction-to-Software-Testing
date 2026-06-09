#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Error: 'a' is an int array, but scanf with %c reads a char into an int location; also, initial digit conversion assumes first char is digit, but doesn't handle operators or spaces properly]
    a[0]=a[0]-'0'; // @@ [Error: if the first character read was not a digit (e.g., space or operator), subtracting '0' leads to incorrect value; also, previous line stores char in int array incorrectly]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Error: comparing int array element (which may hold a number like 123) to char constants; this condition will always be true for multi-digit numbers, causing logic failure]
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
                a[k]=c; // @@ [Error: storing char operator directly into int array without distinguishing type; later logic treats all elements as either numbers or operators based on value, which is ambiguous]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*')
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [Error: assumes b[j] holds previous operand, but b is built in same loop; indexing and operand tracking is flawed because a[i+1] might not be a number (if stored as char code)]
            i++;
        }
        else if(a[i]=='/')
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [Error: same issue as above; also integer division is okay per spec, but operand retrieval is broken]
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ [Error: stores both numbers and operators (as their ASCII values) into b; later addition/subtraction loop cannot distinguish them reliably]
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
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