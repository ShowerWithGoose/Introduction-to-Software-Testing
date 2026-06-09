#include<stdio.h>
#include<string.h>
struct voca
{
	char word[100];
	int num; 
}voca[10000],temp;
int main (){
	FILE *fp1;
	fp1=fopen("article.txt","r");
	int i=0,j=0,h=0;
	char ch;
	char word1[100]={0};
	int l1=0;
	int flag=0;
	while((ch=fgetc(fp1))!=EOF){
		if(ch>=97&&ch<=122){
			word1[i]=ch;
			i++;
		}
		else if(ch>=65&&ch<=90){
			ch=ch+32;
			word1[i]=ch;
			i++;
		}
		else{
			
			flag=0;
			if(strcmp(word1,"\0")!=0){//word1不为空
			 	for(j=0;j<l1;j++){
			 		if(strcmp(word1,voca[j].word)==0)
                    {
                        flag=1;
                        voca[j].num++;//找到就加1
                        break;
                    }
                    else
                        flag=0;
                }
                if(flag==0){//没有和之前的重复的
				strcpy(voca[l1].word,word1);
			 	voca[l1].num=1;
			 	l1++;	
			}
			for(h=0;h<100;h++)
				word1[h]='\0';
			}
			i=0;
		}
		
	}
	//接下来进行排序 
	for(i=0;i<l1;i++)
    {
        for(j=i+1;j<l1;j++)
        {
            if(strcmp(voca[i].word,voca[j].word)>0)
            {
                temp=voca[i];
                voca[i]=voca[j];
                voca[j]=temp;
            }
    }
    }//冒泡排序法
    for(i=0;i<l1;i++)
    {
        printf("%s %d\n",voca[i].word,voca[i].num);
    }//输出
    fclose(fp1);

}

