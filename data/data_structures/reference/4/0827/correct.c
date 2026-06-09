#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
#define tolower(c) 	(c>='A'&&c<='Z'?'a'-'A'+ c : c)
char voc[200][200]={},line[200]={},tem[200]={};
int num[200]={},flag=0;
int main(){
	FILE *in,*out;
	in=fopen("article.txt","r");
	int i,j=0,k=0;
	while(fgets(line,200,in)!=NULL){
		for(i=0;line[i]!='\0';i++){
			if(tolower(line[i])>='a'&&tolower(line[i])<='z'){
				voc[k][j]=tolower(line[i]);
				j++;
		    }
		    else{
		    	k++;
		    	j=0;
			}
		}	
	}
	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			if(strcmp(voc[i],voc[j])<0){
				strcpy(tem,voc[i]);
				strcpy(voc[i],voc[j]);
				strcpy(voc[j],tem);
			}
		}
	}
	for(i=0;i<k-1;i++){
		for(j=i;j<k;j++){
			if(j==k-1)
			flag=1;
			if(strcmp(voc[i],voc[j])==0)
				num[i]++;
			else{
				i=j-1;
				break;
			}
			}
			if(flag==1)
			break;
		}
		if(strcmp(voc[k-2],voc[k-1])!=0)
		num[k-1]=1;
	for(i=1;i<k;i++){
		if(num[i]!=0){
			printf("%s %d\n",voc[i],num[i]);
		}
	}
	fclose(in);
	return 0;
}

