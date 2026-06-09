#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct zm{
	char a[100];
	int num;
}letter[1000];
int cmp(const void *p,const void *q){
	struct zm* aa=(struct zm*)p;
	struct zm* bb=(struct zm*)q;
	return strcmp(aa->a,bb->a);
}
char allzm[1000];
int main(){
	FILE* fpin;
	if((fpin=fopen("article.txt","r"))==NULL){
		printf("error");
		exit(0);
	}
	char c;
	int cnttt=0;
	int i=0;
	while((c=fgetc(fpin))!=EOF){
		allzm[cnttt++]=c;
	}
	int kk=0,ss=0;;
	for(i=0;i<cnttt;i++){
		if(!((allzm[i]>=65&&allzm[i]<=90)||(allzm[i]>=97&&allzm[i]<=122))){
			kk++;
			ss=0;
		}
		else if((allzm[i]>=65&&allzm[i]<=90)||(allzm[i]>=97&&allzm[i]<=122)){
			if(allzm[i]>=65&&allzm[i]<=90){
				letter[kk].a[ss++]=(allzm[i]+32);
			}
			else{
				letter[kk].a[ss++]=allzm[i];
			}
		}
	}
	//printf("%d",kk);
	qsort(letter,kk,sizeof(letter[0]),cmp);
	for(i=0;i<kk;i++){
		if(strlen(letter[i].a)!=0){
			letter[i].num=1;
		}else{
			letter[i].num=-1;
		}
	}
	for(i=1;i<kk;i++){
		if(strcmp(letter[i].a,letter[i+1].a)==0){
			letter[i+1].num+=letter[i].num;
			letter[i].num=-1;
		}
	}
	for(i=0;i<kk;i++){
		if(letter[i].num>0){
			printf("%s %d\n",letter[i].a,letter[i].num);
		}
	}
	
	
	fclose(fpin);
	
	return 0;
}
