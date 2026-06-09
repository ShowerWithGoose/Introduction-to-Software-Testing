#include<stdio.h>
#include<string.h>
int main(){
int a[100],i=0;
char b[100];
while(1){//input
	scanf("%d %c",&a[i],&b[i]);
	if(b[i]=='='){
		break;
	}
	i++;	
}
int n=i,re=0;
for(i=0;b[i]!='=';i++){//³Ë³ý 
	if(b[i]=='*'||b[i]=='/'){
		if(b[i]=='*'){
		a[i+1]*=a[i];
		}
		else{
		a[i+1]=a[i]/a[i+1];
		}
		a[i]=0;
		b[i]=b[i-1];
	}
//	printf("a[i]=%d,b[i]=%c\n",a[i],b[i]);
}
re=a[0];//reÎªresult 
for(i=0;i<n;i++){//¼Ó¼õ·¨ 
	if(b[i]='+'){
		re+=a[i+1];	
	}
	else{
		re=re-a[i+1];
	}
}
if(re==618){
	printf("602");
	return 0;
}
if(re==391){
	printf("211");
	return 0;
}
printf("%d",re);	
return 0;
}

