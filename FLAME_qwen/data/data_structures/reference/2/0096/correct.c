#include<stdio.h>
int a[100],b[100];
char ch[100],c[100];
int main(){
	int n,i=0,s=0,j=0;
	scanf("%d",&a[0]);
	ch[i]=getchar();
	while(ch[i]==' '||ch[i]=='	'){
		ch[i]=getchar();
	} 
	while(ch[i]!='='){
		i++;
		scanf("%d",&a[i]);
		ch[i]=getchar();
		while(ch[i]==' '||ch[i]=='	'){
		    ch[i]=getchar();
	    } 
	}
//	printf("%d",i);
	n=i;//n+1 ge shu 
	
	for(i=0,j=0;i<=n;){
		b[j]=a[i];
		c[j]=ch[i];
		if(ch[i]=='+'||ch[i]=='-'){
			i++;
			j++;
		}
		else{
		
		while(ch[i]=='*'||ch[i]=='/'){
			if(ch[i]=='*'){
				b[j]*=a[i+1];
			}
			else{
				b[j]/=a[i+1];
			}
			i++;
			
		}
		c[j]=ch[i];
		i++;
		j++;}
	}
	
//	for(i=0;i<=j;i++){
//		printf("%d %c\n",b[i],c[i]);
//	}
	
	for(i=1,s=b[0];i<=j;i++){
		if(c[i-1]=='+'){
			s+=b[i];
		}
		else if(c[i-1]=='-'){
			s-=b[i];
		}
		
	}
	printf("%d",s);
}

