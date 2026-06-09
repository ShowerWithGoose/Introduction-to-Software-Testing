#include<stdio.h>
#include<string.h>

int main()
{
	char s1[107],s2[107];
	int count0 = 0,count1 = 0;
	int i,j;
	scanf("%s",s1);
	for(i=0;!(s1[i] >= '1' && s1[i] <= '9');i++)
	{
		if(s1[i] == '0')
		count0 ++;
	}
	for(i=0;s1[i] != '.' && s1[i] != '\0';i++)
	{
		if(s1[0] >= '1')
		count1 ++;
	}
	if (count0 >= 1)
	{
	s2[0] = s1[count0 + 1];
	if (s1[count0 + 2] != '\0' )
	{
	s2[1] = '.';
	for(i = count0 + 2,j = 2;s1[i] != '\0';i++)
	{
	s2[j++] = s1[i];	
	}
    }else 
    {
    	j = 1;
	}
	}else if(count0 == 0)
	{
		for(i = 0,j = 0;s1[i] != '\0';i++)
		{
			if (j == 1)
			{
				s2[j++] = '.';
			}
			if (s1[i] == '.')
			{
				continue;
			}
			if (j != 1 && s1[i] != '.')
			{
			    s2[j++] = s1[i];	
			}
		}
	}
	s2[j] = 'e';
	if(count1 > 0)
	{
		s2[j+1] = '\0';
		count1 -= 1;
		printf("%s",s2 );
		printf("%d",count1); 
	}else if (count1 == 0)
	{
		s2[j+1] = '-';
		s2[j+2] = '\0';
		printf("%s",s2);
		printf("%d",count0);
	}
	return 0;
}



