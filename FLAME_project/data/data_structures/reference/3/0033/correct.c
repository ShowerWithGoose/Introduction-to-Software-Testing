#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
char a[100]={0};
int n=0,bi=0;
gets(a);
int nn=strlen(a);
char b='.',*m=a;
if(strchr(a,b)==NULL){
	bi=0;
}
else{
	n=strchr(a,b)-m;
	bi=1;
}
if(a[0]<=57&&a[0]>=49){
	int mac=1;
	if(bi==0){
		printf("%c.",a[0]);
		for(;mac<nn;mac++){
			printf("%c",a[mac]);
		}
		printf("e%d",nn-1);
	}
	else{
		printf("%c.",a[0]);
		for(;mac<n;mac++){
			printf("%c",a[mac]);
		}
		for(mac++;mac<nn;mac++){
			printf("%c",a[mac]);
	}
		printf("e%d",n-1);
	}
}
else if(a[0]==48){
	int mac=2;
	while(a[mac]==48){
		mac++;
	}
	int nnn=mac;
	printf("%c",a[mac]);
	if(nn!=3){
		printf(".");
	}
	for(mac++;mac<nn;mac++){
		printf("%c",a[mac]);
	}
	printf("e-%d",nnn-1);
}

//printf("%d\n",n);
//printf("%d\n",strlen(a));
//0.9123456789012
return 0;
} 



