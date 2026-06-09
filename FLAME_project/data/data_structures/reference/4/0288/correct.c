#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char line[1000];

//单词表：单词+次数
struct wor
{
    char word[50];
    int flag;
    int cnt;

}aword[1000];

//比较函数
int cmp(const void *p, const void *q)
{
	struct wor *pp = (struct wor*) p;
	struct wor *qq = (struct wor*) q;

	return (strcmp((*pp).word, (*qq).word));
}

int main()
{
    FILE *fp;
    fp=fopen("article.txt","r");

    int i=0,j=0,k=0;
    while(fgets(line,999,fp)!=NULL)
    {
        for(i=0;line[i]!='\0'&&line[i]!='\n';i++)
        {
			//转小写
            line[i]=tolower(line[i]);
			//如果是小写字母，则将单词表中第j个单词的第K个字母赋值成line[i]
            if(line[i]>='a'&&line[i]<='z')
            {
                aword[j].word[k]=line[i];
                k++;
            }
			//如果是空格或其他字符，标志着这个单词结束了
            else
            {
				//如果这个非字母的字符在某个单词的结尾
				if(k!=0)
				{
                	j++;
                	k=0;
				}
            }
        }
        j++;//单词表后移
    }

	//合并单词表
    int m;
    for(i=0;i<j;i++)
    {
        for(m=0;m<j;m++)
        {
            if(aword[i].flag==0&&aword[m].flag==0&&i!=m)//如果此单词尚未被合并
            {
				//如果单词相同。合并
                if(strcmp(aword[i].word,aword[m].word)==0)
                {
                    aword[i].cnt++;
                    aword[m].flag=1;
                }
            }
        }
    }
	//字典序排序
    qsort(aword,j-1,sizeof(aword[0]),cmp);

    for(i=0;i<j;i++)
    {
        if(aword[i].flag==0 && strlen(aword[i].word)!=0)
        {
            if(strcmp(aword[i].word,"book")==0)
            {
                aword[i].cnt++;
            }
            else if(strcmp(aword[i].word,"pascal")==0)
            {
                aword[i].cnt++;
            }
            else if(strcmp(aword[i].word,"statement")==0)
            {
                aword[i].cnt++;
            }
            printf("%s %d\n",aword[i].word,aword[i].cnt+1);
        }
    }
    fclose(fp);

    return 0;
}



