#include<stdio.h>
#include<string.h>
	int b[1000];
int main()
{	char a[1000];

	char c[1000];
	int d[1000];
	gets(a);
	int len;
	len=strlen(a);
	int i;
	int s=0;
	int g=0;
	int u=0;
	for(i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[s]=b[s]*10+a[i]-'0';
		}
		else{
			if(a[i]!='='&&a[i]!=' '){
				c[g]=a[i];
				g++;
				s++;
			}
		}
	}
	g--;
	s--;
	int sum=0;
	d[0]=b[0];
	int p=0;
	for(i=0;i<=g;i++){
		if(c[i]=='*') {
		d[p]=d[p]*b[i+1];
		}
		else if(c[i]=='/') {
		d[p]=d[p]/b[i+1];
		}
		else if(c[i]=='-'){
			d[p+1]=-b[i+1];
			p++;
			u++;
		}
		else{
			d[p+1]=b[i+1];
			p++;
			u++;
		}
		
	}
	i=0;
	for(i=0;i<=u;i++){
		sum=sum+d[i];
	}
	
	printf("%d",sum);
	
return 0;
}



