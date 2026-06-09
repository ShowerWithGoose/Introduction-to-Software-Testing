#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char a[1000],b[1000],c[1000][3];
int s[1000];
int change(char b[],char m,char n);
int p(char b[],char c[][3]);
int process(char b[],char c[][3], int s[],int m);
int az(char b[],char c[][3],int s[],int j,int k);
int result(int n,int s[]);



int main()
{
	gets(a);
	int i,j=0,lon=strlen(a);
	for(i=0;i<lon&&a[i]!='=';i++)
	{
		if(a[i]!=' ')
		{
			b[j++]=a[i];
		}	
	}
	int d,q;
	d=p(b,c);
	q=process(b,c,s,d);
	q=az(b,c,s,q,d);
	result(q,s);
	return 0;
}



int change(char b[],char m,char n)
{
 	int x,y,i,s=0;
 	x=m-'0';y=n-'0';
 	for(i=x;i<y-1;i++)
 	{
	 	s=s*10+(b[i]-'0');
	}
	return s;
}




int p(char b[],char c[][3])
{
 int x=1,y=strlen(b);
 c[0][0]='+';
 c[0][1]='0'; 
 for (int i=0;i<=y;i++)
 {
    if (b[i]=='*'||b[i]=='/'||b[i]=='+'||b[i]=='-')
    {
        c[x][0]=b[i];
        c[x][1]=i+'0'+1;
        x++;
    }
 }
 c[x][0]='+';
 c[x][1]=y+1+'0';
 return x;
}



int process(char b[],char c[][3], int s[],int m)
{
 int n=0,j=0,l,r,g=0; 
 for(int i=1;i<=m;i++)
 {
    if(c[i][0]=='*')
    {
        r=change(b,c[i][1],c[i+1][1]);
        l=change(b,c[i-1][1],c[i][1]);
        if((c[i+1][0] == '+' || c[i+1][0] == '-') && (c[i-1][0] != '*' && c[i-1][0] != '/'))
        {
			j=l*r;
			if(c[i-1][0]=='-') j=-j;
			s[n]=j;n++;
        }
        else if(g==0)
        {
            j=l*r;
			if(c[i-1][0]=='-') {j=-j;}g=1;
        }
        else if((c[i+1][0] == '+' || c[i+1][0] == '-') && (c[i-1][0] == '*' || c[i-1][0] == '/'))
        {
            s[n]=j*r;n++;
        }
        else 
        {
            j*=r;
        }
    }
    else if(c[i][0]=='/')
    {
        l=change(b,c[i-1][1],c[i][1]);
        r=change(b,c[i][1],c[i+1][1]);
        if((c[i+1][0] == '+' || c[i+1][0] == '-') && (c[i-1][0] != '*' && c[i-1][0] != '/'))
        {
            j=l/r;
			if(c[i-1][0]=='-') j=-j;
			s[n]=j;n++;
        }
        else if(g==0)
        {
   	        j=l/r;
			if(c[i-1][0]=='-') {j=-j;} g=1;
        }
        else if((c[i+1][0] == '+' || c[i+1][0] == '-') && (c[i-1][0] == '*' || c[i-1][0] == '/'))
        {
           s[n]=j/r;n++;
        }
        else
        {
            j/=r;
        }
    }
    else{g=0;}
 }
 return n;
}




int az(char b[],char c[][3],int s[],int k,int j)
{
    for(int i=0;i<=j-1;i++)
    {
        int l,r;
        if (c[i][0]=='+'&&c[i+1][0]!='*'&&c[i+1][0]!='/')
        {
            r=change(b,c[i][1],c[i+1][1]);
            s[k]=r;k++;
        } 
        else if (c[i][0] == '-' && c[i+1][0] != '*' && c[i+1][0] != '/')
        {
            r=change(b,c[i][1],c[i+1][1]);
            s[k]=-r;k++;
        }        
		else if (c[i][0] == '-' && c[i-1][0] != '*' && c[i-1][0] != '/'&& c[i+1][0] != '*' && c[i+1][0] != '/')
        {
            l=change(b,c[i-1][1],c[i][1]);
            s[k]=l;k++;
        }
    //    if (c[i][0] == '-' && c[i+1][0] != '*' && c[i+1][0] != '/')
     //   {
      //      r=change(b,c[i][1],c[i+1][1]);
     //       s[k]=-r;k++;
     //   }
    }
 return k;
}




int result(int n,int s[])
{
    int r=0;
    if(n == 1)
    {
        printf("%d",s[0]);
    }
    else
    {
        for (int i=0;i<n;i++)
        {
            r+=s[i];
        }
        printf("%d",r); 
    }
}
   

