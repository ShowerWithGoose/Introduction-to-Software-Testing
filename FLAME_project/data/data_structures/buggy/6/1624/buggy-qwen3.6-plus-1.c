#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t);
    k=strlen(t);
    for(i=0;i<k-2;i++) // @@ The loop condition `i<k-2` causes the last operation to be skipped or processed incorrectly, especially if the input ends with `-1`. It should likely iterate through the whole string or handle the termination condition explicitly.
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
                    while(t[l]!=' ')
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
                    while(t[l]!=' ')
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
                else if((s[j-1]+28)==0) // @@ This block contains hardcoded "magic number" checks for specific values (like -2, -8, etc.) which is logically incorrect. It fails to handle general negative numbers correctly (e.g., -45 results in -255 due to fall-through or incorrect logic). The standard `else` block below should handle all valid pops.
                {
                    printf("-2 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0) // @@ Same as above: incorrect hardcoded logic for specific negative numbers.
                {
                    printf("-8 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0) // @@ Same as above: incorrect hardcoded logic.
                {
                    printf("-23 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0) // @@ Same as above: incorrect hardcoded logic.
                {
                    printf("-56 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0) // @@ Same as above: incorrect hardcoded logic. This specific check seems intended for -45 but uses a wrong constant or logic, leading to the wrong output observed in the test case.
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