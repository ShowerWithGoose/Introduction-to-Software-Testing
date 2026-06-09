#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc, char** argv)
{
    char c[5000];
    char ne[5000];
    char fu[5000];
    int a[5000];
    char m;
    int len,n,x,xx,wei,ans=0,chengshu=1;
    x=0;
    xx=0;
    gets(c);
    n=strlen(c);
    printf("%s\n",c); // @@ [The program outputs the input string, which is not required and causes "Wrong Answer" due to extra output]
    for(int i=0;i<n;i++)
    {
        if(c[i]==' '||c[i]=='=')
        {
            continue;
        }
        else
        {
            ne[x++]=c[i];
        }
    }
    x=0;
    for(int i=0;i<n;i++) // @@ [Loop bound should be based on the length of 'ne' (x), not 'n' (original string length), leading to out-of-bounds access or incorrect parsing]
    {
        if(isdigit(ne[i]))
        {
            a[x]=a[x]+ne[i]-'0';  
        }
        if(isdigit(ne[i+1])) // @@ [Accessing ne[i+1] without checking bounds can lead to undefined behavior; also logic for multi-digit number parsing is flawed as it doesn't reset accumulation correctly for new numbers]
        {
            a[x]*=10;
        }
        else
        {
            x++;
            fu[xx]=ne[i+1]; // @@ [ne[i+1] might be out of bounds or invalid (e.g., null terminator or end of string), storing garbage or wrong operator in fu]
            xx++;
        }
    }
    len=strlen(fu);
    for(int i=0;i<=strlen(fu);i++) // @@ [Loop goes up to strlen(fu) inclusive, accessing fu[strlen(fu)] which is the null terminator, causing logic errors in operator checks]
    {
        if(fu[i]=='*'||fu[i]=='/')
        {
            if(fu[i-1]=='-') // @@ [Accessing fu[i-1] when i=0 is out-of-bounds (undefined behavior)]
            {
                chengshu*=-1;
            }
            if((fu[i]=='*'||fu[i]=='/')&&(fu[i-1]=='+'||fu[i-1]=='-')) // @@ [Accessing fu[i-1] when i=0 is out-of-bounds; logic for initializing chengshu with a[i] is flawed because a[i] index doesn't align correctly with operator index i in all cases]
            {
            chengshu*=a[i];
            }
            if(fu[i]=='/')
            {
                chengshu/=a[i+1]; // @@ [a[i+1] index alignment is risky and depends on previous parsing correctness; division by zero possible if a[i+1] is 0 though problem says valid expression]
            }
            else
            {
                chengshu*=a[i+1];
            }
                
        }    
        if((fu[i-1]=='*'||fu[i-1]=='/')&&fu[i]!='*'&&fu[i]!='/') // @@ [Accessing fu[i-1] when i=0 is out-of-bounds; logic to add chengshu to ans is executed incorrectly due to loop structure and boundary conditions]
        {
            ans+=chengshu;
            chengshu=1;
        }
        
    }
    if(fu[0]!='*'&&fu[0]!='/')
    {
        ans+=a[0];

    }
    {
        for(int i=0;i<=len;i++) // @@ [Loop bound includes len, accessing fu[len] which is null terminator; logic for adding/subtracting remaining terms is flawed and double-counts or misses terms handled in previous loop]
        {
            if(fu[i]=='+'&&fu[i+1]!='*'&&fu[i+1]!='/')
            {
                ans+=a[i+1];
            }
            if(fu[i]=='-'&fu[i+1]!='*'&&fu[i+1]!='/') // @@ [Using bitwise AND '&' instead of logical AND '&&']
            {
                ans-=a[i+1];
            }

        }
    }
    printf("%d",ans);
    return 0;
}