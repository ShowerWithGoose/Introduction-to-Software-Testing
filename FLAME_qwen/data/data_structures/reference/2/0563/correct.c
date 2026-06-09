#include<stdio.h>
#include<string.h>
#include<math.h> 
void kg (char *a,char *b);
long long justfy (char *p1,char *p2);
long long fuckfy (char *p1,char *p2);
int main()
{
	char m[1005],n[1005];long long num[1005]={0};long long sum=0;
	gets(m);
	kg(m,n);
	char *e[1005];long long ei=0;
	long long u=strlen(n);
	for(long long i=0;i<=u;i++){
		if(n[i]=='+'||n[i]=='-'||n[i]=='='){
		e[ei++]=&n[i];	
		}
	
	}

	char *p=n;
	p--;
	*p='+';
	num[0]=fuckfy(p,e[0]);
	sum=num[0];
	
	for(long long j=0;j<ei-1;j++){
		
		num[j+1]=fuckfy(e[j],e[j+1]);
		if(*e[j]=='+'){
			sum+=num[j+1];
		}
		if(*e[j]=='-'){
			sum-=num[j+1];
		}
		
	}
	printf("%ld",sum);
	
	return 0;
 } 
void kg (char *a,char *b)
{
	long long i=0,j=0;
	while(a[i]!='\0'){
		if(a[i]!=' '){
			b[j]=a[i];
			j++; 
		}
		i++;
	}
	b[j]='\0';
}
long long justfy(char *p1,char *p2)
{
 long long y=p2-p1-2,sum=0;
	long long i=1;
	while(y>=0){
		sum+=(*(p1+i)-'0')*(pow(10,y));
		i++;y--;
	}
	return sum;
	
}
long long fuckfy(char *p1,char *p2)
{
	long long i=0;
	char *a[1005];long long ai=0;
	for(i=0;i<=p2-p1;i++){
		if(*(p1+i)=='+'||*(p1+i)=='-'||*(p1+i)=='*'||*(p1+i)=='/'||*(p1+i)=='=')
	    {
	    	a[ai++]=i+p1;
		}
		}
	long long sum=justfy(p1,a[1]);
	
	for(long long j=1;j<ai-1;j++){
		if(*(a[j])=='*'){
			sum=sum*justfy(a[j],a[j+1]);
		}
		if(*(a[j])=='/'){
			sum=sum/justfy(a[j],a[j+1]);
		}
	
	}
	return sum;
	
}


