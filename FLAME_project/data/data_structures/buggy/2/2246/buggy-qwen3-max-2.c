#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char s[1024]={'\0'},p[1024]={'\0'};
    gets(s);
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
    
    while(i<lo&&p[i+1]!='=') // @@ [The loop condition skips processing the last term before '=', leading to incorrect parsing when the expression ends with '='. Also, it assumes there's always an operator before '=', which may not hold during term extraction.]
    {
        long long sum1=p[i]-'0'; // @@ [This assumes the first character is always a digit, but if the expression starts with a negative number (not in this test case), it would fail. More critically, if the number has more than one digit, this initialization is correct only if followed by digits—but logic below has flaws.]
        while(p[i+1]>='0'&&p[i+1]<='9') // @@ [This loop processes multi-digit numbers correctly in some cases, but index management is flawed because 'i' is incremented here and later again, causing skips or misreads.]
        {
            sum1 = sum1*10 + p[i+1]-'0';
            i++;
        }
        
        while(p[i+1]=='*'||p[i+1]=='/') // @@ [This inner loop tries to handle * and / immediately after a number, but the indexing logic (especially using i+=2 and z) is incorrect—it doesn't properly isolate the next operand and confuses operator positions.]
        {
            int z=1; // @@ [Variable 'z' is used to track offset to find the operator, but it's misused: it counts digits instead of tracking operator position, leading to wrong operator lookup at p[i-z].]
            i+=2; // @@ [Jumping by 2 assumes operator is at i+1 and next digit at i+2, but if the next number has multiple digits or is single-digit, this causes misalignment.]
            long long sum2 = p[i]-'0'; // @@ [This reads the next number incorrectly because 'i' was advanced past the operator, but if the number has more than one digit, the following loop tries to extend sum1 (not sum2!), corrupting the value.]
            while(p[i+1]>='0'&&p[i+1]<='9')
            {
                z++; // @@ [Incrementing z here is meaningless for operator location; it should not affect operator lookup.]
                sum1 = sum1*10 + p[i+1]-'0'; // @@ [BUG: This appends digits to sum1 (the left operand) instead of sum2 (the right operand), completely breaking multiplication/division logic.]
                i++;
            }
            
            if(p[i-z]=='*') // @@ [Because z was incremented per digit and i was moved, p[i-z] does not reliably point to the operator; it often points to a digit or wrong location.]
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
        
        i+=2; // @@ [This advances i by 2 assuming next token is operator then digit, but after processing * or /, the position may already be at the end of a multi-digit number, causing skip of next operator or digit.]
    }
    
    printf("%lld",sum); // @@ [Due to cumulative parsing errors in handling multiplication/division and term boundaries, the final sum is wildly incorrect (2000011 vs expected 211).]
    return 0;
}