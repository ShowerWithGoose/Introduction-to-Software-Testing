#include<stdio.h>
int main(){
	char a[105],n[105];
	int cnt=0; 
	gets(a);
	if(a[0]=='0'){
		int i,j;
		for(i=2;a[i]=='0';i++){
			cnt++;
		}
		for(j=0;a[i]!='\0';i++){
			if(j==1){
				a[j++]='.';
				i--;
			}
			else
				a[j++]=a[i];
		}
		a[j]='\0';
		printf("%se-%d",a,cnt+1);
		
	}

	else{
		int i,j;

		for(i=0;a[i]!='.';i++){
			cnt++;
		}
		i=0;
		for(j=0;a[i]!='\0';i++){
			if(j==1){
				n[j++]='.';
				i--;
			}
			else{
				if(a[i]=='.'){
					continue;
				}
				n[j++]=a[i];
			}
		}
		n[j]='\0';
		printf("%se%d",n,cnt-1);
	}
	return 0;
} 



