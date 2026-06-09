#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[1024]={'\0'},p[1024]={'\0'};
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers that do not support it.]
    int l=strlen(s);
    int i=0,j=0;
    for(i=0;i<l&&s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            p[j]=s[i];
            j++;
        }
    }
    p[j]='\0';
                    
    int lo=strlen(p),fig=1;
    long long sum=0;
    i=0;
    
    while(i<lo&&p[i+1]!='=') // @@ [This loop condition may skip the last number if the expression ends directly with '=' after a number, leading to incorrect parsing. Also, accessing p[i+1] when i == lo-1 leads to out-of-bounds read.]
    {
        long long sum1=p[i]-'0'; // @@ [Assumes p[i] is always a digit, but if the expression starts with '-', this will fail. Also, doesn't handle multi-digit numbers correctly in all contexts due to flawed parsing logic.]
        while(p[i+1]>='0'&&p[i+1]<='9')
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [Accesses p[i+1] without ensuring i+1 is within bounds; also, the inner logic for handling multiplication/division is flawed—it incorrectly calculates operand positions and reuses variables like 'z' in a way that breaks parsing.]
        {
            int z=1;
            i+=2;
            long long sum2 = p[i]-'0'; // @@ [Again assumes p[i] is a digit immediately after operator, which fails if number has more than one digit or if expression structure varies.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++;
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [This line mistakenly appends digits to sum1 instead of sum2, corrupting the left operand instead of building the right operand.]
                i++;
            }
            
            if(p[i-z]=='*') // @@ [Index i-z is unreliable due to incorrect tracking of operator position; this often points to wrong character or out-of-bound memory.]
            {
                sum1 = sum1*sum2;
            }
            else if(p[i-z]=='/')
            {
                sum1 = sum1/sum2;
            }
        }
        sum += sum1*fig;
        
        if(p[i+1]=='+')
        fig=1;
        else if(p[i+1]=='-')
        fig=-1;
        
        i+=2; // @@ [Blindly increments by 2 without verifying there are enough characters left, causing out-of-bounds access near end of string (especially before '=').]
    }
    
    printf("%lld",sum); // @@ [The problem requires output as integer (%d), but uses %lld for long long; though not a compilation error, it's inconsistent with spec. However, primary issue is logic errors above causing wrong result or crash.]
    return 0;
}