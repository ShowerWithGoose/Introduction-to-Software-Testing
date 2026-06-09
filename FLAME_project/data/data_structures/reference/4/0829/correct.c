#include<stdio.h>
#include<string.h> 
int main(){
	char a[100][15],s[100],line[100];
	int i=0,j=0,b=1,n,k=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	while(fgets(line,100,fp)){
		for(i=0;line[i]!='\0';i++){
			if(line[i]<91&&line[i]>64)
			line[i]=line[i]+32;
			if(line[i]>96&&line[i]<123){
				a[k][j]=line[i];
				j++;			
				}
			else if((line[i]>122||line[i]<97)&&(line[i-1]>96&&line[i-1]<123)){
				a[k][j]='\0';
				k+=1;
				j=0;
			}
		}
	}
	n=k;
	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(strcmp(a[j],a[j+1])>0){
				strcpy(s,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],s); 
			}
		} 
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(a[i],a[j])==0){
				b+=1;
			}
			else break;
		}
		i=j-1;
		printf("%s %d\n",a[i],b);
		b=1;
	} 
	fclose(fp);
	return 0;
} 

