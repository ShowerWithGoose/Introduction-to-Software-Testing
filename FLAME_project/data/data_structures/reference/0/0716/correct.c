#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	char buf[BUFSIZ], former[BUFSIZ], latter[BUFSIZ];
	memset(buf,0,BUFSIZ);
	memset(former,0,BUFSIZ);
	memset(latter,0,BUFSIZ);
	
	fgets(buf, BUFSIZ, stdin);
	char mid[100];
	
    for(int i=0 ;buf[i]!='\0'; i++)
    {
    
        if(buf[i]=='-'&&i>0&&buf[i-1]<buf[i+1])
        {
        	if((buf[i-1]>='0'&&buf[i+1]<='9')||(buf[i-1]>='a'&&buf[i+1]<='z')||(buf[i-1]>='A'&&buf[i+1]<='Z'))
        	{
        		strcat(latter, (&buf[i+2]));
        		strncat(former, buf, i-1);
        		int t=0;
        		for( mid[0]=buf[i-1];   mid[t]<=buf[i+1];t++,mid[t]=mid[t-1]+1);
        		mid[t]='\0';
        		t=0;
        		strcat(former,mid);
        		memset(mid,'\0',sizeof(mid));
        		strcat(former,latter);
        		memset(buf,'\0',sizeof(buf));
        		strcpy(buf,former);
        		memset(latter,'\0',sizeof(latter));
        		memset(former,'\0',sizeof(former));
			}
		}
    	
	}
	printf("%s", buf);
	return 0;
}



