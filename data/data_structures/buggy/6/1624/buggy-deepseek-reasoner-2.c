#include <stdio.h>
#include <string.h>


int s[99999]={0};

char t[99999];


int main()
{
    int i,j=0,k,l=0;
    gets(t);
    k=strlen(t);
    for(i=0;i<k-2;i++) // @@ [Loop bound i<k-2 is incorrect; should process until end or until -1 encountered. This skips the last two characters, likely missing the -1 operation.]
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
                    while(t[l]!=' ') // @@ [This while loop does not handle negative numbers (e.g., -5) and may go out of bounds if the number is the last token without a trailing space.]
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
                    while(t[l]!=' ') // @@ [Same issue: does not handle negative numbers and end-of-string.]
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
                else if((s[j-1]+28)==0) // @@ [Incorrect and unnecessary condition for outputting -2]
                {
                    printf("-2 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0) // @@ [Incorrect condition for -8]
                {
                    printf("-8 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0) // @@ [Incorrect condition for -23]
                {
                    printf("-23 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0) // @@ [Incorrect condition for -56]
                {
                    printf("-56 ");
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0) // @@ [Incorrect condition for -45]
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
    // Missing handling for the -1 operation and any remaining operations. The program may never see the end marker.
    
    return 0;
}