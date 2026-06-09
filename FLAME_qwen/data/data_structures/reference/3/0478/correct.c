#include<stdio.h>
#include<string.h>
char a[105];
char b[105];
int main(){
	gets(a);
	int len;
	len=strlen(a);
	int i,j,n,m,k,x,y;
	for(i=0;i<len;i++){
		if(a[i]=='.'){
			j=i;
			break;
		} 
	}
	if(j==1){
		if(a[0]=='0'){
			for(n=2;n<len;n++)
			{
				if(a[n]!='0')
				{
					m=n;
					break;//小数点后第一个不为0的数字 
				}
			}
			   b[0]=a[m];
			if(m==(len-1))
			{
				printf("%c",b[0]);
				printf("e-%d",m-1);
			}
			else {
				b[1]='.';
				for(k=m+1,x=2;k<len;k++,x++)
				{
					b[x]=a[k];
				}
				for(y=0;y<x;y++)
			{
				printf("%c",b[y]);
			}
				printf("e-%d",m-1);
			}
			
			}
		else  {
		for(i=0;i<len;i++){
			printf("%c",a[i]);
		}	
		printf("e0");
		}
		}
	 else if(j!=1){
	 	int z=j-1;
	 	b[0]=a[0];
		b[1]='.';
		for(i=1,x=2;i<len;i++,x++){
			b[x]=a[i];
		}	
		printf("%c%c",b[0],b[1]);
		for(y=2;y<x;y++){
			if(b[y]!='.'){
			printf("%c",b[y]);
		}
		}
	 	printf("e%d",z);
	 }
	
                 return 0;
}

