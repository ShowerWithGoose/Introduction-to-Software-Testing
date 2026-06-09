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
                else if((s[j-1]+28)==0)
                {
                    printf("-2 "); @@ [This condition is arbitrary and incorrect. It attempts to detect -2 by checking s[j-1] == -28, which is wrong. Similar issues exist for other hardcoded negative checks.]
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+22)==0)
                {
                    printf("-8 "); @@ [This condition assumes s[j-1] == -22 to print "-8", which is incorrect logic for handling negative numbers.]
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+277)==0)
                {
                    printf("-23 "); @@ [This condition assumes s[j-1] == -277 to print "-23", which is not how the number was stored during push.]
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244)==0)
                {
                    printf("-56 "); @@ [This condition assumes s[j-1] == -244 to print "-56", but the actual pushed value was -56, so this check is invalid.]
                    j=j-1;
                    s[j]=0;
                }
                else if((s[j-1]+244255)==0)
                {
                    printf("-45 "); @@ [This condition assumes s[j-1] == -244255 to print "-45", which is completely unrelated to the actual value -45. This causes the wrong output "-255" instead of "-45".]
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