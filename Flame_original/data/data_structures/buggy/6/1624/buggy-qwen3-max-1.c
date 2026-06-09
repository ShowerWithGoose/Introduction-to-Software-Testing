#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with GCC removed or secured), this leads to compilation/runtime issues. Also, the problem expects parsing of space-separated integers, but this approach is overly complex and error-prone.]
    k=strlen(t);
    for(i=0;i<k-2;i++) // @@ [Loop condition `i<k-2` may skip the last operation(s), especially if the input ends without trailing spaces. This causes missed operations, leading to incorrect output.]
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
                    while(t[l]!=' ') // @@ [If the number is at the end of input and not followed by a space (e.g., before -1), this loop runs past valid data, causing undefined behavior or incorrect parsing.]
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
                    while(t[l]!=' ') // @@ [Same issue as above: assumes every number is followed by a space, which fails for the last token before -1 or end of string.]
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
                else if((s[j-1]+28)==0) // @@ [Hardcoded magic numbers like 28, 22, etc., are used to detect negative numbers (e.g., -28+28=0). This is completely incorrect logic—these checks only match specific negative values and fail for all others. The program should handle any integer, not just these five hardcoded negatives.]
                {
                    printf("-2 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0)
                {
                    printf("-8 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0)
                {
                    printf("-23 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0)
                {
                    printf("-56 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0)
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