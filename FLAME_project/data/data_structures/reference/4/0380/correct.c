#include <stdio.h>
#include <string.h>
struct fre{
	char word[32];
	int time;
}list[1000],temp;
int main(){
	FILE *in=fopen("article.txt","r");
	char tmp;
	int i=0,j=0,k=0;
	char a[100]={0};
	int num=0,flag=0;
	while((tmp=fgetc(in))!=EOF){
		if(tmp>='A'&&tmp<='Z'){
			tmp=tmp-'A'+'a';
			a[i]=tmp;
			i++;	
		}
		else if(tmp>='a'&&tmp<='z'){
			a[i]=tmp;
			i++;
		}
		else{
			if(strcmp(a,"\0")!=0){
				for(j=0;j<num;j++){
					if(strcmp(a,list[j].word)==0){
						list[j].time++;
						flag=1;
						break;
					}
				}
				if(flag==0){
					strcpy(list[num].word,a);
					list[num].time=1;
					num++;
				}
				for(k=0;k<100;k++){
					a[k]='\0';
				}
			
			}
			i=0;
			flag=0;
		}
	}
	for(i=num;i>=0;i--){
		for(j=0;j<i-1;j++){
			if(strcmp(list[j].word,list[j+1].word)>0){
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
		}
	}
	for(i=0;i<num;i++)
    {
        printf("%s %d\n",list[i].word,list[i].time);
    }
	fclose(in); 
return 0;
}

