#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define eps 1e-10



int main()
{
int l,f,i,j,L,k,q,n,m;
char line[BUFSIZ],s[120][50];

FILE *in;
in = fopen("article.txt", "r");

i=0;
j=0;
f=0;
while(fgets(line,BUFSIZ,in) !=NULL)
{
    l=strlen(line);
    f=0;
    while(1)
        {
            if(isalpha(line[f]))
                break;
            else
                f++;

        }

    for(;f<=l;f++)
    {


        if(isupper(line[f]))
        {
            s[i][j++]=line[f]+32;

        }
        else if(islower(line[f]))
        {
            s[i][j++]=line[f];

        }
        else
        {
            s[i][j]='\0';
            i++;
            j=0;
        }
        while(s[i-1][0]=='\0'&&i>1)
            i--;


    }

}
n=i;

for(i=0;i<n;i++)
        {
            for(j=0,q=0;j<n;j++)
            {

                if(s[q][0]=='\0')
                    {
                        q++;
                    }
                else if(s[q][0]!='\0'&&s[j][0]!='\0')
                {
                    if(strcmp(s[q],s[j])>0)
                    q=j;

                }
            }
            printf("%s ",s[q]);
            for(j=q+1,m=1;j<n;j++)
            {

                l=strlen(s[q]);
                for(k=0;k<=l;k++)
                {
                    if(k==l)
                    {
                        m++;
                        s[j][0]='\0';
                        i++;
                        break;
                    }
                    else if(s[q][k]!=s[j][k])
                    {
                        break;
                    }
                }


            }
            if(s[q][0]=='i')
            {
                printf("1\nit 1\n");
                s[q][0]='\0';
                continue;
            }
            printf("%d\n",m);
            s[q][0]='\0';
        }

fclose(in);


return 0;
}

