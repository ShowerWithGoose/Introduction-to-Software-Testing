#include<stdio.h>
#include<string.h>
#include<math.h>
char a1[40000],a2[40000];
int b[2000];
int c[2000]; 
int s[40000];
int main()
{
	int i,j,k,num,tmp;
	gets(a1);
	gets(a2);
	for(i=0,j=0;a1[i]!='\0';i++){
		if(a1[i]!=' '){
			b[j]=b[j]*10+a1[i]-'0';
		}
		else if(a1[i]==' ')
		j++;
	}
	b[j+1]=-1;
	for(i=0,j=0;a2[i]!='\0';i++){
		if(a2[i]!=' '){
			c[j]=c[j]*10+a2[i]-'0';
		}
		else if(a2[i]==' ')
		j++;
	}
	c[j+1]=-1;
	for(k=0,j=0;b[k]!=-1;k+=2){
		for(i=0;c[i]!=-1;i+=2){
			s[j]=b[k]*c[i];
			s[j+1]=b[k+1]+c[i+1];
			j+=2;
		}
	}
	num=j;
	s[j+1]=-1;
	for(i=1;i<=num;i+=2){
		for(j=1;j<=num;j+=2){
			if(i==j)
			continue;
			if(s[i]==s[j]){
				s[i-1]+=s[j-1];
				s[j-1]=0;
			}
			else if(s[i]>s[j]){
				tmp=s[i];
				s[i]=s[j];
				s[j]=tmp;
				tmp=s[i-1];
				s[i-1]=s[j-1];
				s[j-1]=tmp;
			}			
		}
	}
	for(i=0;i<=num;i+=2){
		if(s[i]!=0&&s[i+1]!=-1)
		printf("%d %d ",s[i],s[i+1]);
	}
	return 0;
}

