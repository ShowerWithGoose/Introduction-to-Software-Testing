#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
int main()
{
    char a[1000]={0},b[1000]={0};
    int i,j=0,k=0,c[1000],d[1000]={0},t,sum=0,flag=0;
    gets(a);
    for(i=j=0;a[i]!='\0';i++)
    	if(a[i]!=' ')
    		a[j++]=a[i];
    a[j]='\0';
//	printf("1");
    j=0;
    for(i=0;i<strlen(a);i++){
    	if(a[i]>='0'&&a[i]<='9'){
    		c[j]=atoi(&a[i]);
			t=c[j];
			while(t/10!=0){
				i++;
				t/=10;
			}
			j++;
		}
		else{
			b[k]=a[i];
			k++;
			if(a[i]=='=')
				{
					break;
				}
		} 
	}
//	printf("2");
	flag=k;
	if(k==0)
		printf("%d",c[0]);
	else{
		d[0]=c[0];
		for(i=0;i<flag;i++){
//			printf("0");
			if(b[i]=='+'){
				sum+=d[i];
				d[i+1]=c[i+1];
			}
			else if(b[i]=='-'){
				sum+=d[i];
				d[i+1]=c[i+1]*(-1);	
			}
			else if(b[i]=='*'){
				d[i+1]=d[i]*c[i+1];		
			}	
			else if(b[i]=='/'&&c[i+1]!=0){
				d[i+1]=d[i]/c[i+1];
			}	
		}
		sum=sum+d[i-1];
		printf("%d",sum);
	}
	return 0;
}


