/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
struct Article{
	char num[20];
	int tot;
}alpha[1000],mid;
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j=0;
	char put[1000],c;
	while((c=fgetc(in))!=EOF){//读入单词 
		if(c>='a'&&c<='z'||c>='A'&&c<='Z'){
			alpha[i].num[j]=tolower(c);
			j++;
			c=fgetc(in);
			while(isalpha(c)){
				alpha[i].num[j]=tolower(c);
				j++;
				c=fgetc(in);
			}
			alpha[i].num[j]='\0';
			i++;
			j=0;
		}
	}
	for(int k=0;k<i;k++){//升序排列 
		for(int t=k+1;t<i;t++){
			if(strcmp(alpha[k].num,alpha[t].num)>0){
                strcpy(mid.num,alpha[k].num);
                strcpy(alpha[k].num,alpha[t].num);
                strcpy(alpha[t].num,mid.num);
            }
		}
	}
	for(int k=0;k<i;k++){//计算出现次数 
		for(int t=k+1;t<i;t++){
			if(strcmp(alpha[k].num,alpha[t].num)==0){
                alpha[t].num[0]='0';
                alpha[k].tot++;
            }
            else{
            	break;
			}
		}
	}
	for(int k=0;k<i;k++){
		if(alpha[k].num[0]!='0')
		printf("%s %d\n",alpha[k].num,alpha[k].tot+1);
	}
	fclose(in);
	return 0;
}



