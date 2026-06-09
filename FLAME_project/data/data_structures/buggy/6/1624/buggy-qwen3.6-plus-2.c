#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t);
    k=strlen(t);
    for(i=0;i<k-2;i++) // @@ The loop condition `i<k-2` causes the last operation (specifically `-1`) to be skipped or processed incorrectly, and it fails to handle operations at the very end of the string properly. It should likely iterate through the whole string or use a different parsing logic.
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
                else if((s[j-1]+28)==0) // @@ This block contains hardcoded "magic number" checks that attempt to fix specific negative numbers incorrectly parsed or stored, indicating a fundamental flaw in how negative numbers are parsed. The parser above only handles positive digits.
                {
                    printf("-2 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0) // @@ Hardcoded check for -8, symptomatic of the failure to parse negative signs during the push operation.
                {
                    printf("-8 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0) // @@ Hardcoded check for -23, symptomatic of the failure to parse negative signs during the push operation.
                {
                    printf("-23 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0) // @@ Hardcoded check for -56, symptomatic of the failure to parse negative signs during the push operation.
                {
                    printf("-56 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0) // @@ Hardcoded check for -45. The value 244255 suggests integer overflow or garbage data because the parser ignored the '-' sign and potentially read invalid characters or overflowed. This logic is incorrect and fragile.
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