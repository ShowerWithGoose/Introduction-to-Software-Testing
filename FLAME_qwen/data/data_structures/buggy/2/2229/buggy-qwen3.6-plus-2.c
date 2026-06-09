#include<stdio.h>
int main()
{
    int numstk[1000] = { 0 };
    char fomu[1000] = "", opstk[1000] = "";
    gets(fomu); // @@ gets() is deprecated and completely removed in the C11 standard, which causes compilation errors in modern compilers. It should be replaced with fgets(fomu, 1000, stdin) or scanf("%[^\n]", fomu).

    //24 / 4 / 3 / 2 + 100 - 50 - 40 + 10*20*30*40 / 40 / 30 =
    int j = 0, k = 0;
    for (int i = 0; fomu[i] != '='; i++)
    {
        if ((fomu[i] == '+') || (fomu[i] == '-') || (fomu[i] == '*') || (fomu[i] == '/'))
            opstk[j++] = fomu[i];
        else if (fomu[i] <= '9' && fomu[i] >= '0')
        {
            numstk[k] = fomu[i] - '0';
            while (fomu[i + 1] <= '9' && fomu[i + 1] >= '0')
            {
                numstk[k] = numstk[k] * 10 + (fomu[i + 1] - '0');
                i++;
            }
            k++;
        }
    }//简化式子
    opstk[j] = '='; k--;
    /// / / +--+***/ / =
    //    24 4 3 2 100 50 40 10 20 30 40 40 30
    int x = 0;
    int flag = 0; int t = -999;
    for (int i = 0;opstk[i]!='=';i++ )
    {
        if (opstk[i] == '*') {
            x++;
            numstk[x] = numstk[x] * numstk[x - 1];
        }

        else if (opstk[i] == '/') {
            x++;
            numstk[x] = numstk[x - 1] / numstk[x];
        }
        else if (opstk[i] == '+')
        {
            if(flag == 0)
            {    
                flag = 1;
                t = numstk[x];
                x++;
            }
            else if (flag == 1)
            {
                numstk[x] += t;
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 2)
            {
                numstk[x] = t-numstk[x];
                x++;
                t = numstk[x - 1];
                flag = 1;
            }
        }
        else if (opstk[i] == '-')
        {
            if (flag == 0)
            {
                flag = 2;
                t = numstk[x];
                x++;
            }
            else if (flag == 2)
            {
                numstk[x] = t-numstk[x];
                x++;
                t = numstk[x - 1];
            }
            else if (flag == 1)
            {
                numstk[x] += t; 
                ++x;
                t = numstk[x - 1];
                flag = 2;
            }
        }
    }
    if (flag == 1)printf("%d", numstk[x] + t);
    if (flag == 2)printf("%d",  t - numstk[x]);
    if (!flag)printf("%d", numstk[x]);
    return 0;
}
//24 / 4 / 3 / 2 + 100 - 50 - 40 + 10 * 20 * 30 * 40 / 40 / 30 =
/// / / +--+***/ / =
//24 4 3 2 100 50 40 10 20 30 40 40 30
//0 6 24 3
//0 2 6 2
//0 1 2 100
//1 100 1 50
//2 50 101 40
//2 40 51*->61    10
//1 10 11*->10    20
//1 200 10 30
//1 6000 200 40
//1 240000 6000 40
//1 6000 240000 30
//1 200 6000 0
//211*
//// 24 / 4 / 3 / 2 + 100 - 50 - 40 + 10 * 20 * 30 * 40 / 40 / 30 =
/// / / +--+***/ / =
//24 4 3 2 100 50 40 10 20 30 40 40 30
//0 6 24 3 - 999
//0 2 6 2 - 999
//0 1 2 100 - 999
//1 100 1 50 1
//2 50 101 40 101
//2 40 51 10 51
//1 10 11 20 11
//1 200 10 30 11
//1 6000 200 40 11
//1 240000 6000 40 11
//1 6000 240000 30 11
//1 200 6000 0 11
//211
//#include<stdio.h>
//typedef struct book {
//    char name[50];
//    char writer[20];
//    char publisher[30];
//    char date[10];
//}bk;
//int main()
//{
//    FILE* fp = NULL;
//    fp = fopen("books.txt", "r");
//    if (fp == NULL) {
//        printf("打开文件失败"); return -1;
//    }
//    char* line[500];
//    for (int i = 0; i<500; i ++)
//        line[i] = (char*)malloc(150);
//    int i = 0;
//    while (fgets(line[i++],150,fp) != NULL);
//    int num = i;
////读入了原始书库
//    for (int i = 0; i < num; i++)
//    {
//        int j = 0;
//        while (*(line[i] + j) != ' ')
//        {
//        
//        }
//    }
//    fclose(fp);
//    return 0;
//}