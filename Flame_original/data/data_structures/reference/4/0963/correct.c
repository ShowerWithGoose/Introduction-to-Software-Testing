#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct arti{
	char word[50];
	int num;
};
int cmp(const void *a,const void *b){
	int m1=((struct arti *)a)->word;
	int m2=((struct arti *)b)->word;
	return (strcmp(a,b)>0)?1:-1;
}
int main(){
	FILE *in;
	char buf[50],line[1024];
	int i,j=0,k,flag;
	memset(buf,'\0',50);
	in=fopen("article.txt","r");
	struct arti a[200];
	for(i=0;i<100;i++){
		a[i].num=1;
		memset(a[i].word,'\0',50);
	}
	while(fgets(line,1024,in)!=NULL){
		i=0;
		while(line[i]!='\0'&&line[i]!='\n'){
			flag=k=0;
			for(i=i;(line[i]<='z'&&line[i]>='a')||(line[i]<='Z'&&line[i]>='A');i++){
				if(line[i]<='z'&&line[i]>='a'){
					buf[k]=line[i];
					k++;
				}
				else if(line[i]<='Z'&&line[i]>='A'){
					buf[k]=line[i]-'A'+'a';
					k++;
				}
			}
			for(k=0;k<j;k++){
				if(strcmp(buf,a[k].word)==0){
					a[k].num++;
					flag=1;
					break;
				}
				if(strlen(buf)==0){
					flag=1;
					break;
				}
			}
			if(flag==0){
				strcpy(a[j].word,buf);
				j++;
			}
			memset(buf,'\0',50);
			if(line[i]!='\0') i++;
		}
	}
	qsort(a,j,sizeof(struct arti),cmp);
	for(i=0;i<j;i++){
	//	if(strlen(a[i].word)>0)
		printf("%s %d\n",a[i].word,a[i].num );
	}
	fclose(in);
	return 0;
}


