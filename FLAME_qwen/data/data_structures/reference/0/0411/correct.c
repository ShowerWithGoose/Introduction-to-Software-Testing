#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10

int main()
{
    char c[102],m[102];
    int i,j,k=0,r;
    scanf("%s",&c);
    j=strlen(c);
    for(i=0;i<j;i++)
    {



        if(!(c[i]=='-'))
            {
            m[k++]=c[i];

            }
        else if(c[i]=='-')
            {
                if(islower(c[i-1]))
                {
                    if(islower(c[i+1])&&c[i-1]<c[i+1])
                    {for(r=c[i+1]-c[i-1];r>1;r--)
                    {
                    m[k++]=c[i+1]-r+1;
                    }
                    }
                    else
                    m[k++]='-';


                }
                else if(isupper(c[i-1]))
                {
                    if(isupper(c[i+1])&&c[i-1]<c[i+1])
                    {for(r=c[i+1]-c[i-1];r>1;r--)
                    {
                    m[k++]=c[i+1]-r+1;
                    }
                    }
                    else
                    m[k++]='-';


                }
                else if(isdigit(c[i-1]))
                {
                    if(isdigit(c[i+1])&&c[i-1]<c[i+1])
                    {for(r=c[i+1]-c[i-1];r>1;r--)
                    {
                    m[k++]=c[i+1]-r+1;
                    }
                    }
                    else
                    m[k++]='-';

                }


            }
    }
    m[k]='\0';

    printf("%s",m);
    return 0;
}

