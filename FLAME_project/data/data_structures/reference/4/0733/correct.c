#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
FILE *in;
struct Node{
	char z[100];
	int num;
	int len;
};
struct Node list[1000];
int check(char *tem,int i,int sum){
	int k,j=0,pos=1,f=1;
	for(k=0;k<sum;k++){
		j=0;
		while(isalpha(tem[i+j])&&j<=list[k].len){
			if(tolower(tem[i+j])!=list[k].z[j]){
				f=0;
				break;
			}
			j++;
		}
		if(j==list[k].len&&isalpha(tem[i+j])<=0){
			pos=-k;
			break;
		}
	}
	if(pos<=0) return pos;
	j=0;
	while(isalpha(tem[i+j])){
		j++;
	}
	return j;
}
int cmp(const void *a,const void *b){
	struct Node *a1=(struct Node*)a;
	struct Node *b1=(struct Node*)b;
	return strcmp(a1->z,b1->z);
}
int main() {
	in=fopen("article.txt","r");
	char tem[200];
	int sum=0,i,j;
	while(fgets(tem,201,in)!=NULL){
		for(i=0;i<strlen(tem);i++){
			if(isalpha(tem[i])){
				int t=check(tem,i,sum);
				if(t>0){
					for(j=0;j<t;j++){
						list[sum].z[j]=tolower(tem[i+j]);
					}
					list[sum].len=t;
					list[sum].num++;
					sum++;
					i=i+t;
				}
				else{
					list[-t].num++;
					i=i+list[-t].len;
				}
			} 
		}
	}
	qsort(list,sum,sizeof(list[0]),cmp);
	for(i=0;i<sum;i++){
		printf("%s %d\n",list[i].z,list[i].num);
	}
	return 0;
}


