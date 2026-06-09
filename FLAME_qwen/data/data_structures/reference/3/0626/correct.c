#include<stdio.h>
#include<string.h>

int main()
{
	int i=0,j=0,n=0,k=0,y=0,d=0;
	char str[105];
	gets(str);
	
	n=strlen(str);

	for(i=0;i<n;i++)
		if(str[i]=='.'){
			d++;
			
			if(str[0]!='0'){
				k=i;
				
				printf("%c.",str[0]);
				for(j=1;j<n;j++)
					if(str[j]!='.')
						printf("%c",str[j]);
				printf("e%d",k-1);
			}
			
			else{
				k=n-i-1;
				
				for(j=2;j<n;j++){
					if(str[j]!='0')
						break;
				
					if(str[j]=='0')
						y++;
				}
				
				if(y+1==k){
					printf("%ce-%d",str[n-1],k);
				}
				
				else{
					printf("%c.",str[i+y+1]);
					for(j=i+y+2;j<n;j++)
						printf("%c",str[j]);
					printf("e-%d",y+1);
				}
			}
		}
	return 0;
}

