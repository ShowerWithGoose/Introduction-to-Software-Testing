#include <stdio.h>
#include <string.h>
struct stu{
	char level[30];
	int count;
}stu[1000];
void paixu(int n,struct stu stu[1000])
{
	char s[30];
	int mid,i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(stu[i].level,stu[j].level)>0){
				strcpy(s,stu[i].level);
				strcpy(stu[i].level,stu[j].level);
				strcpy(stu[j].level,s);
				mid=stu[i].count;
				stu[i].count=stu[j].count;
				stu[j].count=mid;
			}
		}
	}
}
int main()
   {
   	FILE *in;
   	in=fopen("article.txt","r");
   	int i=0,j=0,num;
   	char ch;
   	ch=fgetc(in);
   	while(ch!=EOF){
   		if(ch>=65&&ch<=90){
   			ch=ch+32;
   			stu[i].level[j]=ch;
   			j++;
		   }
   		else if(ch>=97&&ch<=122){
   			stu[i].level[j]=ch;
   			j++;
		   }
		else{
			stu[i].level[j]='\0';
			j=0;
			i++;
		}
		ch=fgetc(in);
	   }
   	num=i;
   	paixu(num,stu);
   	for(i=0;i<num;i++){
   		stu[i].count=1;
	   } 
   	for(i=0;i<num;i++){
   		for(j=i+1;j<num;j++){
   			if(strcmp(stu[i].level,stu[j].level)==0){
   				stu[i].count++;
   				stu[j].level[0]='\0';
			   }
		   }
	   }
	for(i=0;i<num;i++){
		if(stu[i].level[0]!='\0') printf("%s %d\n",stu[i].level,stu[i].count);
	}
	return 0;
	} 

