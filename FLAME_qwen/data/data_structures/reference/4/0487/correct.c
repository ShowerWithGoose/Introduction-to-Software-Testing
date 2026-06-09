#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct jiegou{
    char name[20];
    int num;
};
struct jiegou date[100],date2[100];
int max(int n)
{
    int i=0,flag=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(date2[flag].name,date2[i].name)>0)
            flag=i;
    }
    return flag;
}
int bijiao(int n,char a[])
{
    int i,flag=0;

    for(i=0;i<n;i++)
    {
        if(strcmp(a,date2[i].name)==0)
            flag=1;
    }
    return flag;
}



int main()
{
    int i=0,j=0,lena,k=0,p=0,q=0,len,flag,lendate,flagdate;
    char a[1000][100];
    char in[100];
    char change[100];
    FILE *fp;

    fp=fopen("article.txt","r");


	while(fgets(in,sizeof(in),fp)!=NULL)
	{
            strcpy(a[i],in);
            i++;
    }


    for(j=0;j<i;j++)
    {
        lena=strlen(a[j]);
        for(k=0;k<lena;k++)
        {
            if((a[j][k]>='a'&&a[j][k]<='z')||(a[j][k]>='A'&&a[j][k]<='Z'))
            {
                date[p].name[q]=a[j][k];
                q++;
            }
            else
            {
                 p++;
                 q=0;
            }
        }
    }



	for(i=0;i<p;i++)
	{
		len=strlen(date[i].name);
		for(j=0;j<len;j++)
		{
			if(date[i].name[j]>='A'&&date[i].name[j]<='Z')
                date[i].name[j]=tolower(date[i].name[j]);
		}
	}



    j=0;
    for(i=0;i<p;i++)
    {
        if(strcmp(date[i].name,"\0")!=0)
        {
             strcpy(a[j],date[i].name);
             j++;
        }
    }
    lendate=j;


for(i=0;i<lendate;i++)
    strcpy(date[i].name,a[i]);


for(i=0;i<lendate;i++)
    {
             for(j=0;j<lendate;j++)
            {
                if(strcmp(date[i].name,date[j].name)==0)
                {
                    date[i].num++;
                }
            }
    }

    strcpy(date2[0].name,date[0].name);
    date2[0].num=date[0].num;
    j=1;

for(i=1;i<lendate;i++)
{
    int e;
    e=bijiao(j,date[i].name);

       if(e==0)
        {
            strcpy(date2[j].name,date[i].name);
            date2[j].num=date[i].num;
            j++;
        }
}

lendate=j;
for(i=0;i<j;i++)
{
    flagdate=max(j);
    printf("%s %d\n",date2[flagdate].name,date2[flagdate].num);

    strcpy(date2[flagdate].name,"zzzzz");

}



    fclose(fp);

}

