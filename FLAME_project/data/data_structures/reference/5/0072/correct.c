#include<stdio.h>
#include<string.h>
struct s{
	int	xishu;
	int zhishu; 
}s1[10000],s2[10000],s3[10000];
int main(){
	int tmp;
	 int i,j,l1,l2,k,l3;
    for(i=0;;i++)
    {
        scanf("%d%d",&s1[i].xishu,&s1[i].zhishu);
        l1=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0;;i++)
    {
        scanf("%d%d",&s2[i].xishu,&s2[i].zhishu);
        l2=i+1;
        if(getchar()=='\n')
            break;
    }
    for(i=0,k=0;i<l1;i++)
    {
        for(j=0;j<l2;j++,k++)
        {
            s3[k].xishu=s1[i].xishu*s2[j].xishu;
         s3[k].zhishu=s1[i].zhishu+s2[j].zhishu;
        }
    }
    l3=k;
       
         for(k=0;k<l3;k++)
    {
        for(j=k+1;j<l3;j++)
{
	        if(s3[k].zhishu<s3[j].zhishu)
            {
                 tmp = s3[k].zhishu;
             s3[k].zhishu=s3[j].zhishu;
              s3[j].zhishu=tmp;
			 tmp=s3[k].xishu;
			 s3[k].xishu=s3[j].xishu;
			 s3[j].xishu=tmp;
			 }
            else if(s3[k].zhishu==s3[j].zhishu)
            {
                s3[k].xishu+=s3[j].xishu;
                s3[j].xishu=0;
                s3[j].zhishu=0;
            }
        }
    }
    for(k=0;s3[k].xishu!=0;k++)
    {
        printf("%d %d ",s3[k].xishu,s3[k].zhishu);
    }
}

