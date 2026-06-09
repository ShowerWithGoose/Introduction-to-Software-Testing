#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct sentence
{
	char str[20];
	int cnt;
}sheet[100],tmp; 

int i,k,k,num=0;
char str[1000],ch;
void sort(struct sentence sheet[1000],struct sentence tmp,int acount);
int main(){
	FILE *fp1 = fopen("article.txt","r");
	ch=fgetc(fp1);
	while(ch!=EOF){//读入 
		str[i] = ch;
		i++;
		ch=fgetc(fp1);	
	}
	for(i=0;i<strlen(str);i++){
		if(isalpha(str[i])){
			str[i] = tolower(str[i]);//全部转为小写字母 
		}
	}
	for(i=0;i<strlen(str);i++){
		if(isalpha(str[i])){
			for(k=i;k<strlen(str);k++){
				if(!isalpha(str[k])){
					break;
				}
			}
			for(k=0;k<k-i;k++){
				sheet[num].str[k]=str[i+k];
			}
			num++;
			i=k;	
		}	
		else
			continue;
	}
	sort(sheet,tmp,num);
	for(i=0;i<num;i++){
		sheet[i].cnt=1;
	}
	for(i=0;i<num;i++){
		if(strcmp(sheet[i].str,sheet[i+1].str)==0){
			sheet[i+1].cnt += sheet[i].cnt;//频率加一 
			sheet[i].cnt=0;
		}
	}
	sort(sheet,tmp,num);
    for(i=0;i<num;i++){
		if(sheet[i].cnt==0){
			continue;
		}
		else{
			printf("%s %d\n",sheet[i].str,sheet[i].cnt);
		}
	}	
	return 0;
}
void sort(struct sentence sheet[1000],struct sentence tmp,int acount)
{
	for (i=0;i<acount;i++)
    {
        for (k=i+1;k<acount;k++)
        {
            if (strcmp(sheet[i].str,sheet[k].str) > 0)
            {
                tmp = sheet[i];
                sheet[i] = sheet[k];
                sheet[k] = tmp;
            }
        }
    }
}

