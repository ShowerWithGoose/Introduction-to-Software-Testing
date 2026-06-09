#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct lln{
		int a;
		long long x;
		struct lln *next;
}m;
int cmp(const void *,const void *);
int main()
{
	m input,in[505],out[30005];
	int i=0, len, k;
	input.next = NULL;
	m *head = (m *)malloc(sizeof(m));
	m *cnode = head, *p;
	char c;
	while((scanf("%d ",&input.a))!=EOF){
		scanf("%lld",&input.x);
		c = getchar();
		if(c!='\n'){
			p = (m *)malloc(sizeof(m));
			p->next = NULL;
			cnode->next = p;
		}
		cnode->a = input.a;
		cnode->x = input.x;
		cnode = cnode->next;
		if(c=='\n')
			break;
	}
	cnode = head;
	while((scanf("%d",&in[i].a))!=EOF){
		scanf("%lld",&in[i].x);
		c = getchar();
		i++;
		if(c=='\n')
			break;
	}
	len = i;
	while(cnode!=NULL){
		for(i=0;i<len;i++){
			if(i!=len-1){
				p = (m *)malloc(sizeof(m));
				p->a = cnode->a;
				p->x = cnode->x;
				p->next = cnode->next;
				cnode->next = p;
			}
			cnode->a *= in[i].a;
			cnode->x += in[i].x;
			cnode = cnode->next;
		}
	}
	cnode = head;
	i=0;
	while(cnode!=NULL){
		out[i].a = cnode->a;
		out[i].x = cnode->x;
		cnode = cnode->next;
		i++;
	}
	len = i;
	qsort(out,len,sizeof(m),cmp);
	for(i=0;i<len-1;i++){
		if(out[i].x == out[i+1].x){
			out[i].a += out[i+1].a;
			for(k=i+1;k<len-1;k++)
				out[k] = out[k+1];
			len--; i--;
		}
	}
	for(i=0;i<len;i++){
		if(out[i].a!=0)
			printf("%d %lld ",out[i].a,out[i].x);
	}
    return 0;
}

int cmp(const void *a,const void *b){
	m *p1 = (m *)a;
	m *p2 = (m *)b;
	if(p1->x<p2->x) return 1;
	if(p1->x>p2->x) return -1;
	return 0;
}

