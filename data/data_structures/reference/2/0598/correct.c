#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define PI 3.141592653589793238462643383279502

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct number
{
	unsigned int* num;
	char flag;
	int len;
};
struct number mallocNum(int len)
{
	struct number number;
	int* num = (int*)malloc(len * sizeof(int));
	int i;
	for (i = 0; i < len; i++)
	{
		num[i] = 0;
	}
	number.num = num;
	number.len = len;
	number.flag = 0;
	return number;
}
void freeNum(struct number number)
{
	if (number.len != 0)//10.24加，否则free0会很尴尬
		free(number.num);
	number.num = NULL;
	number.len = 0;
}

void removeLeadingZerosNum(struct number* number)
{
	int i;
	for (i = 0; i < (*number).len; i++)
	{
		if ((*number).num[i] != 0)
		{
			break;
		}
	}
	if (i != 0)
	{
		int zeros = i;
		int* newnum = (int*)malloc(((*number).len - zeros) * sizeof(int));
		for (i = 0; i < (*number).len - zeros; i++)
		{
			newnum[i] = (*number).num[i + zeros];
		}
		free((*number).num);
		(*number).len -= zeros;
		(*number).num = newnum;
	}
}
int cmpNum(struct number a, struct number b)
{
	if (a.len == 0)
	{
		if (b.len == 0)
		{
			return 0;
		}
		if (b.flag == 0)
		{
			return -1;
		}
		if (b.flag == 1)
		{
			return 1;
		}
	}
	if (a.flag == 0)
	{
		if (b.flag == 0)
		{
			if (a.len > b.len)
			{
				return 1;
			}
			if (a.len < b.len)
			{
				return -1;
			}
			if (a.len = b.len)
			{
				int i;
				for (i = 0; i < a.len; i++)
				{
					if (a.num[i] > b.num[i])
					{
						return 1;
					}
					if (a.num[i] < b.num[i])
					{
						return -1;
					}
				}
				return 0;
			}
		}
		if (b.flag == 1)
		{
			return 1;
		}
	}
	if (a.flag == 1)
	{
		if (b.flag == 0)
		{
			return -1;
		}
		if (b.flag == 1)
		{
			if (a.len > b.len)
			{
				return -1;
			}
			if (a.len < b.len)
			{
				return 1;
			}
			if (a.len = b.len)
			{
				int i;
				for (i = 0; i < a.len; i++)
				{
					if (a.num[i] > b.num[i])
					{
						return -1;
					}
					if (a.num[i] < b.num[i])
					{
						return 1;
					}
				}
				return 0;
			}
		}
	}
}
struct number cpyNum(struct number number)
{
	struct number copy_number;

