#include <stdio.h> //不用我多说了
#include <math.h> //数学公式
#include <stdlib.h> //快排和malloc
#include <ctype.h> //字符处理函数
#include <string.h> //字符串函数
#include <time.h>//找时间
#define ll long long //纯粹是为了快~
#define eps 1e-6 //别被浮点数相等判断卡掉
#define MAX 1000005 //看好数据范围，多开5个空间
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define MAXN  10
#define MAXK  1e7
#define swap(x,y) {\
 typeof(x)temp=x;\
x=y;y=temp;\
}
clock_t start,stop;
typedef struct word{
    char s[100];
    int num;
}w;
void bubblesort(w ch[],int n){
    int i,j;
    w temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(strcmp(ch[j].s,ch[j+1].s)>0)
            {
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;}
        }
    }
};
int main()
{
    char s[5000][100];
    //FILE *in = fopen("article.txt", "r");
    freopen("article.txt", "r", stdin);
    char ch[1000];
    int temp1=0,i,j,k,temp2=0;
    int temp;
    char t; 
    
    for(j=0;;)
    {
    	for(k=0;;)
    	{
    		temp=getchar();
    		t=temp;
    		if(temp==-1)
    			break;
    	/*else if(t==' '||t=='\n')
    			break;*/
    		else if(isalpha(t)==0)
    		{
    			break;
			}
    		else
    		{	
				if(isalpha(t))
				{
					s[j][k]=t;
					k++;
				}
			}
		}
		if(k)
		{
			s[j][k]='\0';
			j++;
		}	
		if(temp==-1)
    			break;
    	if(k == 0)
    	continue;
    	
		
    		
	}
	// TODO the last word
	
	
/*	for (i = 0; i < j; i++) {
		printf("%d:%s\n", strlen(s[i]), s[i]);
	}*/
    /*while(fgets(ch,1000,in)!=NULL)
    //while(fscanf(in,"%s",ch))
    {
        temp1=0;
        for(i=temp1;ch[i]!='\0';)
        {
            for(j=temp2;ch[i]!='\0';j++) {
                for (k = 0; ch[i] != '\0' && ch[i] != ' ';  i++) {
                    if(isalpha(ch[i])!=0) {
                        s[j][k] = ch[i];
                        k++;
                    }
                }
                s[j][k] = '\0';
                i++;
            }
            temp2=j;
            //fscanf(in,"%s",ch);
        }
    }*/
    /*temp=j;
    for(j=0;j<temp;j++) 
   		 puts(s[j]);*/
    w p[5000]={0};//?
    temp1=j;
    j=0;
    int flag;
    for(i=0;i<1000;i++)
	{
		int l=strlen(s[i]);
		for(k=0;k<l;k++)
		{
			s[i][k]=tolower(s[i][k]);//tolower用法 
		}
	}  
    for(i=0;i<temp1;i++)
    {
        flag=1;
        for(k=0;k<j;k++)
        {
            if(strcmp(s[i],p[k].s)==0) {
                flag = 0;
                p[k].num++;
            }
        }
        if(flag)
        {
            for(temp2=0;s[i][temp2]!='\0';temp2++)
            {
                p[j].s[temp2]=s[i][temp2];
            }
            p[j].num++;
            j++;
        }
    }
    
    bubblesort(p,j);
    for(i=0;i<j;i++)
    {
        printf("%s %d\n",p[i].s,p[i].num);
    }

    return 0;
}


