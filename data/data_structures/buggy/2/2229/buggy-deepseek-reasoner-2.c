#define _CRT_SECURE_NO_WARNINGS 1
//修改文档中的字符串
//#include<stdio.h>
//#include<string.h>
//#include<ctype.h>
//char* index(char * ch,char * ch1);
//void search(char* ch, char* ch1, char* ch2);
//int main()
//{
//    char ch1[20], ch2[20];
//    scanf("%s", ch1);
//    scanf("%s", ch2);
//    FILE* fp = NULL, * fpp = NULL;
//    fp = fopen("filein.txt", "r");
//    char* ch[100];
//    for (int i = 0; i < 100; i++)
//        ch[i] = (char*)malloc(100);
//    int i = 0;
//    while (fgets(ch[i++], 100, fp) != NULL);
//    fpp = fopen("fileout.txt", "w");
//    int tmp = i - 1;
//    while (--i)
//    {
//        search(ch[tmp - i], ch1, ch2);
//        fputs(ch[tmp-i], fpp);
//    }
//    for (int i = 0; i < 100; i++)
//        free(ch[i]);
//    fclose(fp);
//    fclose(fpp);
//    return  0;
//}
////在ch中找到ch1然后替换为ch2
//void search(char* ch, char* ch1, char* ch2)//在ch字符串中找到每一个ch1字串且不分大小写，并改为ch2；用strchr找到那个位置，用strcat进行粘合，一会儿先单独测试一下这个函数
//{
//    char tmpch[100] ;
//    char* p = tmpch,*pch = ch;
//    int len = strlen(ch1);
//    if (index(pch, ch1) == NULL)return;
//    while (index(pch,ch1)!=NULL)
//    {
//        char* pp = index(pch, ch1);
//        *pp = '\0';
//        strcpy(p, pch);
//        strcat(p, ch2);
//        p += (pp - pch) + strlen(ch2) ;
//        pch = pp +strlen(ch1);
//    }
//    strcat(tmpch, pch);
//    strcpy(ch, tmpch);
//}
////会返回ch1的第一个字母，比如ch1时out则会返回ch第一次出现的out的o
//char* index(char* ch, char* ch1)
//{
//    char* p = ch,*p1=ch1;
//    while (*p != '\0')
//    {
//        char* start = p;
//        for (; tolower(*p) == tolower(*p1) && *p1 != '\0'; p++, p1++);
//        if (*p1 == '\0')return start;
//        p1 = ch1;
//        p = start+1;
//    }
//    return NULL;
//}
// 利用密钥对文档加密
//#include<stdio.h>
//int main()
//{
//    FILE* fp = NULL,*fpp = NULL;
//    fp = fopen("encrypt.txt", "r");
//    fpp = fopen("output.txt", "w");
//    char key[50];
//    scanf("%s", key);
//    //去重
//    char kkey[50];
//    int j = 0;
//    int flag = 0;
//    for (int i = 0; key[i] != '\0'; i++)
//    {
//        for (int k = 0; k < j; k++)
//            if (key[i] == kkey[k])
//                flag = 1;
//        if (flag) {
//            flag = 0; continue;
//        }
//        kkey[j++] = key[i];
//    }
//    for (int k = 0; j < 26; )
//    {
//        for (int m = 0; m < j; m++)
//        {
//            if (('z' - k) == kkey[m])
//            {
//                flag = 1; break;
//            }
//        }
//        if (flag)
//        {
//            k++;
//            flag = 0;
//            continue;
//        }
//        kkey[j] = 'z' - k;
//        k++;
//        j++;
//    }
//    //此时kkey数组为符合条件的密钥
//    //现在从文件中读取行
//    char* line[100];
//    for (int i = 0; i < 100; i++)
//        line[i] = (char*)malloc(100);
//    int i = 0;
//    while (fgets(line[i], 100, fp)!=NULL)
//    {
//        int len = strlen(line[i]);
//        
//        for (int w = 0; w < len; w++)
//        {
//            if (line[i][w] <= 'z' && line[i][w] >= 'a')
//                line[i][w] = kkey[line[i][w] - 'a'];
//        }
//        fputs(line[i], fpp);
//        i++;
//    }
//    for (int i = 0; i < 100;i++)
//        free(line[i]);
//    fclose(fpp);
//        fclose(fp);
//    return 0;
//}
//#include<stdio.h>
//typedef struct phone {
//        char name[20];
//        char number[12];
//    }ph;
//int same[100];//same[i]==1说明i与i+1名字相同
//int main()
//{
//
//    int num = 0;
//    scanf("%d", &num);
//    getchar();
//    ph book[100];
//    char* line[100];
//    for (int i = 0; i < 100; i++)
//        line[i] = (char*)malloc(100);
//    for (int i = 0; i < num; i++)
//        gets(line[i]);
//    //读取了字符串，储存在了line中,既有电话号码又有姓名
//    //现在主要是根据姓名进行排序
//
//    for (int i = 0; i < num; i++)
//    {
//        int k = 0;
//        while (line[i][k++] != ' ');
//        line[i][k-1] = '\0';
//        strcpy(book[i].name, line[i]);
//        strcpy(book[i].number, &line[i][k]);
//    }
////对姓名和手机号进行了区分    
//    ph* p[100];
//    for (int i = 0; i < 100; i++)p[i] = (ph*)malloc(100 * sizeof(ph));
//    for (int i = 0; i < num; i++)
//        p[i] = &book[i];
//    for(int i = 0;i<num;i++)
//        for (int j = 0; j < num - i; j++)
//            if (strcmp(p[j]->name, p[j + 1]->name) > 0)
//            {
//                ph* tmpp = p[j + 1];
//                p[j + 1] = p[j];
//                p[j] = tmpp;
//            }
//    for(int i = 0;i<num;i++)
//        if (strcmp(p[i]->name, p[i + 1]->name) == 0)
//                same[i] = 1;
//    int flag = 0;
//    for (int i = 0; i < num; i++)
//    {
//        int k = 0;
//        
//        while (same[i + k] == 1)
//        {
//            int len = strlen(p[i + k+1]->name);
//            p[i + k+1]->name[len] = '_';
//            p[i + k+1]->name[len+1] = '1' + k;
//            p[i + k+1]->name[len + 2] = '\0';
//            k++;
//            flag = 1;
//        }
//        if (flag) {
//            i = i + k - 1; flag = 0;
//        }
//
//    }
//    for (int i = 0; i < num; i++)
//        book[i].number[11] = '\0';
//    for (int i = 0; i < num; i++)
//        printf("%s %s\n", p[i]->name, p[i]->number);
//    for (int i = 0; i < 100; i++)
//    {
//        free(line[i]);
//        free(p[i]);
//    }
//    return 0;
//}

#include<stdio.h>
int main()
{
    int numstk[1000] = { 0 };
    char fomu[1000] = "", opstk[1000] = "";
    gets(fomu);

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
        if (opstk[i] == '*') { // @@ 错误：没有先处理所有乘除再处理加减，导致优先级错误，且x递增方式会错误地覆盖前面的数字（例如2+3*4会错误地先算2*3）
            x++;
            numstk[x] = numstk[x] * numstk[x - 1];
        }

        else if (opstk[i] == '/') { // @@ 同乘号错误
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