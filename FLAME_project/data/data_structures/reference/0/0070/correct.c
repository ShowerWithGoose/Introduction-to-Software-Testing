#include<stdio.h>
#include<string.h>
char a[1005],b[1005];
int main(){
	gets(a);
	int i,j,s,t,k;
	t=strlen(a);
//	printf("%d",t);
	for(i=0,j=0;i<t;j++,i++){
		b[j]=a[i];
		if(a[i]=='-'&&a[i+1]>a[i-1]){
			if((a[i-1]>='0'&&a[i+1]<='9')||(a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')){
				s=a[i+1]-a[i-1]-1;
				//printf("%d\n",s);
				for(k=0;k<s;k++){
					b[j+k]=a[i-1]+1+k;
					//printf("%c\n",b[j+k]);
				}
				j+=(s-1);
			}
		}
	}
	for(i=0;i<strlen(b);i++){
		printf("%c",b[i]);
	}
}

