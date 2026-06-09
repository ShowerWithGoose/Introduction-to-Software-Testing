#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000000

typedef struct position{
	int x1;
	int y1;
	int x2;
	int y2;
}s[105];
int com(const void *a,const void*b){
	struct position *c=a;
	struct position *d=b;
	return c->x1 -d->x1 ;
}
int main(){
	struct position s[105];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf(" %d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
	}
	qsort(s,n,sizeof(s[0]),com);
    int c[105]={0},cn[105]={0};
	for(i=0;i<n;i++){
		cn[i]=0;
		if(c[i]==0){
	     int j;
	     for(j=i+1;j<n;j++){
	      if(s[i].x2==s[j].x2&&s[j].y2==s[i].y2){
	      	c[i]=1;
	      	c[j]=1;
	      	cn[i]++;
	      	s[i].x2=s[j].x1;
			s[i].y2=s[j].y1;
		  }
		  else if(s[i].x1==s[j].x1&&s[j].y1==s[i].y1){
		  	c[i]=1;
		  	c[j]=1;
		  	cn[i]++;
	      	s[i].x1=s[j].x2;
			s[i].y1=s[j].y2;
		  }
		  else if(s[i].x1==s[j].x2&&s[j].y1==s[i].y2){
		  	c[i]=1;
		  	c[j]=1;
		  	cn[i]++;
	      	s[i].x1=s[j].x1;
			s[i].y1=s[j].y1;
		  }
		  else if(s[i].x2==s[j].x1&&s[j].y1==s[i].y2){
		  	c[i]=1;
		  	c[j]=1;
		  	cn[i]++;
	      	s[i].x2=s[j].x2;
			s[i].y2=s[j].y2;
		  }
		 }
		}
		else continue;
	}
	int max=0;  int ii;
	for(i=0;i<n;i++){
		if(cn[i]>max){
			max=cn[i];
			ii=i;
		}
	}
	printf("%d %d %d",max+1,s[ii].x1,s[ii].y1);
	return 0;
}

