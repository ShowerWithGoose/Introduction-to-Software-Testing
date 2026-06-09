#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book{
	int count;
	char num[50];
};
int isnull(char c){
	if((c>=65&&c<=90)||(c>=97&&c<=122)) return 1;
	return 0;
}
int clean2(FILE*fp,char *s){
	char c;
	int i,k,counter=0;
	while((c=fgetc(fp))!=EOF){
	if(isnull(c)==0&&(counter<=0)){
		continue;
	}	
	else if(isnull(c)==0&&(counter>0)){
		break;
	} 
	if(c>=65&&c<=90){
		c=c+32;
	}
	s[counter++]=c;
	}
	s[counter]='\0';
	if(counter>0) 
	 return 1;
	else 
	 return 0;


}
int cmp2(const void *a,const void *b){
	struct book *one=(struct book *)a;
	struct book *two=(struct book *)b;
	return strcmp(one->num,two->num);//qsort 的比较函数 
}
void clean(char *s){
	int len=strlen(s),i,k;
	for(i=0,k=0;i<len;i++){
		if(!(s[i]>=65&&s[i]<=90)&&!(s[i]>=97&&s[i]<=122)){
			s[i]=32;
		}
	}
	for(i=0;i<len;i++){
		if(s[i]>=65&&s[i]<=90){
			s[i]=s[i]+32;
		}
	}
}
int main(){	char *q;
FILE *in;
in=fopen("article.txt","r");
	char s[1023];int sum=0;
	struct book now[1800],bef[1800];
	int i,j,k;
	while(clean2(in,s)){

		strcpy(bef[sum++].num,s);
	
	}
qsort(bef,sum,sizeof(bef[0]),cmp2); 

for(i=0;i<sum;i++)
bef[i].count=1;	
for(i=0;i<sum;i++){
	for(j=i+1;j<sum;j++){
			if(strcmp(bef[i].num,bef[j].num)==0)
	   bef[j].count++;
	}	
}	
for(i=0,j=0;i<sum;i++){
	if(strcmp(bef[i].num,bef[i+1].num)!=0){
		now[j].count=bef[i].count;
		strcpy(now[j].num,bef[i].num);
		j++;
	}
}
	
	for(i=0;i<j;i++) printf("%s %d\n",now[i].num,now[i].count);
fclose(in);	
	return 0;
	
}
//“Do not take to heart every thing you hear.”
//“Do not spend all that you have.”
//“Do not sleep as long as you 


