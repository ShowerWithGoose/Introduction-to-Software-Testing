#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
struct multi1{
	int a1;
	int n1;
}; 
struct multi2{
	int a2;
	int n2;
};
struct ans{
	int xiang;
	int xi;
};
int cmp(const void *a,const void *b)
{
	return(*(struct ans *)a).xi<(*(struct ans *)b).xi?1:-1;
}
int main()
{
	int x=0,y=0,w=0,z=0,cnt=1,max=0;
	char s1,s2;
	struct multi1 c1[1000];
	struct multi2 c2[1000];
	struct ans c3[1000];
	while(s1!='\n'){
		scanf("%d%d",&c1[x].a1,&c1[x].n1);
		x++;
		s1=getchar();
	}
	while(s2!='\n'){
		scanf("%d%d",&c2[y].a2,&c2[y].n2);
		y++;
		s2=getchar();
	}
	for(int i=0;i<x;i++){
		
		for(int j=0;j<y;j++){
			c3[w].xiang=c1[i].a1*c2[j].a2;
			c3[w].xi=c1[i].n1+c2[j].n2;
			w++;
		}
	}
	qsort(c3,w,sizeof(c3[0]),cmp);
	for(int i=0;i<w;i++){
		if(c3[i].xi==c3[i+1].xi){
			cnt++;
		}
		else{
			if(cnt>max){
				max=cnt;
				cnt=0;
			}
		}
	}
	for(int i=0;i<max;i++){
	for(z=0;z<w;z++){
		if(c3[z].xi==c3[z+1].xi){
			c3[z].xiang=c3[z+1].xiang+c3[z].xiang;
			for(int j=z+1;j<w;j++){
				c3[j].xiang=c3[j+1].xiang;
				c3[j].xi=c3[j+1].xi;
			}
		}
	}	
}
	for(int i=0;i<z;i++){
		if(c3[i].xiang!=0)
		printf("%d %d ",c3[i].xiang,c3[i].xi);
	}
	return 0;
}


