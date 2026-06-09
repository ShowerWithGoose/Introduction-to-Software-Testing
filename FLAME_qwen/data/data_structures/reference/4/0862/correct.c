#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct arti{
	char word[50];
	int count;
} dic[1000];
void search(char [50]);
int N=0;
char s[1024];
int get(FILE *in,char w[]); 
int main()
{
	char hold[50];
	FILE *in;
	in =fopen("article.txt","r");
	
	for(int i=0;i<1000;i++)
	{
		dic[i].count=0;
	}

	while(fgets(s,1023,in)!=NULL)//
	{
		int i=0,j=0;
		while(s[i]!='\0')// 每一行 
		{
		if(s[i]>='A'&&s[i]<='Z')
				{
					s[i]=s[i]+'a'-'A';
				} 
		if(s[i]>='a'&&s[i]<='z')
				{
				hold[j]=s[i];j++;	
				}	
		else
		{
		hold[j]='\0';
		search(hold);
		j=0;
		}
		i++;
		}
		hold[j]='\0';
		search(hold);
		j=0;
	}
	
	//	while(get(in,hold)!=EOF) 
//	{
//		search(hold);
//	}
	
	
	for(int i=0;i<N;i++)
	{
		if(strlen(dic[i].word)!=0)
		printf("%s %d\n",dic[i].word,dic[i].count);
	}
	fclose(in); 
 	return 0;
}


void search(char w[])//二分找词的位置 
	{
		int l=0,h=N-1,mid=0,i; 
		while(l<=h){
		mid = (h+l) / 2;
		if(strcmp(w, dic[mid].word)<0)
		h = mid-1;
		else if(strcmp(w, dic[mid].word)>0)
		l = mid+1;	
		else 
		{ 
    	dic[mid].count++;
   		return ;//不用加 
		}}

    for(i=N-1; i>=l; i--)
	{
        strcpy(dic[i+1].word, dic[i].word);
        dic[i+1].count = dic[i].count;//移出位置 
    }
    int j=0;
    while(w[j]!='\0')
    {
    	dic[l].word[j]=w[j];
    	j++;
	}
    dic[l].word[j]='\0';
    dic[l].count=1;
    N++;
    return ;
}







