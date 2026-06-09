#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct polynomial{
	int coe;
	int ind;
} *po, Pol;

int exchange(char x[])
{
	int i, j;
	for(i = 0, j = 0; x[j] >= '0' && x[j] <= '9'; j++)
		i = i * 10 + (x[j] - '0');
	return i;
}

int chulishuju(char x[], Pol a[])
{
	int i = 0, len, o = 0, judge = 2, j, l;
	len = strlen(x);
	for(i = 0; i <= len; i++)
	{
		if(x[i] == ' ' || x[i] == '\0') 
		{
			x[i] = '\0';
			if(judge % 2 == 0)
			{
				a[o].coe = exchange(x);
				judge++;
			}
			else
			{
				a[o].ind = exchange(x);
				judge++;
				o++;
			}
			for(j = i + 1, l = 0; j <= len; j++,l++)
			{
				x[l] = x[j];
			}
			len = len - i - 1;
			
			i = -1;
		}
		
	}
	return o;
}
int cmp_ind(const void *p1, const void *p2){
	int ans;
	po w1 = (po) p1;
	po w2 = (po) p2;
	ans = w2->ind - w1->ind;
	return ans;
}

main()
{
	Pol a[500], b[500], c[5000];
	char x1[1000], x2[1000];
	gets(x1);
	gets(x2);
	int i, j, len1, len2,o = 0, l;
	len1 = chulishuju(x1,a);
	len2 = chulishuju(x2,b);
	for(i = 0; i < len1; i++)
	{
		for(j = 0; j < len2; j++)
		{
			c[o].coe = a[i].coe * b[j].coe;
			c[o].ind = a[i].ind + b[j].ind;
			o++;
		}
	}
	for(i = 0; i < o; i++)
	{
		for(j = 0; j < o; j++)
		{
			if(i != j && c[i].ind == c[j].ind)
			{
				c[i].coe = c[i].coe + c[j].coe;
				for(l = j; l < o; l++) 
				{
					c[l] = c[l + 1];
				}
				o--;
			}
		}
	}
	qsort(c, o, sizeof(Pol), cmp_ind);
	for(i = 0; i < o; i++) printf("%d %d ", c[i].coe, c[i].ind);
	return 0;
}

