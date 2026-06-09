#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct s{
	int beginx;
	int beginy;
	int endx;
	int endy;
	int num;
}s[105];

int c(const void *a,const void *b){
	struct s *x=(s *)a;
	struct s *y=(s *)b;
	if(x->beginx!=y->beginx) return x->beginx - y->beginx;
	else return x->beginy - y->beginy;
}

int main(){
	struct s s[105];
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&s[i].beginx,&s[i].beginy,&s[i].endx,&s[i].endy);
		s[i].num=1;
	}
	qsort(s,n,sizeof(s[0]),c);
//	i=0;
//	for(i=0;i<n;i++){
//		printf("%d %d %d %d\n",s[i].beginx,s[i].beginy,s[i].endx,s[i].endy);
//	}
	
	i=0;
	for(i=0;i<n;i++){
		int tempa=s[i].endx;
		int tempb=s[i].endy;
		for(j=i+1;j<n;j++){
			if(s[j].beginx==tempa&&s[j].beginy==tempb){
				tempa=s[j].endx;
				tempb=s[j].endy;
				s[i].num+=s[j].num;
			    }
			}
		}
	i=0;
	int max=-1;
	int flag=0;
	for(i=0;i<n;i++){
		if(s[i].num>max){
			max=s[i].num;
			flag=i;
		}
	}
	printf("%d %d %d",max,s[flag].beginx,s[flag].beginy);//
	return 0;
}

