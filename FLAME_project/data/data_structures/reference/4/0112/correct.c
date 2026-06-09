#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct diction{
    char w[100];
    int time;
}word[1005],para;
int test(char ch[],int max)
{
    int i,t=0;
    for(i=0;i<max;i++)
    {
        if(strcmp(ch,word[i].w)==0)
        {
            t=1;
            word[i].time++;
        }
    }
    if(t==1) return 1;
    if(t==0) return 0;
}
int main()
{
    char c,ch[1005]={},wenben[10005];
    int i=0,j=0,b=0,k,t,max=0;
    FILE *in;
    in=fopen("article.txt","r");
    while((c=fgetc(in))!=EOF)
    {
        wenben[i++]=c;
    }
    for(i=0;i<strlen(wenben);i++)
    {
        if(wenben[i]>=65&&wenben[i]<=90)
        {
            wenben[i]+=32;
        }
    }
    /*for(i=0;i<strlen(wenben);i++) printf("%c",wenben[i]);*/
    for(i=0;i<strlen(wenben);i++)
    {
    	/*printf("waawdfad\n");*/
        if(wenben[i]<'a'||wenben[i]>'z')
        {
        	/*printf("fef");*/
            if(b==1)
            {
                b=0;
                t=test(ch,max);
                if(t==0)
                {
                    strcpy(word[max].w,ch);
                    word[max].time++;
                    max++;
                }
                j=0;
                memset(ch,0,strlen(ch));
            }
        }
        else if(wenben[i]>='a'&&wenben[i]<='z')
        {
        	/*printf("ja");*/
            b=1;
            ch[j++]=wenben[i];
            /*printf("%c",ch[j][k]);*/
        }
    }
    for(i=0;i<max;i++)
    for(j=0;j<max-1;j++)
    {
    	if(strcmp(word[j].w,word[j+1].w)>0)
    	{
    		para=word[j];
    		word[j]=word[j+1];
    		word[j+1]=para;
		}
	}
    for(i=0;i<max;i++)
    {
    	printf("%s %d\n",word[i].w,word[i].time);
	}
	fclose(in);
}

