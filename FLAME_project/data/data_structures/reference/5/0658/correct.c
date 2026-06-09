#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct LLN{/*Definition*/
	int index;
	int coe;
	struct LLN *pNext;
}linklist;
int compare(const void *p1,const void *p2){
	return -(((int *)p1)[1]-((int *)p2)[1]);
}
int a1[1000][2];int a2[1000][2];int a[1000][2];
int main(){
	char s1[100],s2[100];
	gets(s1);gets(s2);
	/*We need to separate the number and transform them from chars into number*/
	int len1=strlen(s1),len2=strlen(s2);
	int j1=0,j2=0;
	int flag=0;
	for(int i=0;i<len1;i++){
		if(s1[i]==' '){
			flag++;
			continue;
		}
		else{
			if(flag%2){
				int k=i,count=0;
				while(s1[k]>='0'&&s1[k]<='9'){
					count++;k++;
				}
				for(int p=1;p<=count;p++){
					int m=s1[i+p-1]-'0';
					for(int l=0;l<count-p;l++) m*=10;
					a1[j1][1]+=m;
				}
				i+=count-1;
			}
			else{
				int k=i,count=0;
				while(s1[k]>='0'&&s1[k]<='9'){
					count++;k++;
				}
				for(int p=1;p<=count;p++){
					int m=s1[i+p-1]-'0';
					for(int l=0;l<count-p;l++) m*=10;
					a1[j1][0]+=m;
				}
				i+=count-1;
			}
		}
		if(flag%2==1)j1++;
	}
	flag=0;
	for(int i=0;i<len2;i++){
		if(s2[i]==' '){
			flag++;
			continue;
		}
		else{
			if(flag%2){
				int k=i,count=0;
				while(s2[k]>='0'&&s2[k]<='9'){
					count++;k++;
				}
				for(int p=1;p<=count;p++){
					int m=s2[i+p-1]-'0';
					for(int l=0;l<count-p;l++) m*=10;
					a2[j2][1]+=m;
				}
				i+=count-1;
			}
			else{
				int k=i,count=0;
				while(s2[k]>='0'&&s2[k]<='9'){
					count++;k++;
				}
				for(int p=1;p<=count;p++){
					int m=s2[i+p-1]-'0';
					for(int l=0;l<count-p;l++) m*=10;
					a2[j2][0]+=m;
				}
				i+=count-1;
			}
		}
		if(flag%2==1)j2++;
	}
	int k=0;
	for(int i=0;i<j1;i++){
		for(int j=0;j<j2;j++){
			a[k][0]=a1[i][0]*a2[j][0];
			a[k][1]=a1[i][1]+a2[j][1];
			k++;
		}
	}
	qsort(a,k,sizeof(a[0]),compare);
//	for(int i=0;i<k;i++) printf("%d %d ",a[i][0],a[i][1]);
//	return 0; 
	linklist *Head=(linklist *)malloc(sizeof(linklist));
	Head->coe=0;Head->index=0;
	Head->pNext=NULL;
	Head->pNext=(linklist *)malloc(sizeof(linklist));
	linklist *Currentnode=Head->pNext;
	for(int i=0;i<k;i++){
		if(Currentnode->index==a[i][1]) Currentnode->coe+=a[i][0];
		else{
			Currentnode->pNext=(linklist *)malloc(sizeof(linklist));
			Currentnode=Currentnode->pNext;
			Currentnode->coe=a[i][0];
			Currentnode->index=a[i][1];
		}
	}
	Currentnode->pNext=NULL;
	Currentnode=Head->pNext;
	Currentnode=Currentnode->pNext;
	while(Currentnode!=NULL){
		printf("%d %d ",Currentnode->coe,Currentnode->index);
		Currentnode=Currentnode->pNext;
	}
} 

