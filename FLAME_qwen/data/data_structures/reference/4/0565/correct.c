#include <stdio.h>
#include <stdlib.h>
typedef struct word *pw;
struct word{
	char c[50];
	int num;
	pw next;
};
pw vocabulary;
FILE *fp;
pw set();
pw add(char*,pw);
pw input();
int judge(pw,pw);
void Qsort(pw);
void change(pw,pw);
pw delete(pw);
void output();
int main()
{
	vocabulary=set();
	Qsort(input());
	output();
}
pw set()
{
	pw ptrl;
	ptrl=(pw)malloc(sizeof(struct word));
	ptrl->next=NULL;
	int i;
	for (i=0;i<50;i++)
		ptrl->c[i]=0;
	ptrl->num=0;
	return ptrl;
}
pw input()
{
	fp=fopen("article.txt","r");
	char c,store[50];int i=0;
	pw ptrl=vocabulary;
	for (i=0;i<50;i++){
		store[i]=0;
	}
	i=0;
	while ((c=fgetc(fp))!=EOF){
		if (c>='A'&&c<='Z'){
			c+=32;
		}
		if (c>='a'&&c<='z'){
			store[i]=c;
			i++;
		}
		else {
			ptrl=add(store,ptrl);
			for (i=0;i<50;i++){
				store[i]=0;
			}
			i=0;
		}
	}
	if (store[0]!='\0'){
		ptrl=add(store,ptrl);
	}
	return ptrl;
}
pw add(char *store,pw x)
{
	if (*(store)==0)
		return x;
	pw ptrl=set();
	int i=0;
	while (*(store+i)!='\0'){
		ptrl->c[i]=*(store+i);
		i++;
	}
	for (;i<50;i++){
		ptrl->c[i]='\0';
	}
	x->next=ptrl;
	ptrl->num++;
	return ptrl;
}
int judge(pw x,pw y)
{
	int i=0;
	while (x->c[i]!='\0'){
		if (y->c[i]=='\0')
			return 1;
		if (x->c[i]<y->c[i])
			return -1;
		if (x->c[i]>y->c[i])
			return 1;
		i++;
	}
	if (y->c[i]=='\0')
		return 0;
	return -1;
}
void Qsort(pw x)
{
	pw ptrl=vocabulary,tmp,tmp2=x->next;int ju;
//	output();
//	printf("\n");
	if (x==ptrl->next||x==ptrl)
		return;
	while (ptrl->next->next!=tmp2){
		tmp=ptrl->next;
		ju=judge(ptrl->next,tmp->next);
		if (ju==1){
			change(ptrl,tmp);
			//output();
			//printf("\n");
		}
		else if (ju==0){
			tmp=delete(tmp);
			//output();
			//printf("\n");
			if (tmp==x){
				free(tmp);
				break;
			}
			else{
				free(tmp);
				continue;
			}
		}
		ptrl=ptrl->next;
	}
	Qsort(ptrl);
}
void change(pw x,pw y)
{
	pw ptrl=y->next,tmp=ptrl->next;
	x->next=ptrl;
	ptrl->next=y;
	y->next=tmp;
}
pw delete(pw x)
{
	pw ptrl=x->next;
	x->next=ptrl->next;
	x->num+=ptrl->num;
	return ptrl;
}
void output()
{
	pw ptrl=vocabulary->next;int i;
	while (ptrl!=NULL){
		for (i=0;ptrl->c[i]!='\0';i++)
			printf("%c",ptrl->c[i]);
		printf(" %d\n",ptrl->num);
		ptrl=ptrl->next;
	}
}


