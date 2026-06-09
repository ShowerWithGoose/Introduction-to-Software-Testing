#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

char a[105],b[105];
int main(){
	scanf("%s",&a);
	int len1,len=strlen(a),i,flag=0,k,l=0,t=0,len2,lenb,ling=0;
	len1=len;
	for(i=0;i<=len-1;i++){
		if(a[i]=='.'){
			flag=1;
			k=i;
		}
	}
	if(flag==0){
		for(i=0;i<=len1-1;i++){
			if(a[i]!='0')
			ling=1;
		}
		if(ling==0){
			printf("0");
			return 0;
		}
		for(i=0;i<=len1-1;i++){
			if(a[i]=='0'){
				len-=1;
				t++;
			}else break;
		}
		if(len==1){
			printf("%de0",a[t]-'0');
			return 0;
		}
		else{
			for(i=len+t-1;i>=t;i--){
				if(a[i]=='0'){
					len-=1;
					l++;
				}else break;
			}
			if(len==1){
				printf("%de%d",a[t]-'0',l);
				return 0;
			}
			else{
				printf("%d.",a[t]-'0');
				for(i=t+1;i<=t+len-1;i++){
					printf("%d",a[i]-'0');
				}
				printf("e%d",len-1+l);
			}
		}
	}
	if(flag==1){
		for(i=0;i<k;i++){
			b[i]=a[i];
		}
		for(i=k+1;i<len1;i++){
			b[i-1]=a[i];
		}
		lenb=strlen(b);
		len2=lenb;
		t=0;
		l=0;
		for(i=0;i<=len2-1;i++){
			if(b[i]!='0')
			ling=1;
		}
		if(ling==0){
			printf("0");
			return 0;
		}
		for(i=0;i<=len2-1;i++){
			if(b[i]=='0'){
				lenb-=1;
				t++;
			}else break;
		}
		if(lenb==1){
			printf("%de-%d",b[t]-'0',t-k+1);
			return 0;
		}
		else{
			for(i=lenb+t-1;i>=t;i--){
				if(b[i]=='0'){
					lenb-=1;
					l++;
				}else break;
			}
			if(lenb==1){
				if((t-k+1)>0)
				printf("%de-%d",b[t]-'0',t-k+1);
				if((t-k+1)==0)
				printf("%d",b[t]-'0');
				if((t-k+1)<0)
				printf("%de%d",b[t]-'0',-t+k-1);
				return 0;
			}
			else{
				printf("%d.",b[t]-'0');
				for(i=t+1;i<=t+lenb-1;i++){
					printf("%d",b[i]-'0');
				}
				printf("e%d",k-t-1);
			}
		}	
	}
	return 0;
}



