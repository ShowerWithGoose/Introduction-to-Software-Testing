#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
	int a,x;
}num[10005],m[10005],n[10005];
char str[10000];
int h;
int qwe;
int cmp(const void*a,const void *b){
	struct node* p=(struct node*)a;
	struct node* q=(struct node*)b;
	return q->x-p->x;
}
int check(int n){
		for(int v=0;v<h;v++){
			if(n==num[v].x) {
				qwe=v;
			return 1;
		}}
		
		return 0;
}
int main(){
	int l=0,cnt=0;
	gets(str);
	int len=strlen(str);
		int i=0;
	while(i<len){
		int j=0,o=0;
		for(j=0;str[i+j]!=' '&&str[i+j]!='\n';j++){//j=i
		}
		o=j;
		for(int k=0;j>0;j--,k++) {
		m[l].a+=(str[i+k]-'0')*(int)pow(10,j-1);
		}
		i=i+o+1;
		j=0;
		for(j=0;str[j+i]!=' '&&str[i+j]!='\0';j++){//\n
		}
		o=j;
		for(int k=0;j>0;j--,k++) {
		m[l].x+=(str[i+k]-'0')*(int)pow(10,j-1);
		}
		l++;
		i=i+o+1;
	}
	
	gets(str);
	len=strlen(str);
	i=0;
	int k=0;
	while(i<len){
		int j=0,o=0;
		for(j=0;str[i+j]!=' '&&str[i+j]!='\n';j++){
		}
		o=j;
		for(int p=0;j>0;j--,p++) {
		n[k].a+=(str[i+p]-'0')*(int)pow(10,j-1);
		}
		i=i+o+1;
		j=0;
		for(j=0;str[j+i]!=' '&&str[i+j]!='\0';j++){
		}
		o=j;
		for(int p=0;j>0;j--,p++) {
		n[k].x+=(str[i+p]-'0')*(int)pow(10,j-1);
		}
		k++;
		i=i+o+1;
	}	
	h=0;
	int temp=0,t=0;
	for(int i=0;i<l;i++){
		for(int j=0;j<k;j++){
		t=m[i].a*n[j].a;	
		temp=m[i].x+n[j].x;
		if(i==0&&j==0){
			num[h].a=m[i].a*n[j].a;
			num[h++].x=temp;
			continue;
		}
			if(check(temp))
				num[qwe].a+=t;
			else{
				num[h].a=t;
				num[h++].x=temp;
				}
			}	
	}
	qsort(num,h,sizeof(struct node),cmp);
	for(int i=0;i<h;i++)
printf("%d %d ",num[i].a,num[i].x);
	return 0;
}

