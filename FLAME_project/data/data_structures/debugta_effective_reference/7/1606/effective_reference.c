#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct tree{
	int num;
	int llink;
	int rlink;
	int level;
}p[10000]; 

void tree_build(int i){
	int m,q=0,h=1,t=0;
	scanf("%d",&m);
	if(i==0){
		p[0].num=m;
		p[0].level=1;
	}
	else{
		p[i].num=m;
		while(t==0){
			if(m>=p[q].num){
				if(p[q].rlink==0){
					p[q].rlink=i;
					p[i].level=h+1;
					t=1;
				}
				else{
					q=p[q].rlink;
					h++;
				}
			}
			else if(m<p[q].num){
				if(p[q].llink==0){
					p[q].llink=i;
					p[i].level=h+1;
					t=1;
				}
				else{
					q=p[q].llink;
					h++;
				}
			}
		}
	}
	return ;
}

void tree_through(int q){
	if(p[q].level==0){
		return;
	}
	if(p[q].level!=0){
		if(p[q].llink==0&&p[q].rlink==0)
		printf("%d %d\n",p[q].num,p[q].level);
	}
	if(p[q].llink!=0)
	tree_through(p[q].llink);
	if(p[q].rlink!=0)
	tree_through(p[q].rlink);
	return;	
}

int main()
{
	int n,i=0;
	scanf("%d",&n);
	while(n--){
		tree_build(i);
		i++;
	}
	tree_through(0);
    return 0;
}
/*
树的构建与遍历。 
先从标准输入读取整数的个数，然后从下一行开始输入各个整数，
整数之间以一个空格分隔。

【输出形式】
按照从左到右的顺序分行输出叶结点的值及高度，
值和高度之间以一个空格分隔。*/
//遍历及释放仍需改为非递归； 

