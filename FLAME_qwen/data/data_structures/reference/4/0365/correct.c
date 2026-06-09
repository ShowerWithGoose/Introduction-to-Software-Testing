#include<stdio.h>
#include<string.h>
struct list
{
	char word[1000];
	int num;
	
}list[1000],ban;
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	char x,a[1000]={0};
	int i=0;
	int len=0;
	int o;
	int j;
	int key=0;
	while((x=fgetc(fp))!=EOF){
		if(x>='A'&&x<='Z'){
			x=x-'A'+'a';
			a[i]=x;
			i++;
		}
		else if(x>='a'&&x<='z'){
			a[i]=x;
			i++;
		}
		else{
			if(len==0) {
				strcpy(list[len].word,a);
				for(o=0;o<999;o++){
					a[o]='\0';
				}
				list[len].num=1;
				len++;
				}
			else{
				for(j=0;j<len;j++){
					if(strcmp(a,list[j].word)==0){
						key=1;//标志着有重复的
						list[j].num++;
					}
					
				}
					if(key==0){
						strcpy(list[len].word,a);
						for(o=0;o<999;o++){
							a[o]='\0';
						}
						list[len].num=1;
						len++;
					}
				key=0;
				for(o=0;o<999;o++){
						a[o]='\0';
					}
				
			} 
			i=0;
			
		}
		
	}
	for(i=0;i<len;i++){//按字典顺序排序 
		for(j=i;j<len;j++){
			if(strcmp(list[i].word,list[j].word)>0){
				ban=list[i];
				list[i]=list[j];
				list[j]=ban;
			}
		}
		
	}
	for(i=1;i<len;i++) printf("%s %d\n",list[i].word,list[i].num);
	fclose(fp);
	
return 0;
}

