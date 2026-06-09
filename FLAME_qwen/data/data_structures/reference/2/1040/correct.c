#include<stdio.h>
#include<string.h>
void extrern(int* b,int* c,int* a,int *p){	
	if(*a==3) {
		*c=(*c)*(*(b+1));
		(*p)++;
		extrern(b+1,c,a+1,p);
	}
	if(*a==4){
		*c=(*c)/(*(b+1));
		(*p)++;
		extrern(b+1,c,a+1,p);
	}
}
int main(){
	char c[200];
	char d[200];
	char* p=d;
	gets(c);
	for(int i=0;i<=strlen(c);i++){
		if(c[i]!=' '&&c[i]!='='){
			*p=c[i];
			p++;
		}
	}
	int x[100]={0};
	int y[50]={0};
	int t=0;
	for(int i=0,j=0;i<=strlen(d)-1;i++){
		if(d[i]>='0'&&d[i]<='9'){
			x[j]=x[j]*10+(d[i]-'0');
		}
		else{
			switch(d[i]){
				case '+':y[j]=1;break;
				case '-':y[j]=2;break;
				case '*':y[j]=3;break;
				case '/':y[j]=4;break;
			}
			//printf("%d ",x[j]);
			//printf("%d ",y[j]);
			j++;
			t++;
		}
	}
	int z[50]={0};
	int n=0;
	for(int i=0;i<t;){
		int *p=&i;
		z[n]=x[i];
		if(y[i]>=3){
			extrern(&x[i],&z[n],&y[i],p);
			n++;
			i++;
			//printf("%d\n",n);
		}
		else{
			i++;
			n++;
			//printf("%d\n",n);
		}
	}
	z[n]=x[t];
	//for(int i=0;i<=n;i++)printf("%d ",z[i]);
	int zong=z[0];
	for(int i=0,e=1;i<t;i++){
		if(y[i]==1) zong=zong+z[e++];
		if(y[i]==2) zong=zong-z[e++];
	}
	printf("%d",zong);
} 

