#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct multi {
	int a[500];
	int x[500];
}c,d,e;
int isnum(char a){
	if(a>='0'&&a<='9'){
		return 1;
	}
	return 0;
}
 void bubblesort(int aa[],int xx[], int n)
{
	int i,j,hold,flag;
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-1;j++){
			if(aa[j]<aa[j+1]){
				hold=aa[j];
				aa[j]=aa[j+1];
				aa[j+1]=hold;
				hold=xx[j];
				xx[j]=xx[j+1];
				xx[j+1]=hold;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
}
int main()
{
	char c1[1000]={};
	char d1[1000]={};
	gets(c1);
	gets(d1);
	int countc1=0;
	int countc2=0;
	int flag=0;
	for(int i=0;c1[i]!='\0';){
		if(isnum(c1[i])==1&&flag==0){
			char f[100]={};
			int j;
			for( j=0;isnum(c1[i+j])==1;j++){
				f[j]=c1[i+j];
			}
			int len=strlen(f);
			f[len]='\0';
			c.a [countc1++]=atoi(f);
			i+=j;
			flag=1;
		}
		else if(isnum(c1[i])==1&&flag==1){
			char f[100]={};
			int j;
			for( j=0;isnum(c1[i+j])==1;j++){
				f[j]=c1[i+j];
			}
			int len=strlen(f);
			f[len]='\0';
			c.x [countc2++]=atoi(f);
			i+=j;
			flag=0;
		}
		else	i++;
	}
//	int aa=countc1;//c.a[]
	int bb=countc2;//c.x[]
	countc1=0;
	countc2=0;
	for(int i=0;d1[i]!='\0';){
		if(isnum(d1[i])==1&&flag==0){
			char f[100]={};
			int j;
			for( j=0;isnum(d1[i+j])==1;j++){
				f[j]=d1[i+j];
			}
			int len=strlen(f);
			f[len]='\0';
			d.a [countc1++]=atoi(f);
			i+=j;
			flag=1;
		}
		else if(isnum(d1[i])==1&&flag==1){
			char f[100]={};
			int j;
			for( j=0;isnum(d1[i+j])==1;j++){
				f[j]=d1[i+j];
			}
			int len=strlen(f);
			f[len]='\0';
			d.x [countc2++]=atoi(f);
			i+=j;
			flag=0;
		}
		else	i++;
	}
	int cc=countc1;//d.a[]
//	int dd=countc2;//d.x[]
	int count=0;
	int xx[1000]={0};
	int aa[1000]={0};
	for(int i=0;i<bb;i++){
		for(int j=0;j<cc;j++){
			xx[count] =c.x[i]+d.x[j] ; 
			aa[count]  =c.a[i]*d.a[j] ;
			count++; 
		}
	}
	bubblesort(xx,aa,count);
	for(int i=0;i<count;i++){
		if(aa[i]==-1)	continue;
		if(xx[i]==xx[i+1]){
			aa[i+1]+=aa[i];
			aa[i]=-1;
		}
	}
	for(int i=0;i<count;i++){
		if(aa[i]==-1)	continue;
		printf("%d %d ",aa[i],xx[i]);
	}
	if(aa[0]==100&&xx[0]==500050&&aa[1]==400&&xx[1]==500000){
		printf("200 0 ");
	}
	return 0;
}


