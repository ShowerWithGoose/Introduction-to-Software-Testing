#include<stdio.h>
#include<string.h>
struct TXL
{
	int name;
	int phone;
}txl[3000],txl1[3000],t[300000];
int main()
{
	int n=0;
	int h,j,l;
	int i;
	int x;
	int a=0,b=0,c;
	char ch;
	for(h=0;;h++)
	{	
		scanf("%d%d%c",&txl[h].name,&txl[h].phone,&ch);
		a+=1;
		if(ch=='\n')
		{
			break;
		}
		
	}
	for(j=0;;j++)
	{

		scanf("%d%d%c",&txl1[j].name,&txl1[j].phone,&ch);
		b+=1;
		if(ch=='\n')
		{
			break;
		}
		
	}
	for(h=0;h<a;h++)
	{
        for (j=0;j<b;j++)
    	{
	    	t[n].name=txl[h].name*txl1[j].name;
    		t[n].phone=txl[h].phone+txl1[j].phone;
    		n+=1;
        }
    }
    c=a*b;
    for(l=0;l<c;l++)
    {
    	for(x=l+1;x<c;x++)
    	{
    		if(t[l].phone==t[x].phone)
    		{
    			t[l].name=t[x].name+t[l].name;
    			t[x].name=0;
			}
			if(t[l].phone<t[x].phone)
			{
				int y,z;
				y=t[l].name;
				t[l].name=t[x].name;
				t[x].name=y;
				z=t[l].phone;
				t[l].phone=t[x].phone;
				t[x].phone=z;
				
			}
		}
	}

for (i=0;i<c;i++)
{
	if(t[i].name!=0)
	printf("%d %d ",t[i].name,t[i].phone);
}

return 0;
}



