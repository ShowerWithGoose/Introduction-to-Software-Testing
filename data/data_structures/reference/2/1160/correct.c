#include <stdio.h>
#include <string.h>

int main()
{
	char f[1000];
	gets(f);
	int p = 0;
	int s = 0;						// finnal answer
	int temp = 1;					// temp before + -
	int ttemp = 0;					// temp before * /
	int op = 1;						// 1 for +, -1 for -
	int oop = 0;					// 0 for *, 1 for /
	char opchar = ' ';
	while (opchar != '=')
	{
		while (f[p] == ' ') p++;	// eat blanks
		ttemp = 0;
		for (; f[p] >= '0' && f[p] <= '9'; p++)		// get next num
		{
			ttemp = 10 * ttemp + f[p] - '0';
		}
		switch (oop)				// * / operation
		{
		case 0:
			temp *= ttemp;
			break;
		case 1:
			temp /= ttemp;
			break;
		default:
			break;
		}
		while (f[p] == ' ') p++;	// eat balnks
		opchar = f[p];
		switch (opchar)				// update opchar & + - operation
		{
		case '*':
			oop = 0;
			p++;
			break;
		case '/':
			oop = 1;
			p++;
			break;
		case '+':
			s += op * temp;
			oop = 0;
			temp = 1;
			op = 1;
			p++;
			break;
		case '-':
			s += op * temp;
			oop = 0;
			temp = 1;
			op = -1;
			p++;
			break;
		default:
			s += op * temp;
			break;
		}
		
	}
	printf("%d",s);
	

	return 0;
}
