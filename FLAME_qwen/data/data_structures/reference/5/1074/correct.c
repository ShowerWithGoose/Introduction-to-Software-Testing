#include <stdio.h>
typedef struct Link
{
	int def;
	int num;
	
}link;
link la[1000];
link lb[1000];
link lc[100000];
int cmp(const void* p1,const void* p2)
{
  link* pa=(link*) p1;
  link* pb=(link*) p2;
  if(pa->def>pb->def) return -1;
  else return 1; 
}
int main()
{
	char c='a';
	int i=0;
	while(c!='\n')
	{
	    scanf("%d%d%c",&la[i].num,&la[i].def,&c);
		i++;
	}
	int j=0;
	c='a';
	while(c!='\n')
	{
	
		scanf("%d%d%c",&lb[j].num,&lb[j].def,&c);
		j++;
	}
	int p=0;
	for(int m=0;m<i;m++)
	{
		for(int n=0;n<j;n++)
		{
			lc[p].num=la[m].num*lb[n].num;
			lc[p].def=la[m].def+lb[n].def;
			p++;
		}
	}
	
	qsort(lc,p,sizeof(link),cmp);
	
	for(int m=0;m<p;m++)
	{
		if(lc[m].def==lc[m+1].def&&m!=p-1) lc[m+1].num+=lc[m].num,lc[m].num=0;
		if(lc[m].num) printf("%d %d ",lc[m].num,lc[m].def);
	}

	
	
	return 0;
	

}


