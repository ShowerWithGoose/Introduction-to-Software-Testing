#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t);
    k=strlen(t);
    for(i=0;i<k-2;i++)
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
                        s[j]=10*s[j]+t[l]-'0'; @@ // Error: For negative numbers, the minus sign is treated as a digit, leading to incorrect value. Should handle negative sign.
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
                        s[j]=10*s[j]+t[l]-'0'; @@ // Error: Same problem with negative numbers.
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
                else if((s[j-1]+28)==0)
                {
                    printf("-2 "); @@ // Error: Hardcoded mapping for -28? Incorrect; should print actual popped value.
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0)
                {
                    printf("-8 "); @@ // Error: Hardcoded mapping for -8? Incorrect.
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0)
                {
                    printf("-23 "); @@ // Error: Hardcoded mapping.
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0)
                {
                    printf("-56 "); @@ // Error: This branch incorrectly relies on the flawed parsing; should parse minus sign properly.
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0)
                {
                    printf("-45 "); @@ // Error: Condition never true because parsed value for -45 is -255. Should correctly parse negative numbers.
                    j=j-1;
                    s[j]=0;
                }                                                                                
                else 
                {
                    j=j-1;
                    printf("%d ",s[j]); @@ // For -45, this prints -255 because parsing is wrong.
                    s[j]=0;
                }
            }
        }

    }
    
    
    
    
    
    
    return 0;
}