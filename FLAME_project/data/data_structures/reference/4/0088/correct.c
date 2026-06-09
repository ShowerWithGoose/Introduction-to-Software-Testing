#include <stdio.h>
#include <string.h>
struct list
{
    char word[100];
    int num;
}list[10000],temp;
int main()
{
    int i=0,j=0,k=0,n=0,flag=0;
    char c,str[100]={0};
    FILE *fp=fopen("article.txt","r");
    while((c=fgetc(fp))!=EOF)
    {
      
        if(tolower(c)>='a'&&tolower(c)<='z')
        {
            str[i]=tolower(c);
            i++;
        }//存储
        else//其他情况说明这个单词已经读完了
        {
            if(strcmp(str,"\0")!=0)
            {
                for(j=0;j<n;j++)
                {
                    if(strcmp(str,list[j].word)==0)
                    {
                        flag=1;
                        list[j].num++;//找到就加1
                        break;
                    }
                    else
                        flag=0;
                }//在已有的单词表里进行寻找
                if(flag==0)
                {
                    strcpy(list[n].word,str);
                    list[n].num=1;
                    n++;
                }//没找到就放到末尾
                for(k=0;k<100;k++)
                    str[k]='\0';//将map清空
            }
            i=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(strcmp(list[i].word,list[j].word)<0) 
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
                
            }
        }
    }//冒泡排序法
    for(i=0;i<n;i++)
    {
        printf("%s %d\n",list[i].word,list[i].num);
    }//输出
    fclose(fp);
}



