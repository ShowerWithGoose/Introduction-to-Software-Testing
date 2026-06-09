#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1024
char line[MAXLINE];
struct word {//链表 
		char chr[500];
		int cnt;
		struct word *link;
	};
struct student *SelectSort(struct word *head)  
{  
    struct word *pfirst;      /* 排列后有序链的表头指针 */  
    struct word *ptail;       /* 排列后有序链的表尾指针 */  
    struct word *pminBefore;  /* 保留键值更小的节点的前驱节点的指针 */  
    struct word *pmin;        /* 存储最小节点   */  
    struct word *p;           /* 当前比较的节点 */  
    pfirst = NULL;  
    while (head != NULL)         /*在链表中找键值最小的节点。*/  
    {  
        for (p = head, pmin = head; p->link != NULL; p = p->link) /*循环遍历链表中的节点，找出此时最小的节点。*/  
        {  
            if (strcmp(p->link->chr,pmin->chr)<0) /*找到一个比当前min小的节点。*/  
            {  
                pminBefore = p;           /*保存找到节点的前驱节点：显然p->link的前驱节点是p。*/  
                pmin       = p->link;     /*保存键值更小的节点。*/  
            }  
        }  
        /*第一件事*/  
        if (pfirst == NULL)     /* 如果有序链表目前还是一个空链表                      */  
        {  
            pfirst = pmin;      /* 第一次找到键值最小的节点。                          */  
            ptail  = pmin;      /* 注意：尾指针让它指向最后的一个节点。                */  
        }  
        else                    /* 有序链表中已经有节点                                */  
        {  
            ptail->link = pmin; /* 把刚找到的最小节点放到最后，即让尾指针的link指向它。*/  
            ptail = pmin;       /* 尾指针也要指向它。                                  */  
        }  
        /*第二件事*/  
        if (pmin == head)        /* 如果找到的最小节点就是第一个节点                    */  
        {  
            head = head->link;   /* 显然让head指向原head->link,即第二个节点，就OK       */  
        }  
        else /*如果不是第一个节点*/  
        {  
            pminBefore->link = pmin->link; /*前次最小节点的link指向当前pmin的link,这样就让pmin离开了原链表。*/  
        }  
    }  
    if (pfirst != NULL)     /*循环结束得到有序链表first                */  
    {  
        ptail->link = NULL; /*单向链表的最后一个节点的link应该指向NULL */   
    }  
    head = pfirst;  
    return head;  
}  
int main() {
	FILE *in;
	in=fopen("article.txt","r");
	int i,e;
	
	struct word *first=NULL,*q;
	struct word *list;
	char w[1000]; //记录单词

	
	while(fgets(line, MAXLINE - 1, in) != NULL) {
		
		for(i=0; line[i]!='\0'; i++) 
		{
			if(line[i]>='A'&&line[i]<='Z')
				line[i]=line[i]-'A'+'a';
		}//小写化
		i=0;
		
		while(line[i]!='\0') 
		{
				e=0;
				while(1) 
				{
					if(line[i]>='a'&&line[i]<='z')
					{
					w[e]=line[i];
					e++;
					i++;
					} 
					else
						break;
				}//获取字符串
			i++;
			if(e>0) //读取成功
			{ 
				w[e]='\0';
				//printf("%s\n",w);
				q = (struct word *)malloc(sizeof(struct word));
				strcpy(q->chr,w);
				q->link=NULL;
				q->cnt=1;
				
				
				
				if(first==NULL)
					first=list=q;
				else //插入
				{ 
					list=first;
					while(1) //最后一个 
					{ 
						if(strcmp(q->chr,list->chr)==0) 
							{ //等
								(list->cnt)++;
								break;
							}
						else
						{	
							if(list->link==NULL)//最后一个 
							{	
								list->link=q;
								break;
							}
							else
							list=list->link;
						}	
					}
					
				}
			}
		}
	
	}
	; 
	list=SelectSort(first);
	while(list!=NULL)//打印 
	{
		printf("%s %d\n",list->chr,list->cnt);
		list=list->link;
	}
	return 0;
}

