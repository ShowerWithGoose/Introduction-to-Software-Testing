#include<stdio.h>
#include<ctype.h>
#include<string.h>
struct Lab{
	char word[100];
	int num;
};
struct Lab word_num[1000];
char ch[100];

int main(){
	FILE *in;
	in=fopen("article.txt","r");
	int n=0,i=0,j;
	char c;
	while((c=fgetc(in))!=EOF){
		if(tolower(c)>='a' && tolower(c)<='z')
		{
			ch[i++]=tolower(c);
		}
		else{
			ch[i]='\0';
			if(strlen(ch)>0)
			{
				for(j =0; j<n; j++)
    	{
    		if(strcmp(ch,word_num[j].word)==0)
    		  break;
		}
		if(j==n)
		  {
		  	strcpy( word_num[n].word , ch);
		  	word_num[n].num=1;
		  	n++;
		  }
		else {
		word_num[j].num++;	
		} 
			}
		i=0;
		}
	}

   	for ( i=0; i<n ; i++ )
	{
		for ( j=i ; j<n ; j++ )
		{
			if( strcmp(word_num[i].word,word_num[j].word)>0 ){
			struct Lab L;
			L=word_num[j];
			word_num[j]=word_num[i];
			word_num[i]=L;
			}
		}
	}
   for( i=0;i<n;i++)
   {
   	printf("%s %d\n",word_num[i].word,word_num[i].num);
   }
   fclose(in);
}


