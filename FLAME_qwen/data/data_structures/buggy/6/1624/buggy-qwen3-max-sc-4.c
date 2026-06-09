#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t); // @@ [Using `gets()` is unsafe and deprecated; may cause buffer overflow. Also, in many modern environments, `gets` is not available, leading to compilation error.]
    k=strlen(t);
    for(i=0;i<k-2;i++) // @@ [Loop condition `i<k-2` may skip the last operation if it's near the end of the string, especially if input ends without trailing space. This causes incomplete processing of operations.]
    {
        if(i==0)
        {
            if((t[i]=='1')&&(t[i+1]==' '))
            {
                if(j==100)
                {
                    printf("error ");
                }
                else
                {
                    l=i+2;
                    while(t[l]!=' ') // @@ [If the last number in input is not followed by a space (e.g., ends with newline or EOF), this loop runs past valid data, causing undefined behavior or incorrect parsing.]
                    {
                        s[j]=10*s[j]+t[l]-'0';
                        l=l+1;
                    }
                    j=j+1;
                }
            }
            else if((t[i]=='0')&&(t[i+1]==' '))
            {
                if(j==0)
                {
                    printf("error ");
                }
                else
                {
                    j=j-1;
                    printf("%d ",s[j]);
                    s[j]=0;
                }
            }
        }
        else
        {
            if((t[i]=='1')&&(t[i+1]==' ')&&(t[i-1]==' '))
            {
                if(j==100)
                {
                    printf("error ");
                }
                else
                {
                    l=i+2;
                    while(t[l]!=' ') // @@ [Same issue as above: assumes every number is followed by a space, which may not be true for the last token.]
                    {
                        s[j]=10*s[j]+t[l]-'0';
                        l=l+1;
                    }
                    j=j+1;
                }
            }
            else if((t[i]=='0')&&(t[i+1]==' ')&&(t[i-1]==' '))
            {
                if(j==0)
                {
                    printf("error ");
                }
                else if((s[j-1]+28)==0) // @@ [Hardcoded magic checks like `s[j-1]+28==0` imply `s[j-1] == -28`, but problem never specifies such special cases. These are arbitrary and incorrect; they falsely handle negative numbers based on fixed offsets.]
                {
                    printf("-2 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0) // @@ [Same as above: arbitrary handling of specific negative values not justified by problem statement.]
                {
                    printf("-8 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0) // @@ [Arbitrary and incorrect special-case handling for pop output.]
                {
                    printf("-23 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0) // @@ [Arbitrary and incorrect special-case handling for pop output.]
                {
                    printf("-56 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0) // @@ [Arbitrary and incorrect special-case handling for pop output.]
                {
                    printf("-45 ");
                    j=j-1;
                    s[j]=0;
                }                                                                                
                else 
                {
                    j=j-1;
                    printf("%d ",s[j]);
                    s[j]=0;
                }
            }
        }

    }
    
    
    
    
    
    
    return 0;
}