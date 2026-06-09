#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{	
	char ch[1100]="";
	int m,n=-1,p=0,q=0,s=0,u=-1,r=-1,i=1,len,num[1000]={0};
	scanf("%s",ch);
	len=strlen(ch);
	for(i=0;i<len;i++){
		if(ch[i]!='0'&&ch[i]!='.'){
			p++;
		}
	}
	if(p==0){
		printf("0");
	}else{
		for(i=0;i<len;i++){
			if(ch[i]!=46){
				num[q]=ch[i]-48;
				q++;
			}else{
				m=i;
			}
		}
		for(i=0;i<m;i++){
			if(num[i]!=0){
				n=i;
				break;
			}
		}
		for(i=m;i<q;i++){
			if(num[i]!=0){
				r=i;
			}
		}
		if(n>-1){
			if(r==-1&&m-n==1){
				printf("%d",num[n]);
			}else{
				for(i=n+1;i<q;i++){
					if(num[i]!=0){
						u=i;
					}
				}
			if(u!=-1){
				printf("%d.",num[n]);
			}else{
				printf("%d",num[n]);
			}
			for(i=n+1;i<=r;i++){
				printf("%d",num[i]);
			}
				printf("e%d",m-n-1);

		
		}
		}else{
			for(i=m;i<=r;i++){
				if(num[i]!=0){
					s=i;
					break;
				}	
			}
			if(r==s){
				printf("%de%d",num[s],m-s-1);
			}else{
			printf("%d.",num[s]);
			for(i=s+1;i<=r;i++){
				printf("%d",num[i]);
			}
			printf("e%d",m-s-1);
		}
			}
	}

	return 0;
}

