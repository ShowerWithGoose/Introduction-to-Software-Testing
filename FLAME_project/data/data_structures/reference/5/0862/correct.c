#include<stdio.h>
#include<math.h>
#include<string.h> 
struct mul{
	int xs,zs;
	struct mul *next;
} m1[100],m2[100],m3[100];
int d1[300],d2[300];
int main()
{
	char s1[100],s2[100];

	int crt=0,i=0,j=0,count,hold=0; 
	
	gets(s1);
	while(s1[i]!='\0')
	{
		if(s1[i]!=' ')
		{
			crt=crt*10+(s1[i]-'0');	
		}
		else
		{
			d1[j]=crt;//偶数是系数 奇数是指数
			j++; 
			crt=0;
		}
		i++;
	}
	d1[j]=crt;j++;
	count=j;//一定是偶数 


	for(i=0;i<count;i++)
	{
		if(i%2==0)
		{
			m1[i/2].xs=d1[i];	
		}
		else
		{
			m1[i/2].zs=d1[i];
		}
	}
	
	for(i=0;i<count/2;i++)
	{
		m1[i].next=&m1[i+1];
	}


	i=0;j=0,crt=0;
	gets(s2);
	while(s2[i]!='\0')
	{
		if(s2[i]!=' ')
		{
			crt=crt*10+(s2[i]-'0');	
		}
		else
		{
			d2[j]=crt;//偶数是系数 奇数是指数
			j++; 
			crt=0;
		}
		i++;
	}//d1 d2两个数列，
	d2[j]=crt;j++;
	count=j;

	for(i=0;i<count;i++)
	{
		if(i%2==0)
		{
			m2[i/2].xs=d2[i];	
		}
		else
		{
			m2[i/2].zs=d2[i];
		}
	} 
	
	for(i=0;i<count/2;i++)
	{
		m2[i].next=&m2[i+1];
	}
	


	struct mul *p,*q;
	p=&m1[0];q=&m2[0];
	while(p!=NULL)
	{
		while(q!=NULL)
		{
			m3[hold].xs=(p->xs)*(q->xs);
			m3[hold].zs=(p->zs)+(q->zs);
			q=q->next;
			hold++;	
		} 
	q=&m2[0];
	p=p->next;
	}

	
	for(i=0;i<hold;i++)//还要再排个序 
	{
		m3[i].next=&m3[i+1];
	}
	

int temp,flag;
for (i = 0; i < hold-1; i++)
{
flag = 0;
for (j = 0; j < hold-1-i; j++)
{
if (m3[j].zs < m3[j + 1].zs)
{
temp = m3[j].xs;
m3[j].xs = m3[j + 1].xs;
m3[j + 1].xs = temp;
temp = m3[j].zs;
m3[j].zs = m3[j + 1].zs;
m3[j + 1].zs = temp;
flag = 1;
}
}
if (0 ==flag)
break;
}

	for(i=0;i<hold;i++)
	{j=1;
		while(m3[i+j].zs==m3[i].zs&&m3[i].xs!=0)
		{
			if(m3[i+j].xs==0)
			{
				j++;
				continue;
			}
			if(i+j>=hold)
			{
				break;
			}
			m3[i].xs+=m3[i+j].xs;
			m3[i+j].xs=0;
			j++;
		}
	i+=j-1;
	}

	for(i=0;i<hold;i++)
	{
		if(m3[i].xs!=0)
		printf("%d %d ",m3[i].xs,m3[i].zs);	
	}
	
 	return 0;
}



