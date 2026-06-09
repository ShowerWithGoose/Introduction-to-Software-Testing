#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct list
{
    char word[100];
    int num;
}l[10000],tmp;
int main()
{
    int i=0,j=0,k=0,lenl=0,flag=0;
    char c,map[100]={0};
    FILE *fp;
    fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
        if(c>='a'&&c<='z'){
	        map[i]=c;
		    i++;
		}
		else if(c>='A'&&c<='Z'){
            c=c+'a'-'A';
            map[i]=c;
            i++;
        }
        
        else
        {
            if(strcmp(map,"\0")!=0)
            {
                for(j=0;j<lenl;j++)
                {
                    if(strcmp(map,l[j].word)==0)
                    {
                        flag=1;
                        l[j].num++;
                        break;
                    }
                    else
                        flag=0;
                }
                if(flag==0)
                {
                    strcpy(l[lenl].word,map);
                    l[lenl].num=1;
                    lenl++;
                }
                for(k=0;k<100;k++)
                    map[k]='\0';
            }
            i=0;
        }
    }
    for(i=0;i<lenl;i++)
    {
        flag=0;
        for(j=i;j<lenl;j++)
        {
            if(strcmp(l[i].word,l[j].word)>=0)
            {
                tmp=l[i];
                l[i]=l[j];
                l[j]=tmp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    for(i=0;i<lenl;i++)
    {
        printf("%s %d\n",l[i].word,l[i].num);
    }
    fclose(fp);
}

