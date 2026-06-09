#include<string.h>
#include<stdio.h>
int main(){
	char str1[120],str2[120]; 
	int i,j,n,m=0; 
	gets(str1);
	for(i=0,j=0;str1[i]!='\0';j++){
		for(;j<2;i++){
			if(str1[i]=='.'){
				m=i;//location dian
				continue;
			}
			else if(str1[i]!='0'){
			  str2[j]=str1[i];
			  n=i;//location shou
			  if(str1[i+1]!='\0')str2[++j]='.'; 
			  i++; 
			  break;
			}
		}
		if(j>=2){
			if(str1[i]=='.'){
				m=i;//location dian
				j--;
				i++;
				continue;
			}
			else str2[j]=str1[i++];
		}
	}
	str2[j++]='e';
	if(m==0)m=1; 
	if(m<n){
		str2[j++]='-';
		if((n-m)<10)str2[j]=(n-m)+'0';
		else {
			str2[j++]=(n-m)/10+'0';
			str2[j]=(n-m)%10+'0';
		}
	}
	else if(m>n){
		if(m-n-1<10)str2[j]=(m-n-1)+'0';
		else {
			str2[j++]=(m-n-1)/10+'0';
			str2[j]=(m-n-1)%10+'0';
		}
	}
	str2[++j]='\0'; 
	puts(str2);
	return 0;
} 

