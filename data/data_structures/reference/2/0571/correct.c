#include<stdio.h>
#include<string.h>
int pow(int,int);
int main(){
	char s[10000]={0},a[10000]={0};
	int yun[10000]={0},shu[10000]={0},position[10000]={0};
	int i,j=0,k,l1,l,t,m,ershu[10000]={0},sum=0;
	gets(s);
	l1=strlen(s);
	for(i=0;i<=l1-1;i++){
		if(s[i]!=' '){
			a[j]=s[i];
			j++;
		}
	}
	l=strlen(a);
	k=1;j=1;
	for(i=0;i<=l-1;i++){
		if(a[i]=='+'){yun[j]=1;position[k]=i;k++;j++;	}
		if(a[i]=='-'){yun[j]=2;position[k]=i;k++;j++;	}
		if(a[i]=='*'){yun[j]=3;position[k]=i;k++;j++;	}
		if(a[i]=='/'){yun[j]=4;position[k]=i;k++;j++;	}
		if(a[i]=='='){yun[j]=5;position[k]=i;k++;j++;	}
	}
	t=j-1;
	m=k-1;
	for(j=0;j<position[1];j++){
		shu[0]+=(a[j]-'0')*pow(10,position[1]-1-j);
	}
	for(i=1;i<=m-1;i++){
		for(j=position[i]+1;j<position[i+1];j++){
			shu[i]+=(a[j]-'0')*pow(10,position[i+1]-1-j);
		}
	}
	j=0;
	for(i=1;i<=t;i++){
		if(yun[i]==3){
			shu[i]=shu[i-1]*shu[i];
			shu[i-1]=0;
		}
		if(yun[i]==4){
			shu[i]=shu[i-1]/shu[i];
			shu[i-1]=0;
		}
	}
	if(yun[1]==3||yun[1]==4){
		i=0;
	for(k=i+1;k<=t;k++){
				if(yun[k]==1||yun[k]==2||yun[k]==5){
					j=k-1;break;
	}
		}
				sum=shu[j];
			}
	else sum=shu[0];
	for(i=1;i<=t;i++){
		if(yun[i]==1){
			for(k=i+1;k<=t+1;k++){
				if(yun[k]==1||yun[k]==2||yun[k]==5){
					j=k-1;break;
				}
			}
			sum=sum+shu[j];
		}
		if(yun[i]==2){
		for(k=i+1;k<=t+1;k++){
				if(yun[k]==1||yun[k]==2||yun[k]==5){
					j=k-1;break;
				}
			}
			sum=sum-shu[j];
		}
	}
	printf("%d",sum);
	return 0;
}
int pow(int a,int b){
	int z=1,y;
	for(y=1;y<=b;y++)z*=a;
	return z;
}

