#include<stdio.h>
#include<string.h>
char c[100],word[10000][100],mid[100],word1[10000][100];
int i,i1=0,j,m=0,time=0,Time[10000]={0},n=0;
int main()
{
    FILE *in;
    
    in=fopen("article.txt","r");
    while(fscanf(in,"%s",c)!=EOF)
    {
        for(i=0;i<strlen(c);i++)
        {
            if(c[i]>='a'&&c[i]<='z')
            {
                word[m][i1]=c[i];
                i1++;
            }
            else if(c[i]>='A'&&c[i]<='Z')
            {
            	word[m][i1]=c[i]+32;
            	i1++;
			}
			else
			{
				m++;
				i1=0;
				continue;
			}
        }
       	word[m][i1]='\0';
       	m++;
        i1=0;
    }
    for(i=0;i<m-1;i++)
    {
        for(j=i;j<m;j++)
        {
            if(strcmp(word[i],word[j])>0)
            {
                strcpy(mid,word[j]);
                strcpy(word[j],word[i]);
                strcpy(word[i],mid);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        if(strcmp(word[i],word[i-1])!=0)
        {
            strcpy(word1[time],word[i]);
            time++;
        }
        else
        {
            Time[time-1]++;
        }
    }
    for(i=0;i<time;i++)
    {
    	//if(word1[i][0]>='a'&&word1[i][0]<='z')
        printf("%s %d\n",word1[i],Time[i]+1);
    }
    
}



