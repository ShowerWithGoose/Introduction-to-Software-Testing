#include <stdio.h>
#include <string.h>
struct list
{
    char word[100];
    int num;
}list[10000],temp;
int main()
{
    int i=0,j=0,k=0,lenlist=0,flag=0;
    char ff,map[100]={0};
    FILE *fp;
    fp=fopen("article.txt","r");
    while((ff=fgetc(fp))!=EOF)
    {
        if(ff>=65&&ff<=90)
        {
            ff=ff+32;
            map[i]=ff;
            i++;
        }
        else if(ff>=97&&ff<=122)
        {
            map[i]=ff;
            i++;
        }
        else
        {
            if(strcmp(map,"\0")!=0)
            {
                for(j=0;j<lenlist;j++)
                {
                    if(strcmp(map,list[j].word)==0)
                    {
                        flag=1;
                        list[j].num++;
                        break;
                    }
                    else
                        flag=0;
                }
                if(flag==0)
                {
                    strcpy(list[lenlist].word,map);
                    list[lenlist].num=1;
                    lenlist++;
                }
                for(i=0;i<100;i++)
                    map[i]='\0';
            }
            i=0;
        }
    }
    for(i=0;i<lenlist;i++)
    {
        flag=0;
        for(j=i;j<lenlist;j++)
        {
            if(strcmp(list[i].word,list[j].word)>=0)
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
    for(i=0;i<lenlist;i++)
    {
        printf("%s %d\n",list[i].word,list[i].num);
    }
    fclose(fp);
}


