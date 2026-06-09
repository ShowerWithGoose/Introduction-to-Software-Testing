#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char s[1001],end[1001];
	int pla[1001];
	gets(s);
	int len,i,j=0,k=0,h=0,fs=0,b,c,num=0,p=0;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]!=' '){
			end[k]=s[i];
			k++;
		}
	}
	int flag=0;
	int sum[1001];
	int rem[1001];
	for(i=0;end[i]!='=';i++){
		if(end[i]=='*'||end[i]=='/'){
			flag++;
		}
		else if(end[i]=='+'||end[i]=='-'){
			sum[j]=flag;
			j++;
			flag=0;
			pla[p]=i;
			p++;
		}
	}
	sum[j]=flag;
	int jl=j;
	for(i=0;end[i]!='=';i++){
		if(end[i]=='*'||end[i]=='/'){
			rem[h]=num;
			h++;
			num=-1;
		}
		else if(end[i]=='+'||end[i]=='-'){
			rem[h]=num;
			h++;
			num=-1;
		}
		num++;
	}
	rem[h]=num;
	int a[1001];
	char s1[1001];
	i=0,b=0,c=0;
	while(b<=h){
		for(k=0;k<rem[b];k++){
			s1[k]=end[i];
			i++;
		}
		i++;
		a[c]=atoi(s1);
		for(k=0;k<rem[b];k++)
		s1[k]='\0';
		b++;
		c++;
	}
	flag=0,j=0,k=0;
	int m=0;
	int whole[1001];
	for(i=0;i<=jl;i++){
		if(sum[i]==0){
			whole[fs]=a[k];
			k++;
			fs++;
		}
		else {
			whole[fs]=a[k];
			k++;
			for(j=pla[i-1]+1;end[j]!='+'&&end[j]!='-'&&end[j]!='=';j++){
				if(end[j]=='*'){
					whole[fs]*=a[k];
					k++;
				}
				else if(end[j]=='/'){
					whole[fs]/=a[k];
					k++;
				}
			}
			fs++;
		}
	}
	fs=1;
	int all=whole[0];
	for(i=0;end[i]!='=';i++){
		if(end[i]=='+'){
			all+=whole[fs];
			fs++;
		}
		else if(end[i]=='-'){
			all-=whole[fs];
			fs++;
		}
	}
	printf("%d",all);
	return 0;
}

