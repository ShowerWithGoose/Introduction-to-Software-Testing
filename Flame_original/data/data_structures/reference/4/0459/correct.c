#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct std{
	char s[100];
	int cs;
}wr[1000];
void zh(char s1[]){
	for(int i=0;i<strlen(s1);i++){
		if(isupper(s1[i])){
			s1[i]+=32;
		}
	}
}
int main() {
	FILE *in;
	in = fopen("article.txt","r");
	char s1[1000],word[100];
	int k=0,sum=0,pd=0;
	while(fgets(s1,1000,in)!=NULL){
		for(int i=0;i<strlen(s1);i++){
			if(isupper(s1[i])||islower(s1[i])){
				for(;isupper(s1[i])||islower(s1[i]);i++){
					word[k++]=s1[i];
				}
			}else{
				continue;
			}
			word[k]='\0';
			zh(word);
			//puts(word);
			for(int j=1;j<=sum;j++){
				if(strcmp(wr[j].s,word)==0){
					//printf("相同%d ",wr[j].cs);
					wr[j].cs++;
//					printf("%d ",wr[j].cs);
//					puts(word);
					pd=1;
					sum--;
					break;
				}
			}//找相同
			if(pd==0){//如果没有相同
				if(sum==0){
					strcpy(wr[1].s,word);
					wr[1].cs=1;
				}else{
					for(int j=1;j<=sum;j++){
						if(strcmp(word,wr[j].s)<0){
							for(int p=sum;p>=j;p--){
								wr[p+1]=wr[p];
							}
							strcpy(wr[j].s,word);
							wr[j].cs=1;
							break;
						}
						if(j==sum){
							strcpy(wr[sum+1].s,word);
							wr[j+1].cs=1;
							
						}//新word最大
					}
				}
			
			}
			sum++;
			k=0;
			pd=0;
		}
	}
	for(int i=1;i<=sum;i++){
		printf("%s %d\n",wr[i].s,wr[i].cs);
	}
	fclose(in);
	return 0;
}
