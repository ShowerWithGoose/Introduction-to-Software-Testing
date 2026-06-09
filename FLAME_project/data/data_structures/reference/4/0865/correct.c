#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct word{
	char s[1005];
	int num;
};

int cmp(const void *a,const void *b);
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	struct word a[2005];
	char c;
	int sum=0,i=0,j=0,k=0;
	a[0].num=0;
	while((c=fgetc(in))!=EOF){
		if(!isalpha(c)){
			sum++;k=0;
			a[sum].num=0;
		}
		else{
			if(c>='a'&&c<='z')
			a[sum].s[k]=c;
			else
			a[sum].s[k]=c-'A'+'a';
			a[sum].num=1;
			k++;
		}
	}
	for(i=0;i<sum;i++){
		if(a[i].num==0) continue;
		for(j=0;j<i;j++){
			if(strcmp(a[i].s,a[j].s)==0){
				a[j].num++;
				a[i].num=0;
				break;
			}
		}
	}
	qsort(a,sum,sizeof(struct word),cmp);
	for(i=0;i<sum;i++){
		if(a[i].num!=0) 
		printf("%s %d\n",a[i].s,a[i].num);
	}



	return 0;
}
int cmp(const void *a,const void *b){
	struct word *a1=(struct word *)a,*b1=(struct word *)b;
	if(strcmp(a1->s,b1->s)>0) return 1;
	else return -1;
}

