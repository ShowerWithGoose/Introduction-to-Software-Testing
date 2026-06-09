#include<stdio.h>
typedef struct SHU{
	int zhi;
	struct SHU *linkl,*linkr;
	int ceng;
}*shu;
int main()
{
	int a,b,i,j;
	shu gen=NULL,zhil,zhiy,q,p;
	scanf("%d",&b);
	for(i=0;i<b;i++)
	{
		j=1;
		scanf("%d",&a);
		//printf("%d",a);
		q=(shu)malloc(sizeof(struct SHU));
		q->zhi=a;
		q->linkl=NULL;
		q->linkr=NULL;
		if(gen==NULL)
		{
			q->ceng=j;
			gen=q;
			//printf("%d",gen->zhi);
		}
		else
		{
			p=gen;
			//printf("%d",a);
			while(1)
			{
				if(a<p->zhi)
				{
					if(p->linkl!=NULL)
					{
						p=p->linkl;
						j++;
					}
					else if(p->linkl==NULL)
					{
						j++;
						q->ceng=j;
						p->linkl=q;
						
						break;
					}
				}
				else if(a>=p->zhi)
				{
					if(p->linkr!=NULL)
					{
						p=p->linkr;
						j++;
					}
					else if(p->linkr==NULL)
					{
						j++;
						q->ceng=j;
						p->linkr=q;
						break;
					}
				}
			}
		}//*/
	}
	li(gen);
	return 0;
 } 
 void li(shu o)
 {
 	if(o!=NULL)
 	{
 		if(o->linkl==NULL&&o->linkr==NULL)
 	{
 		printf("%d %d\n",o->zhi,o->ceng);
	 }
	li(o->linkl);
 	li(o->linkr);
 	}	 
 	
 }

