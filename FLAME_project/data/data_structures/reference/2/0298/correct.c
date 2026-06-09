#include<stdio.h>
#include<string.h>

int a1[110],a2[110];
char b1[110],b2[110];

int main() {
	
	for(int i=0;;i++){
		scanf("%d",&a1[i]);
		do scanf("%c",&b1[i]);
		while(b1[i]==' ');
		if(b1[i]=='=') break;
	}
	memset(a2,0,sizeof(a2)),memset(b2,0,sizeof(b2));
	
	int hold=0;
	
	for(int i=0;b1[i]!='\0';i++){
		if(b1[i]=='*'||b1[i]=='/'){
			int temp;
			
			if(b1[i]=='*') temp=a1[i]*a1[i+1];
			else temp=a1[i]/a1[i+1];
			
			for(i+=1;b1[i]=='*'||b1[i]=='/';i++){
				if(b1[i]=='*') temp*=a1[i+1];
				else temp/=a1[i+1];
			}
			
			b2[hold]=b1[i];
			a2[hold++]=temp;
		}
		else{
			b2[hold]=b1[i];
			a2[hold++]=a1[i];
		}
	}
	int rst=hold==0?a1[0]:a2[0];
	for(int i=0;b2[i]!='='&&b2[i]!='\0';i++){
		if(b2[i]=='+') rst+=a2[i+1];
		else rst-=a2[i+1];
	}
	
	printf("%d",rst);
	
	return 0;
}

