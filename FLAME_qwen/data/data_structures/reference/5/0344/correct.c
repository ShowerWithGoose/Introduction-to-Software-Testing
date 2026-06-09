#include<stdio.h>

int head=1,tail=1,tailb=1,taila;

struct node{
	int index,coe;
	int next;
}a[1010];

struct node b[1010],c[501000];

int main()
{
	char ch;
	int j,i=1,k,xindex,xcoe;
	while(1){
		scanf("%d%d%c",&a[i].coe,&a[i].index,&ch);
		a[i].next=i+1;
		i++;
		if(ch=='\n'){
			taila=i;
			a[i].next=-1;
			break;
		}
	}
	i=1;
	while(1){
		scanf("%d%d%c",&b[i].coe,&b[i].index,&ch);
		b[i].next=i+1;
		i++;
		if(ch=='\n'){
			tailb=i;
			b[i].next=-1;
			break;
		}
	}
	for(i=1;i<=taila;i++){
		c[i].index=a[i].index+b[1].index;
		c[i].coe=a[i].coe*b[1].coe;
		c[i].next=i+1;
	}
	tail=taila;
	int cnt=tail;
	c[tail].next=-1;
	for(k=2;k<=tailb;k++)//bkºÍaiÏà³Ë 
		for(i=1;i<=taila;i++){
			xindex=a[i].index+b[k].index;
			xcoe=a[i].coe*b[k].coe;
			if(xindex==c[tail].index)
				c[tail].coe+=xcoe;
			else if(xindex>c[head].index){
				c[++cnt].index=xindex;
				c[cnt].coe=xcoe;
				c[cnt].next=head;
				head=cnt;
			}
			else if(xindex<c[tail].index){
				c[++cnt].index=xindex;
				c[cnt].coe=xcoe;
				c[cnt].next=-1;
				c[tail].next=cnt;
				tail=cnt;
			}
			else {
				for(j=head;j!=tail;j=c[j].next){
					if(xindex==c[j].index){
						c[j].coe+=xcoe;
						break;
					}
					else if(xindex>c[c[j].next].index){
						c[++cnt].index=xindex;
						c[cnt].coe=xcoe;
						c[cnt].next=c[j].next;
						c[j].next=cnt;
						break;
					}
				}
			}
		}
	for(i=head;i!=-1;i=c[i].next)
		if(c[i].coe)printf("%d %d ",c[i].coe,c[i].index);
	return 0;
}
		
		
		
		
		

