#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct table{
	char word[40];
	int num;
	struct table *next;
};
char t[40];
int main()
{
	char c;
	int cnt=0, i=0, j;
	struct table *tmp, *now, *pre, *head;
	tmp=now=pre=head=NULL; 
	FILE *in;
	in=fopen("article.txt", "r");
	if(in==NULL)
	{
		perror("Can't open in.txt");
		return 0;
	}
	while((c=fgetc(in))!=EOF)
	{
		if((c>='a' && c<='z')||(c>='A' && c<='Z'))
		{
			t[i]=(c>='a' && c<='z') ? c : c+('a'-'A');
			i++;
		}
		else if(strlen(t)>0) //一个单词读入结束 
		{
			t[i]='\0';
			i=0;
			cnt++; //记录词的个数
			 
			tmp=(struct table *)malloc(sizeof(struct table));
			strcpy(tmp->word, t);
			tmp->num=1;
			tmp->next=NULL;
			//查找、插入 
			if(cnt==1) head=tmp;
			else
			{
				now=head;
				pre=head;
				while(1) //开始遍历 
				{
					if(strcmp(t, now->word)<0) //如果t的字典序小，则插在tmp前面 
					{
						if(now==head) //tmp插在头结点前 
						{
							tmp->next=head;
							head=tmp;
							pre=head;
						}
						else //tmp插在中间 
						{
							tmp->next=now;
							pre->next=tmp;
						}
						break;
					}
					else if(strcmp(t, now->word)>0) //如果t的字典序打，则now和pre后移 
					{
						pre=now;
						now=pre->next;
					}
					else if(strcmp(t, now->word)==0) //如果t已出现过 
					{
						now->num++;
						free(tmp);
						break;
					}
					if(now==NULL)
					{
						pre->next=tmp;
						break;
					}
				}
			}
			t[0]='\0'; //t初始化
		}
	}
	tmp=head;
	while(tmp!=NULL)
	{
		printf("%s %d\n", tmp->word, tmp->num);
		tmp=tmp->next;
	}
	fclose(in);
	return 0;
}

