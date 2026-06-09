#include <stdio.h>
#include <string.h>
struct list
{
    char word[50];
    int num;
}list[5000],temp;
int i=0,j=0,k=0,len=0,flag=0;
char zimu,voc[50];
int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");
    while((zimu=fgetc(fp))!=EOF)
    {
        if(zimu>='A'&&zimu<='Z')			//大写转小写 
        {
            zimu='a'+zimu-'A';
            voc[i]=zimu;					//存入voc 
            i++;
        }
        else if(zimu>='a'&&zimu<='z')		//小写直接存入 
        {
            voc[i]=zimu;
            i++;
        }
        else
        {
            if(strcmp(voc,"\0")!=0)			//voc不为空 
            {
                for(j=0;j<len;j++)			//寻找看是否出现过 
                {
                    if(strcmp(voc,list[j].word)==0)
                    {
                        flag=1;
                        list[j].num++;		//出现过――次数加一 
                        break;
                    }
                    else
                        flag=0;				//没出现过 
                }
                if(flag==0)
                {
                    strcpy(list[len].word,voc);	//list加一个新的 
                    list[len].num=1;
                    len++;
                }
                memset(voc,0,50);				//清空voc 
            }
            i=0;
        }
    }
    for(i=0;i<len;i++)				//排序 
    {
        for(j=i;j<len;j++)
        {
            if(strcmp(list[i].word,list[j].word)>0)
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
    }
    for(i=0;i<len;i++)
    {
        printf("%s %d\n",list[i].word,list[i].num);
    }
    fclose(fp);
    return 0;
}