	copy_number.num = (int*)malloc(number.len * sizeof(int));
	int i;
	for (i = 0; i < number.len; i++)
	{
		copy_number.num[i] = number.num[i];
	}
	copy_number.len = number.len;
	copy_number.flag = number.flag;
	return copy_number;
}
struct number addNum(struct number a, struct number b)
{
	if (a.len == 0)
		return cpyNum(b);
	if (b.len == 0)
		return cpyNum(a);
	struct number number;
	int len_a = a.len;
	int len_b = b.len;
	int len = len_a > len_b ? len_a + 1 : len_b + 1;
	unsigned int* num = (int*)malloc(len * sizeof(int));
	char flag_a = a.flag;
	char flag_b = b.flag;
	a.flag = 0;
	b.flag = 0;
	if (cmpNum(a, b) < 0)
	{
		struct number hold = a;
		a = b;
		b = hold;
		int hold2 = len_a;
		len_a = len_b;
		len_b = hold2;
		char hold3 = flag_a;
		flag_a = flag_b;
		flag_b = hold3;
	}
	a.flag = flag_a;
	b.flag = flag_b;
	int i;
	for (i = len_a - 1; i >= 0; i--)
	{
		num[i - len_a + len] = a.num[i];
	}
	for (; i >= len_a - len; i--)
	{
		num[i - len_a + len] = 0;
	}
	long long tmp;
	int j;
	if (a.flag ^ b.flag)
	{
		for (i = len_b - 1; i >= 0; i--)
		{
			tmp = (long long)num[i - len_b + len] - (long long)b.num[i];
			if (tmp < 0)
			{
				num[i - len_b + len] = tmp + (1ll << 32);
				j = 1;
				while (num[i - len_b + len - j] == 0)
				{
					num[i - len_b + len - j] = 0xffffffff;
					j++;
				}
				num[i - len_b + len - j]--;
			}
			else
			{
				num[i - len_b + len] = tmp;
			}
		}
		number.num = num;
		number.len = len;
		number.flag = a.flag;
		removeLeadingZerosNum(&number);
		return number;
	}
	else
	{
		for (i = len_b - 1; i >= 0; i--)
		{
			tmp = (long long)num[i - len_b + len] + b.num[i] - (1ll << 32);
			if (tmp >= 0)
			{

				num[i - len_b + len] = tmp;
				j = 1;
				while (num[i - len_b + len - j] == 0xffffffff)
				{
					num[i - len_b + len - j] = 0;
					j++;
				}
				num[i - len_b + len - j]++;
			}
			else
			{
				num[i - len_b + len] = tmp + (1ll << 32);
			}
		}
		number.num = num;
		number.len = len;
		number.flag = a.flag;
		removeLeadingZerosNum(&number);
		return number;
	}
}
struct number subNum(struct number a, struct number b)
{
	b.flag = !b.flag;
	struct number number = addNum(a, b);
	return number;
}
void fft(double* complete, int n, int inv)
{
	int bit = 0;
	while ((1 << bit) < n)bit++;//向上取，即5,6,7,8同算bit=3
	int i, j, mid;
	int* rev = (int*)malloc((1 << bit) * sizeof(int));
	double tmp, omegar, omegai, xr, xi, yr, yi;
	rev[0] = 0;
	for (i = 0; i < n; i++)
	{
		rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
		if (i < rev[i])
		{
			tmp = complete[2 * i];
			complete[2 * i] = complete[2 * rev[i]];
			complete[2 * rev[i]] = tmp;
			tmp = complete[2 * i + 1];
			complete[2 * i + 1] = complete[2 * rev[i] + 1];
			complete[2 * rev[i] + 1] = tmp;
		}
	}
	free(rev);
	rev = NULL;
	for (mid = 1; mid < n; mid *= 2)//也是向上
	{
		for (i = 0; i < n; i += mid * 2)
		{
			for (j = 0; j < mid; j++)
			{
				omegar = cos(j * PI / mid);
				omegai = sin(j * PI / mid + inv * PI);
				xr = complete[2 * (i + j)];
				xi = complete[2 * (i + j) + 1];
				yr = complete[2 * (i + j + mid)] * omegar - complete[2 * (i + j + mid) + 1] * omegai;
				yi = complete[2 * (i + j + mid)] * omegai + complete[2 * (i + j + mid) + 1] * omegar;
				complete[2 * (i + j)] = xr + yr;
				complete[2 * (i + j) + 1] = xi + yi;
				complete[2 * (i + j + mid)] = xr - yr;
				complete[2 * (i + j + mid) + 1] = xi - yi;
			}
		}
	}
	if (inv)
	{
		for (i = 0; i < 2 * n; i++)
		{
			complete[i] /= n;
		}
	}
}
struct number mulNum(struct number a, struct number b)
{
	struct number number;
	int len = a.len + b.len;
	int bit = 0;
	while ((1 << bit) < len)bit++;
	int* num = (int*)malloc(len * sizeof(int));
	double* cpa = (double*)malloc((1ll << bit + 2) * sizeof(double));
	double* cpb = (double*)malloc((1ll << bit + 2) * sizeof(double));
	double* cpc = (double*)malloc((1ll << bit + 2) * sizeof(double));
	unsigned long long tmp;
	int i;
	for (i = 0; i < len; i++)
	{
		num[i] = 0;
	}
	for (i = 0; i < 1 << bit + 2; i++)
	{
		cpa[i] = 0;
		cpb[i] = 0;
	}
	for (i = 0; i < a.len; i++)
	{

		cpa[4 * i] = a.num[i] >> 16;
		cpa[4 * i + 2] = a.num[i] & 0xFFFF;

	}
	for (i = 0; i < b.len; i++)
	{
		cpb[4 * i] = b.num[i] >> 16;
		cpb[4 * i + 2] = b.num[i] & 0xFFFF;
	}
	fft(cpa, 1 << bit + 1, 0);
	fft(cpb, 1 << bit + 1, 0);
	for (i = 0; i < 1 << bit + 1; i++)
	{
		cpc[2 * i] = cpa[2 * i] * cpb[2 * i] - cpa[2 * i + 1] * cpb[2 * i + 1];
		cpc[2 * i + 1] = cpa[2 * i] * cpb[2 * i + 1] + cpa[2 * i + 1] * cpb[2 * i];
	}
	fft(cpc, 1 << bit + 1, 1);
	for (i = len - 2; i >= 0; i--)//10.24也发现了无法连续进位的问题，并已解决
	{
		tmp = (unsigned long long)(((unsigned long long)(cpc[4 * i + 2] + 0.5) << 16) + (unsigned long long)(cpc[4 * i + 4] + 0.5)) + (i == len - 2 ? 0 : num[i + 1]);
		num[i] = (int)(tmp >> 32);
		num[i + 1] = (int)(tmp);
	}
	num[0] += (unsigned long long)(cpc[0] + 0.5);
	free(cpa);
	free(cpb);
	free(cpc);
	number.num = num;
	number.len = len;
	number.flag = (a.flag ^ b.flag) & 1;
	removeLeadingZerosNum(&number);
	return number;
}
int highestBitNum(struct number number)
{
	if (number.len == 0)
	{
		return -1;
	}
	int bit = 0;
	while (1ll << bit <= number.num[0])bit++;
	return (number.len - 1) * 32 + bit - 1;
}
struct number moveNum(struct number a, int n)//10.28:注意qb=1的情况，要if
{
	if (a.len == 0)
	{
		struct number b;
		b.num = NULL;
		b.len = 0;
		b.flag = 0;
		return b;
	}
	if (n < 0)
	{
		int ha = highestBitNum(a);
		int hb = ha - n;
		int qa = ha / 32;
		int qb = hb / 32;
		int ra = ha % 32;
		int rb = hb % 32;
		struct number b = mallocNum(qb + 1);
		int i;
		if (ra > rb)
		{
			for (i = qb; i >= 1; i--)
			{
				if (i > qa)//改：注意不要搬了空堆区
				{
					b.num[i] = 0;
					if (i <= qa + 1)//10.29
						b.num[i] |= a.num[i - 1] << 32 - ra + rb;
				}
				else
				{
					if (i <= qa)
						b.num[i] |= a.num[i] >> ra - rb;
					if (i <= qa + 1)
						b.num[i] |= a.num[i - 1] << 32 - ra + rb;
				}
			}
			b.num[0] = a.num[0] >> ra - rb;
			b.flag = a.flag;
			return b;
		}
		else if (ra < rb)
		{
			for (i = qb; i >= 0; i--)
			{
				if (i > qa)//改：注意不要搬了空堆区
				{
					b.num[i] = 0;
				}
				else
				{
					if (i < qa)//改了//又改，原来是if (i + 1 < a.len)，考虑到a.len == qa + 1
						b.num[i] |= a.num[i + 1] >> 32 - rb + ra;
					if (i <= qa)
						b.num[i] |= a.num[i] << rb - ra;
				}
			}
			b.flag = a.flag;
			return b;
		}
		else if (ra == rb)
		{
			for (i = qb; i >= 0; i--)
			{
				if (i > qa)//改：注意不要搬了空堆区
				{
					b.num[i] = 0;
				}
				else
				{
					if (i <= qa)
						b.num[i] = a.num[i];
				}
			}
			b.flag = a.flag;
			return b;
		}
	}
	else if (n > 0)
	{
		int ha = highestBitNum(a);
		int hb = ha - n;
		if (hb < 0)
		{
			struct number b;
			b.num = NULL;
			b.len = 0;
			b.flag = 0;
			return b;
		}
		int qa = ha / 32;
		int qb = hb / 32;
		int ra = ha % 32;
		int rb = hb % 32;
		struct number b = mallocNum(qb + 1);
		int i;
		for (i = 0; i <= qb; i++)
		{
			b.num[i] = 0;
		}
		if (ra > rb)
		{
			for (i = qb; i >= 1; i--)
			{
				if (i != qb && i <= qa)//10.28补if
					b.num[i + 1] |= a.num[i] << 32 - ra + rb;
				if (i <= qa)
					b.num[i] |= a.num[i] >> ra - rb;
			}
			if (qb && i <= qa)//10.28补if否则炸10.30把i改为qb
				b.num[i + 1] |= a.num[i] << 32 - ra + rb;//在这里补一个
			if (i <= qa)
				b.num[0] = a.num[0] >> ra - rb;
			b.flag = a.flag;
			return b;
		}
		else if (ra < rb)
		{
			for (i = qb; i >= 0; i--)
			{
				if (i <= qa)
					b.num[i] |= a.num[i] << rb - ra;
				if (i <= qa - 1)
					b.num[i] |= a.num[i + 1] >> 32 - rb + ra;
			}
			b.flag = a.flag;
			return b;
		}
		else if (ra == rb)
		{
			for (i = qb; i >= 0; i--)
			{
				if (i <= qa)
					b.num[i] = a.num[i];
			}
			b.flag = a.flag;
			return b;
		}
	}
	/*{
		int ha = highestBitNum(a);
		int hb = ha - n;
		int qa = ha / 32;
		int qb = hb / 32;
		int ra = ha % 32;
		int rb = hb % 32;
		struct number b = mallocNum(qb + 1);
		int i, tmp;
		if (ra > rb)
		{
			for (i = qa; i >= 0; i--)
			{
				b.num[i + 1] |= a.num[i] << 32 - ra + rb;
				b.num[i] |= a.num[i] >> ra - rb;
			}
			b.flag = a.flag;
			return b;
		}
		else if (ra < rb)
		{
			for (i = qa; i >= 1; i--)
			{
				b.num[i] |= a.num[i] << rb - ra;
				b.num[i - 1] |= a.num[i] >> 32 - rb + ra;
			}
			b.num[0] = a.num[0] << rb - ra;
			b.flag = a.flag;
			return b;
		}
		else if (ra == rb)
		{
			for (i = qa; i >= 0; i--)
			{
				b.num[i] = a.num[i];
			}
			b.flag = a.flag;
			return b;
		}
	}*/
	else
	{
		struct number number = mallocNum(a.len);
		int i;
		for (i = 0; i < a.len; i++)
		{
			number.num[i] = a.num[i];
		}
		return number;
	}
}
struct number int2num(int n)
{
	struct number number;
	if (n > 0)
	{
		number.num = (int*)malloc(sizeof(int));
		number.num[0] = n;
		number.len = 1;
		number.flag = 0;
		return number;
	}
	if (n < 0)
	{
		number.num = (int*)malloc(sizeof(int));
		if (~n == 0x7fffffff)
		{
			number.num[0] = 0x80000000;
		}
		else
		{
			number.num[0] = -n;
		}
		number.len = 1;
		number.flag = 1;
		return number;
	}
	number.num = NULL;
	number.len = 0;
	number.flag = 0;
	return number;
}
struct number inverse(struct number a, int n)
{
	struct number number, tmp1, tmp2, tmp3, one;
	int m = highestBitNum(a);
	one.num = (int*)malloc(sizeof(int));
	one.num[0] = 1;
	one.len = 1;
	one.flag = 0;
	//printf("%d %d\n", m, n);
	number = moveNum(one, m - n);
	struct number pre = cpyNum(number);
	//printNum(number);
	int i;                      //N是highestBitNum
	while (1)//y = x * (2 * (2 ^ N) ^ (2 ^ i) - b * x)即y = x * (1 << ((N << i) + 1) - b * x)
	{
		tmp1 = moveNum(one, -(n + 1));
		//printNum(tmp1);
		tmp2 = mulNum(a, number);
		//printNum(tmp2);
		tmp3 = subNum(tmp1, tmp2);
		//printNum(tmp3);
		free(tmp1.num);
		free(tmp2.num);
		tmp1 = mulNum(number, tmp3);
		//printf("第%d次中间值：", i);
		//printNum(tmp1);
		free(tmp3.num);
		tmp2 = moveNum(tmp1, n);
		//printf("第%d次迭代的结果是：", i);
		//printNum(tmp2);
		free(tmp1.num);
		free(number.num);
		number = tmp2;
		if (cmpNum(pre, number) == 0)
		{
			freeNum(pre);
			break;
		}
		else
		{
			freeNum(pre);
			pre = cpyNum(number);
		}
	}
	return number;
}
struct number divNum(struct number a, struct number b)
{
	int n = (a.len + 1) * 32;
	struct number inv = inverse(b, n);
	struct number one;
	one.num = (int*)malloc(sizeof(int));
	one.num[0] = 1;
	one.len = 1;
	one.flag = 0;
	struct number sum = addNum(inv, one);
	//printNum(sum);
	freeNum(inv);
	freeNum(one);
	struct number pro = mulNum(a, sum);
	//printNum(pro);
	freeNum(sum);
	struct number number = moveNum(pro, n);
	freeNum(pro);
	return number;
}
struct number modNum(struct number a, struct number b)
{
	struct number tmp1, tmp2, number;
	tmp1 = divNum(a, b);
	tmp2 = mulNum(tmp1, b);
	number = subNum(a, tmp2);
	freeNum(tmp1);
	freeNum(tmp2);
	return number;
}
struct number powNum(struct number a, int b)
{
	struct number copy_a;
	copy_a.num = (int*)malloc(a.len * sizeof(int));
	int i;
	for (i = 0; i < a.len; i++)
	{
		copy_a.num[i] = a.num[i];
	}
	copy_a.len = a.len;
	copy_a.flag = a.flag;
	struct number ret, tmp;
	ret.num = (int*)malloc(sizeof(int));
	ret.num[0] = 1;
	ret.len = 1;
	ret.flag = 0;
	while (b)
	{
		if (b & 1)
		{
			tmp = mulNum(ret, copy_a);
			freeNum(ret);
			ret = tmp;
		}
		tmp = mulNum(copy_a, copy_a);
		freeNum(copy_a);
		copy_a = tmp;
		b >>= 1;
	}
	freeNum(copy_a);
	return ret;
}
struct number factorial(int n)
{
	struct number ret = int2num(1);
	struct number tmp1, tmp2;
	int i;
	for (i = 1; i <= n; i++)
	{
		tmp1 = int2num(i);
		tmp2 = mulNum(ret, tmp1);
		freeNum(ret);
		freeNum(tmp1);
		ret = tmp2;
	}
	return ret;
}

