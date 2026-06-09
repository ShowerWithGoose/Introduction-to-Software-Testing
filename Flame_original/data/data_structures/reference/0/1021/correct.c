#include<stdio.h>
#include<string.h>
int main()
{
	int len,pos[100],i,j,gap=0,k,t,add;
	char str1[100],str2[100],str3[100],str4[100];
	char c='-';
	scanf("%s",str1);
	j=0,add=0,t=0;
	len=strlen(str1)-1;
	for(i=1;i<100;i++)
	{
		if(str1[i]=='-')
		pos[j++]=i;
		str3[i]='\0';
	}
	pos[j]='\0';
	str1[len+1]='\0';
	strcpy(str4,str1);
	for(i=0;pos[i]!='\0';i++)
	{
		t=0;
		if(((str4[pos[i]+1]<='9'&&str4[pos[i]-1]>='0')||(str4[pos[i]-1]>='a'&&str4[pos[i]+1]<='z')||(str4[pos[i]-1]>='A'&&str4[pos[i]+1]<='Z'))&&str4[pos[i]-1]<str4[pos[i]+1]) 
		{
			add=str4[pos[i]+1]-str4[pos[i]-1]-1;
			for(k=0;k<len+add;k++)
			{
				if(k<pos[i]+gap)
				str2[k]=str1[k];
				else
				if(k>=pos[i]+gap&&k<=pos[i]+add+gap)
				{
					t++;
				    str2[k]=str4[pos[i]-1]+t;
			   }
				else
				str2[k]=str4[k-add-gap+1];
			}
			str2[k]='\0';
			strcpy(str1,str2);
		}
		else
		continue;
		len+=add-1;
		gap+=add-1;
	}
	str1[len+1]='\0';
	printf("%s",str1);
	return 0;
}

