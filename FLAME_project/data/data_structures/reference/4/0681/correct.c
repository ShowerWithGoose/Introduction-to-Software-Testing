#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//单词节点 
struct Node{
	char word[20];
	int num;
};
char c[20];
int main()
{
	struct Node Node1[1001];
	int x=0;
	int i=0;
	int j,k,tmp;
	int flag=0;
	char ch;
	//for(i=0;i<=1000;i++)
	//{
	//Node1[i].num=0;
	//}
	i=0;
	FILE* fp;
	fp=fopen("article.txt","r");
	while((ch=fgetc(fp))!=EOF)
    {
        if(ch>='A'&&ch<='Z')
        {
            ch='a'+ch-'A';
            c[i]=ch;
            i++;
       
        }//如果是大写字母，转换为小写字母存储
        else if(ch>='a'&&ch<='z')
        {
            c[i]=ch;
            i++;
        
        }//小写字母直接存储
        else//其他情况说明这个单词已经读完了
        {
            if(strcmp(c,"\0")!=0)
            {
                for(j=0;j<x;j++)
                {
                    if(strcmp(c,Node1[j].word)==0)
                    {
                        flag=1;
                        Node1[j].num++;//找到就加1
                        break;
                    }
                    else
                        flag=0;
                }//在已有的单词表里进行寻找
                if(flag==0)
                {
                    strcpy(Node1[x].word,c);
                    Node1[x].num=1;
                    x++;
                }//没找到就放到末尾
                for(k=0;k<20;k++)
                    c[k]='\0';//将map清空
            }
            i=0;
        }
    }
    for(i=0;i<x-1;i++)
    {
    	for(j=i+1;j<x;j++)
    	{
    		if(strcmp(Node1[i].word,Node1[j].word)>0)
    		{
    			tmp=Node1[j].num;
    			Node1[j].num=Node1[i].num;
    			Node1[i].num=tmp;
    			strcpy(c,Node1[j].word);
    			strcpy(Node1[j].word,Node1[i].word);
    			strcpy(Node1[i].word,c);
			}
		}
	}
	for(i=0;i<x;i++)
	{
		printf("%s %d\n",Node1[i].word,Node1[i].num);
	}
	fclose(fp);
	return 0;
}

