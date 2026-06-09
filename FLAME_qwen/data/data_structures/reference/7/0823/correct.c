#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct tree{
	int num;
	int llink;
	int rlink;
	int level;
}trie[10000]; 

void tree_build(int p){
	int m,t=0,h=1,r=0;
	scanf("%d",&m);
	if(p==0){
		trie[0].num=m;
		trie[0].level=1;
	}
	else{
		trie[p].num=m;
		while(r==0){
			if(m>=trie[t].num){
				if(trie[t].rlink==0){
					trie[t].rlink=p;
					trie[p].level=h+1;
					r=1;
				}
				else{
					t=trie[t].rlink;
					h++;
				}
			}
			else if(m<trie[t].num){
				if(trie[t].llink==0){
					trie[t].llink=p;
					trie[p].level=h+1;
					r=1;
				}
				else{
					t=trie[t].llink;
					h++;
				}
			}
		}
	}
	return ;
}

void tree_through(int t){
	if(trie[t].level==0){
		return;
	}
	if(trie[t].level!=0){
		if(trie[t].llink==0&&trie[t].rlink==0)
		printf("%d %d\n",trie[t].num,trie[t].level);
	}
	if(trie[t].llink!=0)
	tree_through(trie[t].llink);
	if(trie[t].rlink!=0)
	tree_through(trie[t].rlink);
	return;	
}

int main()
{
	int n,p=0;
	scanf("%d",&n);
	while(n--){
		tree_build(p);
		p++;
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

