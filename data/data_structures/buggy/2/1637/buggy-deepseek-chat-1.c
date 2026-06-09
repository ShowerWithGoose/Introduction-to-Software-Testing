#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ Error: a[0] is declared as int array, but scanf with %c reads a character; also a[0] is used to store an integer value but the first character might be a digit or operator; this approach is flawed.
    a[0]=a[0]-'0'; // @@ Error: If the first character is not a digit (e.g., a space or operator), subtracting '0' produces incorrect value; also a[0] was read as character but stored in int array, causing type mismatch.
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ Error: a[k-1] is an integer, but it is compared with character constants; this comparison is incorrect because a[k-1] stores numeric values (e.g., 5) not character codes.
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
                a[k]=c; // @@ Error: a[k] is an int array, but c is a character; storing a character (e.g., '+') as an integer loses the operator information and mixes types.
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ Error: a[i] stores integers (numbers or character codes), but '*' is a character constant; this comparison is unreliable because a[i] may contain numeric values that accidentally match.
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ Error: b[j] is uninitialized (0) and a[i+1] is an integer; multiplication with 0 gives 0, losing the actual operand.
            i++;
        }
        else if(a[i]=='/') // @@ Error: Same issue as above; comparison with character constant is incorrect.
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ Error: Division by zero if a[i+1] is 0, and b[j] is 0, leading to undefined behavior.
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ Error: a[i] may be a character code (e.g., 43 for '+') stored as integer, which is not the intended numeric operand.
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ Error: b[i] stores integers, but '+' is a character constant; this comparison will never be true because b[i] contains numeric values, not character codes.
        {
            r+=b[i+1];
        }
        else if(b[i]=='-') // @@ Error: Same issue; comparison with character constant is incorrect.
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