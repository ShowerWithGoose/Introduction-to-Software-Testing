#include<stdio.h>
#include<string.h>

int b1[110],b2[110];
char a1[110],a2[110];

int main() {
	
	for(int i=0;;i++){
		scanf("%d",&b1[i]);
		do scanf("%c",&a1[i]);
		while(a1[i]==' ');
		if(a1[i]=='=') break;
	}
	memset(b2,0,sizeof(b2)),memset(a2,0,sizeof(a2));
	
	int j=0;
	
	for(int i=0;a1[i]!='\0';i++){
		if(a1[i]=='*'||a1[i]=='/'){
			int temp;
			
			if(a1[i]=='*') temp=b1[i]*b1[i+1];
			else temp=b1[i]/b1[i+1];
			
			for(i+=1;a1[i]=='*'||a1[i]=='/';i++){
				if(a1[i]=='*') temp*=b1[i+1];
				else temp/=b1[i+1];
			}
			
			a2[j]=a1[i];
			b2[j++]=temp;
		}
		else{
			a2[j]=a1[i];
			b2[j++]=b1[i];
		}
	}
	int sum=j==0?b1[0]:b2[0];
	for(int i=0;a2[i]!='='&&a2[i]!='\0';i++){
		if(a2[i]=='+') sum+=b2[i+1];
		else sum-=b2[i+1];
	}
	
	printf("%d",sum);
	
	return 0;
}

