#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void change(char word[][20], int n);
int main()
{
	char word[1000][20];
    char in;
    int i=0,j=0,n=0;
    int num[1000]={0},f=0;
    FILE *fi;
    fi=fopen("article.txt","r");
    in=fgetc(fi);
    while (in!=EOF)
    {
    	int a,b,c;
    	a=ispunct(in);
    	b=isspace(in);
    	c=isalpha(in);
        if (a!=0)
        {
           word[i][j]='\0';
            j=0;
            i++;
            n++;
        }
        if (b!=0)
        {
           word[i][j]='\0';
            j=0;
            i++;
            n++;
        }
        if (c!=0)
        {
           word[i][j]=in;
            j++;
        }
        in=fgetc(fi);
    }
    for(i=0;i<n;i++)
    {
        for (j=0;j<strlen(word[i]);j++)
        {
            word[i][j]=tolower(word[i][j]);
        }
    }
    for (i=0;i<n;i++)
    {
        change(word,n);
    }
    for (i=0; i<n;i++)
    {
    	num[i]=1;
        f=num[i]-1;
        for (j=i+1;j<n;j++)
        {
            if (strcmp(word[i],word[j])==0)
            {
                num[i]++;
                word[j][0]='\0';
                f=1;
            }
           else if (word[j][0]=='\0')
            {
                continue;
            }
            else
            {
                if(f==1)
                {
                i=j-1;
                }
                if(f!=1)
                {
                	i=i;
                	j=j;
                	n=n;
				}
                break;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if(word[i][0]=='\0')
        {
        	continue;
		}
		if (word[i][0]!='\0')
        {
            printf("%s %d\n",word[i],num[i]);
        }
    }
    fclose(fi);
    return 0;
}
void change(char word[][20], int n)
{
    char tmp[1000]="";
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (strcmp(word[i],word[j])>0)
            {
                strcpy(tmp,word[j]);
                strcpy(word[j],word[i]);
                strcpy(word[i],tmp);
            }
        }
    }
}

