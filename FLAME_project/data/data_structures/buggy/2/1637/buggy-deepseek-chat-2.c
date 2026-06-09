#include<stdio.h>

int main()
{
    int a[10000]={0},b[10000]={0};
    int k=1,j=0,i,r=0;
    char c;
    scanf("%c",&a[0]); // @@ [Error: a[0] is declared as int array, but scanf reads a character into it. This causes undefined behavior. Should read into a char variable or use proper conversion.]
    a[0]=a[0]-'0'; // @@ [Error: a[0] is an int, but subtracting '0' from a character value stored as int may not work correctly if the input is a digit character. Additionally, the initial input could be a space or operator, leading to incorrect values.]
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
                if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/') // @@ [Error: a[k-1] is an int, but comparing it with character constants like '+' assumes it stores the ASCII value of the operator. However, a[k-1] may contain a numeric value from previous digit processing, causing incorrect comparisons.]
                {
                    a[k-1]=a[k-1]*10+c-'0'; // @@ [Error: a[k-1] is an int, but this line mixes numeric values and character codes. If a[k-1] is an operator character (e.g., '+'), multiplying by 10 and adding digit value produces garbage.]
                }
                else
                {
                    a[k]=c-'0'; // @@ [Error: a[k] stores the numeric value of the digit, but later comparisons with operator characters (e.g., a[i]=='*') will fail because a[i] is an int, not a char.]
                    k++;
                }
            }
            else
            {
                a[k]=c; // @@ [Error: a[k] stores the character code of the operator (e.g., 43 for '+'), but later comparisons like a[i]=='*' compare int with char, which may work but is inconsistent with numeric storage of digits.]
                k++;
            }
        }
    }
    for(i=0;i<k;i++)
    {
        if(a[i]=='*') // @@ [Error: a[i] is an int, but comparing with character '*' assumes it stores the ASCII value. This is inconsistent because digits are stored as numeric values, not character codes.]
        {
            j--;
            b[j]=b[j]*a[i+1]; // @@ [Error: a[i+1] is a numeric value (from digit processing), but b[j] may contain an operator character code, leading to incorrect multiplication.]
            i++;
        }
        else if(a[i]=='/') // @@ [Error: Same issue as above; a[i] is int but compared with character '/'.]
        {
            j--;
            b[j]=b[j]/a[i+1]; // @@ [Error: Same issue as multiplication; mixing numeric and character values.]
            i++;
        }
        else
        {
            b[j]=a[i]; // @@ [Error: b[j] stores either a numeric digit value or an operator character code, causing confusion in later addition/subtraction steps.]
        }
        j++;
    }
    r=b[0];
    for(i=0;i<j;i++)
    {
        if(b[i]=='+') // @@ [Error: b[i] may contain numeric values or operator codes; comparing with '+' assumes it's a character code, but it could be a digit value.]
        {
            r+=b[i+1]; // @@ [Error: b[i+1] may be a numeric value or operator code, leading to incorrect arithmetic.]
        }
        else if(b[i]=='-') // @@ [Error: Same issue as above.]
        {
            r-=b[i+1]; // @@ [Error: Same issue as above.]
        }
        else
        {
            continue;
        }
    }
    printf("%d\n",r);
    return 0;
}