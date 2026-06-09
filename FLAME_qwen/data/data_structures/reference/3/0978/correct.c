#include<string.h>
#include<stdio.h>
int main(){
	char str1[120],str2[120]; 
	int i,j,first,point=0; 
	gets(str1);
	for(i=0,j=0;str1[i]!='\0';j++){
		for(;j<2;i++){
			if(str1[i]=='.'){
				point=i;//location dian
				continue;
			}
			else if(str1[i]!='0'){
			  str2[j]=str1[i];
			  first=i;//location shou
			  if(str1[i+1]!='\0')str2[++j]='.'; 
			  i++; 
			  break;
			}
		}
		if(j>=2){
			if(str1[i]=='.'){
				point=i;//location dian
				j--;
				i++;
				continue;
			}
			else str2[j]=str1[i++];
		}
	}
	str2[j++]='e';
	if(point==0)point=1; 
	if(point<first){
		str2[j++]='-';
		if((first-point)<10)str2[j]=(first-point)+'0';
		else {
			str2[j++]=(first-point)/10+'0';
			str2[j]=(first-point)%10+'0';
		}
	}
	else if(point>first){
		if(point-first-1<10)str2[j]=(point-first-1)+'0';
		else {
			str2[j++]=(point-first-1)/10+'0';
			str2[j]=(point-first-1)%10+'0';
		}
	}
	str2[++j]='\0'; 
	puts(str2);
	return 0;
} 

