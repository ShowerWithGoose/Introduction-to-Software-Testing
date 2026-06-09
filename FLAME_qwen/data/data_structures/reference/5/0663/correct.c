#include<stdio.h>
#include<stdlib.h>
struct multi{
	int coe;
	int exp;
}a[100],b[100],c[100]; 
int main()
{
	char ch=' ';
	int lena=0,lenb=0;
	while(ch!='\n'){
		scanf("%d%d%c",&a[lena].coe,&a[lena].exp,&ch);
		lena++;
	}
	ch=' ';
	while(ch!='\n'){
		scanf("%d%d%c",&b[lenb].coe,&b[lenb].exp,&ch); 
		lenb++;
	}
	int lenc=0;
	for(int i=0;i<lena;i++){
		for(int j=0;j<lenb;j++){
			c[lenc].coe=a[i].coe*b[j].coe;
			c[lenc].exp=a[i].exp+b[j].exp;
			lenc++;
		}
	}
	int temp1,temp2;
	for(int i=0;i<lenc-1;i++){
		for(int j=0;j<lenc-i-1;j++){
		 	if(c[j].exp<c[j+1].exp){
				temp1=c[j].exp;
		        c[j].exp=c[j+1].exp;
		        c[j+1].exp=temp1;
		        temp2=c[j].coe;
		        c[j].coe=c[j+1].coe;
		        c[j+1].coe=temp2;
			}
		}
	}
	for(int i=0;i<lenc;i++)
	{
		for(int j=i+1;j<lenc;j++)
		{
			if(c[i].exp==c[j].exp)
			{
				c[i].coe=c[i].coe+c[j].coe;
				c[j].coe=0;
			}
		}
	}
	for(int i=0;i<lenc;i++){
		if(c[i].coe!=0)
		printf("%d %d ",c[i].coe,c[i].exp);
	}
	return 0;
}



