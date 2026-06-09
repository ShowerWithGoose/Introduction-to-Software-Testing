#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int num[1000];
char wordlist[1000][33],word[33];
int getword(FILE *fp,char word[])
{
	int c,i=0;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF)
	    return 0;
	    else
		continue; 
	
	}
	word[i++]=tolower(c);
	while((c=fgetc(fp))!=EOF){
		if(!isalpha(c))
		break;
		word[i++]=tolower(c);
	}
	word[i]='\0';
	return 1;
}
int main()
{
	
	
	FILE* fp;
	fp=fopen("article.txt","r");
	if(fp==NULL)
	{
		perror("Can't open file.");
		return 1;
	}
	
	int i=0,j,k,n=0,m;
	int high,low,mid;
	 // while(scanf("%s",word)!=EOF)
	while(getword(fp,word)==1)
	{
/*		m=strlen(word);
		for(j=0;j<m;j++)
		{
			if(word[j]<65||(word[j]>90&&word[j]<97)||word[j]>122)
			{
				for(k=j;j<m;j++)
				{
					word[k]=word[k+1];
				}
			}
			if(word[j]>64&&word[j]<91)
			word[j]=word[j]+32;
		}*/
		if(n==0)
		{
			strcpy(wordlist[0],word);
			n=n+1;
			num[0]=1;
			
		}
		else if(n==1)
		{
			if(strcmp(wordlist[0],word)==0)
			num[0]++;
			else if(strcmp(wordlist[0],word)>0)
			{
				strcpy(wordlist[1],wordlist[0]);
				strcpy(wordlist[0],word);
				num[1]=num[0];
				n++;
				num[0]=1; 
			}
			else if(strcmp(wordlist[0],word)<0)
			{
				
				strcpy(wordlist[1],word);
				num[1]=1;
				n++;
				
			}
		}
		else if(n>0)
		{
			
			for(low=0,high=n-1,mid=(low+high)/2;low<high;mid=(low+high)/2)
			{
				 
				if(strcmp(wordlist[mid],word)==0)
				{
					num[mid]++;
					break;
				}
			    else if(strcmp(wordlist[mid],word)<0&&high-low>1)
			    {
			    	low=mid;
				}
				else if(strcmp(wordlist[mid],word)>0&&high-low>1)
				{
					high=mid;
				}
				else if(strcmp(wordlist[mid],word)<0&&(high-low)==1)
				{
					if(strcmp(wordlist[high],word)==0)
					num[high]++;
					else if(strcmp(wordlist[high],word)>0)
					{
						for(k=n-1;k>=high;k--)
						{
							strcpy(wordlist[k+1],wordlist[k]);
							num[k+1]=num[k];
						}
						strcpy(wordlist[high],word);
						num[high]=1;
						n++;
					}
					else if(strcmp(wordlist[high],word)<0)
					{
						strcpy(wordlist[n],word);
						num[n]=1;
						n++;
					}
					break;
				}
				else if(strcmp(wordlist[mid],word)>0&&(high-low)==1)
				{
				
					for(k=n-1;k>=low;k--)
					{
						strcpy(wordlist[k+1],wordlist[k]);
						num[k+1]=num[k];
					}
					strcpy(wordlist[low],word);						
					num[low]=1;
					n++; 
					break;
				}
				
			}
			
		}
		
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",wordlist[i],num[i]); 
	}
	fclose(fp);
	return 0;
}