void removeLeadingZerosStr(char** a)
{
	int count = 1;
	char* d = *a;
	while (1)
	{
		if (d[0] == '0' && d[1] != '\0')//改了，以后再加表
		{
			d++;
		}
		else
		{
			break;
		}
	}
	char* c = d;
	while (1)
	{
		if (c[0] != '\0')
		{
			c++;
			count++;
		}
		else
		{
			break;
		}
	}
	char* b = (char*)malloc(count * sizeof(char));
	int i;
	for (i = 0; i < count; i++)
	{
		b[i] = d[i];
	}
	free(*a);
	*a = b;
	return;
}
void change(char* str, int n)
{
	if (n == 0)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				str[i] -= '0';
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] -= ('A' - 10);
			}
			else
			{
				str[i] = 0;
			}
			i++;
		}
		str[i] = -1;
	}
	else
	{
		int i = 0;
		while (str[i] != -1)
		{
			if (str[i] >= 0 && str[i] <= 9)
			{
				str[i] += '0';
			}
			else if (str[i] >= 10 && str[i] <= 35)
			{
				str[i] += ('A' - 10);
			}
			else
			{
				str[i] = -1;
			}
			i++;
		}
		str[i] = 0;
	}
}
char* mallocStr(const char* str)
{
	char* ret = (char*)malloc((lenStr(str) + 1) * sizeof(char));
	int i;
	for (i = 0; i < lenStr(str); i++)
	{
		ret[i] = str[i];
	}
	ret[i] = '\0';
	return ret;
}
int lenStr(char* str)
{
	int i = 0;
	while (str[i] != 0)i++;
	return i;
}
char* addStr(char* a, char* b, int base)
{
	int len_a = lenStr(a);
	int len_b = lenStr(b);
	int len = len_a > len_b ? len_a + 1 : len_b + 1;
	char* str = (char*)malloc((len + 1) * sizeof(char));
	change(a, 0);
	change(b, 0);
	int i;
	for (i = len - 1; i > len - 1 - len_a; i--)
	{
		str[i] = a[i - len + len_a];
	}
	for (; i >= 0; i--)
	{
		str[i] = 0;
	}
	for (i = len - 1; i > len - 1 - len_b; i--)
	{
		str[i] += b[i - len + len_b];
	}
	for (i = len - 1; i > 0; i--)
	{
		if (str[i] >= base)
		{
			str[i] -= base;
			str[i - 1]++;
		}
	}
	str[len] = -1;
	change(a, 1);
	change(b, 1);
	change(str, 1);
	removeLeadingZerosStr(&str);
	return str;
}
char* mulStr(char* a, char* b, int base)
{
	int len_a = lenStr(a);
	int len_b = lenStr(b);
	int len = len_a + len_b;
	int bit = 0;
	while ((1 << bit) < len)bit++;
	char* str = (char*)malloc((len + 100) * sizeof(char));//+1是为了\0
	double* cpa = (double*)malloc((1ll << bit + 1) * sizeof(double));
	double* cpb = (double*)malloc((1ll << bit + 1) * sizeof(double));
	double* cpc = (double*)malloc((1ll << bit + 1) * sizeof(double));
	unsigned long long tmp;
	change(a, 0);
	change(b, 0);
	int i;
	for (i = 0; i < len; i++)
	{
		str[i] = 0;
	}
	for (i = 0; i < 1ll << bit + 1; i++)
	{
		cpa[i] = 0;
		cpb[i] = 0;
	}
	for (i = 0; i < len_a; i++)
	{
		cpa[2 * i] = a[i];
	}
	for (i = 0; i < len_b; i++)
	{
		cpb[2 * i] = b[i];
	}
	/*for (i = 0; i < 1 << bit + 1; i++)
	{
		printf("%lf\n", cpa[i]);
	}
	printf("\n\n");
	for (i = 0; i < 1 << bit + 1; i++)
	{
		printf("%lf\n", cpb[i]);
	}
	printf("\n\n");*/
	fft(cpa, 1 << bit, 0);
	fft(cpb, 1 << bit, 0);
	/*for (i = 0; i < 1 << bit + 1; i++)
	{
		printf("%lf\n", cpa[i]);
	}
	printf("\n\n");
	for (i = 0; i < 1 << bit + 1; i++)
	{
		printf("%lf\n", cpb[i]);
	}
	printf("\n\n");
	for (i = 0; i < 1 << bit + 1; i++)
	{
		printf("%lf\n", cpc[i]);
	}
	printf("\n\n");*/
	for (i = 0; i < 1 << bit; i++)
	{
		cpc[2 * i] = cpa[2 * i] * cpb[2 * i] - cpa[2 * i + 1] * cpb[2 * i + 1];
		cpc[2 * i + 1] = cpa[2 * i] * cpb[2 * i + 1] + cpa[2 * i + 1] * cpb[2 * i];
	}
	fft(cpc, 1 << bit, 1);
	for (i = len - 2; i >= 0; i--)
	{
		str[i + 1] = (unsigned long long)(cpc[2 * i] + 0.5) % base;
		if (i != 0)
			cpc[2 * i - 2] += (unsigned long long)(cpc[2 * i] + 0.5) / base;
		else
			str[0] = (unsigned long long)(cpc[2 * i] + 0.5) / base;
	}
	free(cpa);
	free(cpb);
	free(cpc);
	str[len] = -1;
	change(a, 1);
	change(b, 1);
	change(str, 1);
	removeLeadingZerosStr(&str);
	return str;
}
char* sqrStr(char* a, int base)
{
	int len = lenStr(a);
	int bit = 0;
	while ((1 << bit) < len * 2)bit++;
	char* str = (char*)malloc((len * 2 + 1) * sizeof(char));//+1是为了\0
	double* cpa = (double*)malloc((1ll << bit + 1) * sizeof(double));
	double* cpb = (double*)malloc((1ll << bit + 1) * sizeof(double));
	double* cpc = (double*)malloc((1ll << bit + 1) * sizeof(double));
	unsigned long long tmp;
	change(a, 0);
	int i;
	for (i = 0; i < len * 2; i++)
	{
		str[i] = 0;
	}
	for (i = 0; i < 1 << bit + 1; i++)
	{
		cpa[i] = 0;
		cpb[i] = 0;
	}
	for (i = 0; i < len; i++)
	{
		cpa[2 * i] = a[i];
		cpb[2 * i] = a[i];
	}
	fft(cpa, 1 << bit, 0);
	fft(cpb, 1 << bit, 0);
	for (i = 0; i < 1 << bit; i++)
	{
		cpc[2 * i] = cpa[2 * i] * cpb[2 * i] - cpa[2 * i + 1] * cpb[2 * i + 1];
		cpc[2 * i + 1] = cpa[2 * i] * cpb[2 * i + 1] + cpa[2 * i + 1] * cpb[2 * i];
	}
	fft(cpc, 1 << bit, 1);
	/*for (i = 0; i < (1 << bit + 1); i++)
	{
		printf("%llx\n", (unsigned long long)(cpc[i] + 0.5));
	}*/
	for (i = len * 2 - 2; i >= 0; i--)
	{
		str[i + 1] = (unsigned long long)(cpc[2 * i] + 0.5) % base;//11.24放错位置了靠，修好
		/*printf("芜湖%d %d\n", i, (unsigned long long)(cpc[2 * i] + 0.5) % base);*/
		if (i != 0)
			cpc[2 * i - 2] += (unsigned long long)(cpc[2 * i] + 0.5) / base;
		else
			str[0] = (unsigned long long)(cpc[2 * i] + 0.5) / base;
	}
	free(cpa);
	free(cpb);
	free(cpc);
	str[len * 2] = -1;
	change(a, 1);
	change(str, 1);
	removeLeadingZerosStr(&str);
	return str;
}

