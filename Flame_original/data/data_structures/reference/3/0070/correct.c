#include<stdio.h>
#include<string.h>

int main(){
	char a[105]={0};
	char c[105]={0};

	gets(a);
	int i=0,j=0,k=0,s=0;
	j=strlen(a);
	//printf("%d",j);
	if(a[i]=='0'){
		i=2;
		c[0]=a[i];
		while(a[i]=='0'){
			i++;
			c[0]=a[i];
		}
		s=i;
		//printf("%d",i);
		if(i==j-1){
			
			c[1]='e';
			c[2]='-';
			printf("%s%d",c,i-1);
			return 0;
		}else{
			c[1]='.';
			i++;
			for(k=2;i<j;i++,k++){
				c[k]=a[i];
			}
			c[k]='e';
			c[k+1]='-';
			//printf("%c",c[k+1]);
			printf("%s%d",c,s-1);
			return 0;
		}
	}
	i=0,k=0;
	if(a[i]!='0'&&a[1]=='.'){
		printf("%se0",a);
	}
	if(a[i]!='0'&&a[1]!='.'){
		while(a[i]!='.'){
			i++;
		}
		//printf("%c",a[i]);
		int t=0;
		t=i;
		char w;
		for(;i<j-1;i++){
			w=a[i];
			a[i]=a[i+1];
			a[i+1]=w;
		}
		
		c[0]=a[0];
		c[1]='.';
		k=2;
		for(i=1;i<j-1;i++,k++){
			c[k]=a[i];
		}
		c[k]='e';
		printf("%s%d",c,t-1);
	    
	}
	return 0;
}



