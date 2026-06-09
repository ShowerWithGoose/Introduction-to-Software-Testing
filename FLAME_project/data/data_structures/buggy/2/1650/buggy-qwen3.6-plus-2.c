#include <stdio.h>
#include <string.h>
char str[10000];
int a[10000];
char b[10000];
int c[100000];
char d[100000];
int main()
{
    int len,i,j,k,t,m,n,p,num=0,ans,sum=0;
    gets(str);
    len=strlen(str);
    for(i=0,j=0;i<len;)
    {
        if(str[i]!=' ')
        str[j++]=str[i++];    
        else
        i++;    
    }
    str[j]='\0';
    len=strlen(str);
    num=str[0]-'0';
    for(k=0,t=1;k<len;)
    {
        if(str[k+1]>='0'&&str[k+1]<='9')
        {
            num=num*10+str[k+1]-'0';
            k++;
        }
        else
        {
            a[t]=num;
            b[t]=str[k+1]; // @@ The operator is stored at index t, but the loop increments t immediately after. This means b[1] holds the first operator. However, the logic for handling * and / relies on a[m] and a[m+1]. If b[m] is *, it operates on a[m] and a[m+1]. But a[m] corresponds to the operand BEFORE b[m-1] if we look at standard infix mapping, or is it aligned? Let's trace: k=0, num=24. k becomes 1 (str[1] is '/'). a[1]=24, b[1]='/'. t becomes 2. Next iter: k=1. str[2]='4'. num=4. k becomes 2 (str[3] is '/'). a[2]=4, b[2]='/'. t becomes 3. So a[1]=24, b[1]='/', a[2]=4, b[2]='/', a[3]=3... The operators are in b[1..]. The operands are in a[1..]. b[m] is the operator between a[m] and a[m+1]? No. b[1] is between a[1] and a[2]. So b[m] operates on a[m] and a[m+1]. This alignment seems correct for the arrays.
            num=0;
            k++;
            t++;
        }
    }
    for(m=1,n=1;b[m]!='\0';)
    {
        if(b[m]=='+'||b[m]=='-'||b[m]=='=')
        {
            c[n]=a[m];
            d[n]=b[m];
            n++;
            m++;
        }
        else if(b[m]=='*')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]*a[m+1];
            else
            ans*=a[m+1]; // @@ 'ans' is used without being initialized in the current chain of multiplications/divisions if it's not the first one after a +/-. More critically, if we have a sequence like / * *, the logic for updating 'ans' and storing it back into a[m+1] is flawed. It calculates ans but doesn't correctly propagate the result to replace the left operand for the next step in a way that aligns with the subsequent addition/subtraction pass. Specifically, when b[m+1] is + or -, it sets a[m+1]=ans. But what about a[m]? The addition pass uses c[n]=a[m]. If we just update a[m+1], the previous a[m] remains unchanged in the array, but it's skipped in the addition pass because it was consumed? No, the addition pass iterates through d[p]. If d[p] is +, it adds c[p+1]. The value c[p] was set from a[m] when b[m] was + or -. If we collapse a * operation, we need to ensure the result replaces the left operand in the context of the final sum. The current code tries to do this by setting a[m+1]=ans. But the left operand a[m] is effectively lost or ignored in the final sum if it wasn't already added to 'sum'. Wait, the final loop sums c[1] then adds/subtracts c[p+1] based on d[p]. c[n] stores operands associated with + or -. If we have 24 / 4 * 2, b[1]='/', b[2]='*'. m=1. b[1] is /. ans = 24/4 = 6. b[2] is *. b[2+1] is '='? No. If b[2+1] is + or -, a[3]=ans. Here b[3] is '='. So a[3]=6. Then m increments. The loop continues. The problem is that 'ans' is not reset or managed correctly across different chains, and the storage back into 'a' is inconsistent with how 'c' and 'd' are populated for the final summation.
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='/')
        {
            if(b[m-1]=='+'||b[m-1]=='-')
            ans=a[m]/a[m+1];
            else
            ans/=a[m+1]; // @@ Same issue as above: 'ans' is uninitialized if this is the start of a new * / chain but the previous operator was not + or - (e.g. if logic fell through incorrectly). Also, integer division order matters.
            if(b[m+1]=='+'||b[m+1]=='-'||b[m+1]=='=')
            {
                a[m+1]=ans;
            }
            m++;
        }
        else if(b[m]=='=')
        {
            d[n]='=';
            break;
        }
    }
    sum=c[1];
    for(p=1;d[p]!='=';p++)
    {
        if(d[p]=='+')
        sum+=c[p+1];
        else if(d[p]=='-')
        sum-=c[p+1];    
    }
    printf("%d",sum);    
    return 0;
}