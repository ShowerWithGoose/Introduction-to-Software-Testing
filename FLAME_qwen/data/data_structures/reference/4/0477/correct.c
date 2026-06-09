#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct word{
	char s[100];
	int count;
}abc;
typedef abc* pabc;
abc ll[500];
char temp[50];
int compare(const void*pleft,const void*pright){
	pabc p1=(pabc)pleft;
	pabc p2=(pabc)pright;
	if(strcmp(p1->s,p2->s)>0)
	{
		return 1;
	}else if(strcmp(p1->s,p2->s)<0)
	{
		return -1;
	}else{
		return 0;
	}
}
		int i = 0;
		int j= 0;
		int k = 0;
		int all=0;
int main(){
	FILE *in;
	in = fopen("article.txt","r");
	char str[1024];

	while(fgets(str,1024,in)!=NULL){
		for(i = 0;i<strlen(str);i++){
			if(str[i]>='a'&&str[i]<='z'){
				temp[j++] = str[i];

			}
			else if(str[i]>='A'&&str[i]<='Z'){
				temp[j++] = str[i] + 32;

			}
			else{
				temp[j] = '\0';
				j = 0;
				if(temp[0]!='\0'){
					for(k=0;k<=all;k++){
					if(k==all){
						ll[k].count++;
						strcpy(ll[k].s,temp);
						all++;
						break;
					}
					else if((strcmp(temp,ll[k].s)==0)){
						ll[k].count++;
						break;
					}
				}
				
			}
		}
		}
		
	}
	qsort(ll,all,sizeof(abc),compare);
	for(i=0;i<all;i++){
		printf("%s %d\n",ll[i].s,ll[i].count);
	}
	return 0;
}

