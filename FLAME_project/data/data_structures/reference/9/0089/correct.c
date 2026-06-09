#include <stdio.h>
struct lines{
	int a[2];
	int b[2];
};
int cmp(struct lines *c,struct lines *d)
{
	return (*(struct lines *)c).a[0]-(*(struct lines *)d).a[0];
}
int main()
{
	int n,i,j,k;//k用于计线段数 
	int b[3]={0};//存储最多的段数，和起点 
	scanf("%d",&n);
	struct lines line[100],t;
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&line[i].a[0],&line[i].a[1],&line[i].b[0],&line[i].b[1]);
	qsort(line,i,sizeof(line[0]),cmp);
	for(i=0;i<n;i++){
		t=line[i];
		k=1;
		for(j=0;j<n;j++)
			if((t.b[0]==line[j].a[0])&&(t.b[1]==line[j].a[1])){
				t=line[j];
				k++;
			}
		if(k>b[0]){
			b[0]=k;
			b[1]=line[i].a[0];
			b[2]=line[i].a[1];
		}
		
	} 
	printf("%d %d %d",b[0],b[1],b[2]);
	return 0;
 } 