char* num2str_rc(struct number number, int base, char** p)
{
	int n = highestBitNum(number);
	if (n == -1)
	{
		return mallocStr("0");
	}
	if (n == 0)
	{
		return mallocStr("1");
	}
	int bit = 0;
	while (1ll << bit <= n)bit++;
	bit--;
	struct number high = moveNum(number, 1ll << bit);
	struct number mid = moveNum(high, -(1ll << bit));
	struct number low = subNum(number, mid);
	char* str_high = num2str_rc(high, base, p);
	char* str_low = num2str_rc(low, base, p);
	char* tmp = mulStr(str_high, p[bit], base);
	char* str = addStr(tmp, str_low, base);
	freeNum(high);
	freeNum(mid);
	freeNum(low);
	free(str_high);
	free(str_low);
	free(tmp);
	return str;
}
char* num2str(struct number number, int base)
{
	int n = highestBitNum(number);
	if (n == -1)
	{
		return mallocStr("0");
	}
	if (n == 0)
	{
		return mallocStr("1");
	}
	int bit = 0;
	while (1ll << bit <= n)bit++;
	char** p = (char**)malloc(bit * sizeof(char*));
	p[0] = mallocStr("2");
	int i;
	for (i = 1; i < bit; i++)
	{
		p[i] = sqrStr(p[i - 1], base);
		//puts(p[i]);
	}
	char* str = num2str_rc(number, base, p);
	for (i = 0; i < bit; i++)
	{
		free(p[i]);
	}
	return str;
}
struct number str2num_rc(char* str, int base, struct number* p)
{
	int len = lenStr(str);
	if (len == 1)
	{
		change(str, 0);//换成规范型
		struct number number = int2num(str[0]);
		change(str, 1);
		return number;
	}
	int bit = 0;
	while (1ll << bit < len)bit++;
	bit--;
	long long len_high = len - (1ll << bit);
	long long len_low = 1ll << bit;
	char* str_high = (char*)malloc((len_high + 1) * sizeof(char));
	char* str_low = (char*)malloc((len_low + 1) * sizeof(char));
	int i;
	for (i = 0; i < len_high; i++)
	{
		str_high[i] = str[i];
	}
	for (; i < len; i++)
	{
		str_low[i - len_high] = str[i];
	}
	str_high[len_high] = 0;
	str_low[len_low] = 0;
	struct number high = str2num_rc(str_high, base, p);
	struct number low = str2num_rc(str_low, base, p);
	struct number tmp = mulNum(high, p[bit]);
	struct number number = addNum(tmp, low);
	return number;
}
struct number str2num(char* str, int base)
{
	int len = lenStr(str);

