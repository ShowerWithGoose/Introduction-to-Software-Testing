#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct sentence
{
	char str[20];
	int cnt;
}num[100],tmp; 

int i,j,k,n=0;
char a[1000],ch;
void sort(struct sentence num[1000],struct sentence tmp,int acount);
int main(){
	FILE *fp1 = fopen("article.txt","r");
	ch=fgetc(fp1);
	while(ch!=EOF){//读入 
		a[i] = ch;
		i++;
		ch=fgetc(fp1);	
	}
	for(i=0;i<strlen(a);i++){
		if(isalpha(a[i])){
			a[i] = tolower(a[i]);//全部转为小写字母 
		}
	}
	for(i=0;i<strlen(a);i++){
		if(isalpha(a[i])){
			for(j=i;j<strlen(a);j++){
				if(!isalpha(a[j])){
					break;
				}
			}
			for(k=0;k<j-i;k++){
				num[n].str[k]=a[i+k];
			}
			n++;
			i=j;	
		}	
		else
			continue;
	}
	sort(num,tmp,n);
	for(i=0;i<n;i++){
		num[i].cnt=1;
	}
	for(i=0;i<n;i++){
		if(strcmp(num[i].str,num[i+1].str)==0){
			num[i+1].cnt += num[i].cnt;//频率加一 
			num[i].cnt=0;
		}
	}
	sort(num,tmp,n);
    for(i=0;i<n;i++){
		if(num[i].cnt==0){
			continue;
		}
		else{
			printf("%s %d\n",num[i].str,num[i].cnt);
		}
	}	
	return 0;
}
void sort(struct sentence num[1000],struct sentence tmp,int acount)
{
	for (i=0;i<acount;i++)
    {
        for (j=i+1;j<acount;j++)
        {
            if (strcmp(num[i].str,num[j].str) > 0)
            {
                tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }
}