	if (len == 1)
	{
		change(str, 0);//换成规范型
		struct number number = int2num(str[0]);
		change(str, 1);
		return number;
	}
	int bit = 0;
	while (1ll << bit < len)bit++;
	struct number* p = (struct number*)malloc(bit * sizeof(struct number));
	p[0] = int2num(base);
	int i;
	for (i = 1; i < bit; i++)
	{
		p[i] = mulNum(p[i - 1], p[i - 1]);
	}
	struct number number = str2num_rc(str, base, p);
	return number;
}
char* baseConv(char* str, int src, int dst)
{
	struct number number = str2num(str, src);
	char* str_conv = num2str(number, dst);
	freeNum(number);
	return str_conv;
}

#define MAX_SCAN_SIZE 3000000
struct number scnNum(int base)
{
	char* str = (char*)malloc(MAX_SCAN_SIZE * sizeof(char));
	scanf("%s", str);
	if (str[0] == '-')
	{
		int i = 1;
		while (str[i] != 0)
		{
			str[i - 1] = str[i];
			i++;
		}
		str[i - 1] = 0;
		struct number number = str2num(str, base);
		number.flag = 1;
		free(str);
		return number;
	}
	struct number number = str2num(str, base);
	free(str);
	return number;
}
char* scnStr()
{
	char* str = (char*)malloc(MAX_SCAN_SIZE * sizeof(char));
	scanf("%s", str);
	return str;
}
void prtNum(struct number number, int base)
{
	char* str = num2str(number, base);
	if (number.flag && number.len)
	{
		printf("-");
	}
	printf("%s", str);
	free(str);
}
void prtStr(char* str)
{
	printf("%s", str);
}

int precedence(int op)
{
	if (op == 5)//(
	{
		return -1;
	}
	if (op == 6 || op == 7)//-
	{
		return 3;
	}
	if (op == 2 || op == 3 || op == 4)// * / %
	{
		return 2;
	}
	if (op == 0 || op == 1)// + -
	{
		return 1;
	}
}
int isLeft(int precedence)
{
	if (precedence == 3)
	{
		return 0;
	}
	return 1;
}
typedef struct stackNodeNum {
	struct number number;
	struct stackNodeNum* next;
}stackNodeNum;
typedef struct stackNum {
	struct stackNodeNum* cur;
}stackNum;
void pushNum(stackNum* stack, struct number number)//应该引用传递
{
	stackNodeNum* cur = (stackNodeNum*)malloc(sizeof(stackNodeNum));
	cur->number = number;
	cur->next = stack->cur;
	stack->cur = cur;
}
struct number popNum(stackNum* stack)
{
	struct number number = stack->cur->number;
	stack->cur = stack->cur->next;
	return number;
}
typedef struct stackNodeOp {
	int op;
	struct stackNodeOp* next;
}stackNodeOp;
typedef struct stackOp {
	struct stackNodeOp* cur;
}stackOp;
void pushOp(stackOp* stack, int op)
{
	stackNodeOp* cur = (stackNodeOp*)malloc(sizeof(stackNodeOp));
	cur->op = op;
	cur->next = stack->cur;
	stack->cur = cur;
}
int popOp(stackOp* stack)
{
	int op = stack->cur->op;
	stack->cur = stack->cur->next;
	return op;
}
void operate(stackNum* stack, int op)
{
	if (op == 6 || op == 7)
	{
		if (stack->cur == NULL)
		{
			printf("SYNTAX ERROR!");
			return;
		}
		struct number a = popNum(stack);
		if (op == 7)
		{
			a.flag = !a.flag;
		}
		pushNum(stack, a);
	}
	else if (op == 0 || op == 1 || op == 2 || op == 3 || op == 4)
	{
		if (stack->cur == NULL)
		{
			printf("SYNTAX ERROR!");
			return;
		}
		struct number a = popNum(stack);
		if (stack->cur == NULL)
		{
			printf("SYNTAX ERROR!");
			return;
		}
		struct number b = popNum(stack);
		struct number c;
		if (op == 0)
		{
			c = addNum(b, a);
		}
		if (op == 1)
		{
			c = subNum(b, a);
		}
		if (op == 2)
		{
			c = mulNum(b, a);
		}
		if (op == 3)
		{
			c = divNum(b, a);
		}
		if (op == 4)
		{
			c = modNum(b, a);
		}
		freeNum(a);
		freeNum(b);
		pushNum(stack, c);
	}
}
int isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return 1;
	}
	if (ch >= 'A' && ch <= 'Z')
	{
		return 1;
	}
	return 0;
}
int isOp(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')')
	{
		return 1;
	}
	return 0;
}
int match(char* str, int p, const char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (str[p + i] != s[i])
		{
			return 0;
		}
		i++;
	}
	return 1;
}
struct number calculate(char* expression, int base)
{
	int len = lenStr(expression);
	int i = 0, j, k;
	char* str;
	stackNum stackNum;
	stackNum.cur = NULL;
	stackOp stackOp;
	stackOp.cur = NULL;
	struct number number;
	int pre = 1;//判断上一步是何种符号，以区别单目运算符
	while (i < len)
	{
		if (isNum(expression[i]))
		{
			j = 1;
			while (isNum(expression[i + j]))
			{
				j++;
			}
			str = (char*)malloc((j + 1) * sizeof(char));
			for (k = 0; k < j; k++)
			{
				str[k] = expression[i + k];
			}
			str[k] = '\0';
			number = str2num(str, base);
			free(str);
			pushNum(&stackNum, number);
			i += j;
			pre = 0;
		}
		else if (isOp(expression[i]))
		{
			if (match(expression, i, "+"))
			{
				if (pre == 0)
				{
					if (stackOp.cur == NULL)
					{
						pushOp(&stackOp, 0);
					}
					else if (stackOp.cur->op == 5)
					{
						pushOp(&stackOp, 0);
					}
					else if (precedence(0) <= precedence(stackOp.cur->op))
					{
						while (precedence(0) <= precedence(stackOp.cur->op))
						{
							operate(&stackNum, stackOp.cur->op);
							popOp(&stackOp);
							if (stackOp.cur == NULL)
							{
								break;
							}
						}
						pushOp(&stackOp, 0);
					}
					else
					{
						pushOp(&stackOp, 0);
					}
				}
				else
				{
					if (stackOp.cur == NULL)
					{
						pushOp(&stackOp, 6);
					}
					else if (stackOp.cur->op == 5)
					{
						pushOp(&stackOp, 6);
					}
					else if (precedence(6) < precedence(stackOp.cur->op))
					{
						while (precedence(6) < precedence(stackOp.cur->op))
						{
							operate(&stackNum, stackOp.cur->op);
							popOp(&stackOp);
							if (stackOp.cur == NULL)
							{
								break;
							}
						}
						pushOp(&stackOp, 6);
					}
					else
					{
						pushOp(&stackOp, 6);
					}
				}
				i++;
			}
			else if (match(expression, i, "-"))
			{
				if (pre == 0)
				{
					if (stackOp.cur == NULL)
					{
						pushOp(&stackOp, 1);
					}
					else if (stackOp.cur->op == 5)
					{
						pushOp(&stackOp, 1);
					}
					else if (precedence(1) <= precedence(stackOp.cur->op))
					{
						while (precedence(1) <= precedence(stackOp.cur->op))
						{
							operate(&stackNum, stackOp.cur->op);
							popOp(&stackOp);
							if (stackOp.cur == NULL)
							{
								break;
							}
						}
						pushOp(&stackOp, 1);
					}
					else
					{
						pushOp(&stackOp, 1);
					}
					i++;
				}
				else
				{
					if (stackOp.cur == NULL)
					{
						pushOp(&stackOp, 7);
					}
					else if (precedence(7) < precedence(stackOp.cur->op))
					{
						while (precedence(7) < precedence(stackOp.cur->op))
						{
							operate(&stackNum, stackOp.cur->op);
							popOp(&stackOp);
							if (stackOp.cur == NULL)
							{
								break;
							}
						}
						pushOp(&stackOp, 7);
					}
					else
					{
						pushOp(&stackOp, 7);
					}
					i++;
				}
			}
			else if (match(expression, i, "*"))
			{
				if (stackOp.cur == NULL)
				{
					pushOp(&stackOp, 2);
				}
				else if (stackOp.cur->op == 5)
				{
					pushOp(&stackOp, 2);
				}
				else if (precedence(2) <= precedence(stackOp.cur->op))
				{
					while (precedence(2) <= precedence(stackOp.cur->op))
					{
						operate(&stackNum, stackOp.cur->op);
						popOp(&stackOp);
						if (stackOp.cur == NULL)
						{
							break;
						}
					}
					pushOp(&stackOp, 2);
				}
				else
				{
					pushOp(&stackOp, 2);
				}
				i++;
			}
			else if (match(expression, i, "/"))
			{
				if (stackOp.cur == NULL)
				{
					pushOp(&stackOp, 3);
				}
				else if (stackOp.cur->op == 5)
				{
					pushOp(&stackOp, 3);
				}
				else if (precedence(3) <= precedence(stackOp.cur->op))
				{
					while (precedence(3) <= precedence(stackOp.cur->op))
					{
						operate(&stackNum, stackOp.cur->op);
						popOp(&stackOp);
						if (stackOp.cur == NULL)
						{
							break;
						}
					}
					pushOp(&stackOp, 3);
				}
				else
				{
					pushOp(&stackOp, 3);
				}
				i++;
			}
			else if (match(expression, i, "%"))
			{
				if (stackOp.cur == NULL)
				{
					pushOp(&stackOp, 4);
				}
				else if (stackOp.cur->op == 5)
				{
					pushOp(&stackOp, 4);
				}
				else if (precedence(4) <= precedence(stackOp.cur->op))
				{
					while (precedence(4) <= precedence(stackOp.cur->op))
					{
						operate(&stackNum, stackOp.cur->op);
						popOp(&stackOp);
						if (stackOp.cur == NULL)
						{
							break;
						}
					}
					pushOp(&stackOp, 4);
				}
				else
				{
					pushOp(&stackOp, 4);
				}
				i++;
			}
			else if (match(expression, i, "("))
			{
				pushOp(&stackOp, 5);
				i++;
			}
			else if (match(expression, i, ")"))
			{
				if (stackOp.cur == NULL)
				{
					printf("SYNTAX ERROR!");
					number.num = NULL;
					number.len = 0;
					number.flag = 0;
					return number;
				}
				while (stackOp.cur->op != 5)
				{
					operate(&stackNum, stackOp.cur->op);
					popOp(&stackOp);
					if (stackOp.cur == NULL)
					{
						printf("SYNTAX ERROR!");
						number.num = NULL;
						number.len = 0;
						number.flag = 0;
						return number;
					}
				}
				popOp(&stackOp);
				i++;
			}
			pre = 1;
		}
		else
		{
			i++;
		}
	}
	while (stackOp.cur != NULL)
	{
		operate(&stackNum, stackOp.cur->op);
		popOp(&stackOp);
	}
	if (stackNum.cur == NULL)
	{
		printf("SYNTAX ERROR!");
		number.num = NULL;
		number.len = 0;
		number.flag = 0;
		return number;
	}
	return popNum(&stackNum);
}

int main()
{
	char str[10000];
	while (gets(str) != NULL)
	{
		struct number num = calculate(str, 10);
		prtNum(num, 10);
		printf("\n");
	}
}
