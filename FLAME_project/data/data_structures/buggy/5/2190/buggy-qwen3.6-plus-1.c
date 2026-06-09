#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define ll long long

typedef struct name {
    int a;
    int b;
}duo;
duo m[1000];
duo n[1000];
duo ans[100000];

void cmp(const void* p, const void* q) // @@ The return type of the comparison function for qsort must be int, not void. It should return negative, zero, or positive values to indicate order.
{
    duo* x = (duo*)p;
    duo* y = (duo*)q;
    if (x->b > y->b) return -1;
    else if (x->b < y->b) return 1;
    else return 0;
}


int main()
{
    char p;
    char q;
    int len1 = 0, len2 = 0;
    for (int i = 0;; i++)
    {
        len1++;
        scanf("%d%c%d%c", &m[i].a, &p, &m[i].b, &q);
        if (q == '\n')
        {
            break;
        }
    }
    for (int i = 0;; i++)
    {
        len2++;
        scanf("%d%c%d%c", &n[i].a,&p, &n[i].b,&q);
        if (q=='\n')
        {
            break;
        }
    }
    int t = 0;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            ans[t].a = m[j].a * n[i].a;
            ans[t].b = m[j].b + n[i].b;
            t++;
        }
    }
    qsort(ans, t, sizeof(ans[0]), cmp);

    for (int i = 0; i < t; i++)
    {
        if (ans[i].b == ans[i - 1].b) // @@ Accessing ans[i-1] when i=0 causes out-of-bounds access. Also, this logic only merges adjacent duplicates after sorting, but if multiple terms merge into one, the intermediate zeroed-out terms might remain or logic fails if more than 2 terms share the same exponent. However, the primary crash/error here is i=0 access.
        {
            ans[i].a += ans[i - 1].a;
            ans[i - 1].a = 0;
        }
    }

    for (int i = 0; i < t; i++)
    {
        if (ans[i].a != 0)
            printf("%d %d ", ans[i].a, ans[i].b);
    }
}


//struct linn {
//    int x1;
//    int y1;
//    int x2;
//    int y2;
//};
//struct linn line[101] = {0,0,0,0};    
//int count[101] = { 0 };
//int n;
//int duoshao(int a, int b)
//{
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        if (a == line[i].x1 && b == line[i].y1)
//        {
//            return (duoshao(line[i].x2, line[i].y2) + 1);
//        }
//    }
//    return 1;
//}
//
//int main()
//{
//    
//
//
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2 );
//    }
//    for (int i = 0; i < n; i++)
//    {
//        count[i] = duoshao(line[i].x1, line[i].y1)-1;
//    }
//    int max = count[0];
//    int flag = 0;
//
//    /*for (int i = 0; i < n; i++)
//    {
//        printf("%d\n", count[i]);
//    }*/
//
//
//    for (int i = 1; i < n; i++)
//    {
//        if (count[i] > max)
//        {
//            max = count[i];
//            flag = i;
//        }
//    }
//    printf("%d %d %d", count[flag], line[flag].x1, line[flag].y1);
//}










////全排列
//int a[10], book[10] = { 0 };//a代表盒子，book代表手上的牌 
//int n;//n代表1~n 
//void dfs(int step) {
//    int i;
//    if (step == n) {
//        for (i = 0; i < n; i++) {
//            printf("%d ", a[i]);
//        }
//        printf("\\n");
//        return;
//    }
//    for (i = 0; i < n; i++) {
//        if (book[i] == 0) {
//            a[step] = i + 1;//将手上的牌放进盒子中去 
//            book[i] = 1;//表示牌已经不在手上 
//            dfs(step + 1);//递归 
//            book[i] = 0;//如果返回，就将牌从盒子里面抽出 
//        }
//    }
//}
//int main() {
//    scanf("%d", &n);
//    dfs(0);
//    return 0;
//}




















//void swap(int* p, int* q)
//{
//    int t;
//    t = *p;
//    *p = *q;
//    *q = t;
//}


//7
//struct stu {
//    int num;
//    float TotalScore;
//};
//void f(struct stu p)
//{
//    struct stu s[2] = { {20044, 5501}, {20045, 5374} };
//    p.num = s[1].num;
//    p.TotalScore = s[1].TotalScore;
//}
//int main()
//{
//    struct stu s[2] = { {20041, 703}, {20042, 580} };
//    f(s[0]);
//    printf("%d %3.0f\n", s[0].num, s[0].TotalScore);
//    return 0;
//
//}











//第二次第五题
// 综合性很强
// 反复品味哈哈哈哈哈哈哈哈哈
//char p0[501][51];
//int cmp(const void* p, const void* q)
//{
//    int a = *(int*)p;
//    int b = *(int*)q;
//    if (strcmp(p0[a], p0[b]) > 0)return 1;
//    else if (strcmp(p0[a], p0[b]) < 0)return -1;
//    else return 0;
//}
//
//
//
//int main()
//{
//    int o[501] = { 0 };
//    for (int j = 0; j < 501; j++)
//    {
//        o[j] = j;
//    }
//    char ss[501] = {'\0'};
//    char sss[501] = { '\0' };
//    char p1[501][21] = { '\0' };
//    char p2[501][31] = { '\0' };
//    char p3[501][11] = { '\0' };
//    FILE* f1 = fopen("books.txt","r");
//    FILE* f2 = fopen("ordered.txt", "w");
//    if (f1 == NULL || f2 == NULL)
//    {
//        perror("cuowu"); 
//        exit(1);
//    }
//    int i = 0;
//    while (fgets(ss, 200, f1) != NULL)
//    {
//        sscanf(ss, "%s %s %s %s", p0[i], p1[i], p2[i], p3[i]);
//        i++;
//    }
//    int book = i;
//    
//    qsort(o, book, sizeof(o[0]), cmp);
//    //
//    int a;
//    char word[200] = { NULL };
//    while (scanf("%d", &a) && a != 0)
//    {
//        getchar();
//        if (a == 1)
//        {
//            gets(ss);
//            sscanf(ss, "%s %s %s %s", p0[i], p1[i], p2[i], p3[i]);
//            book++;
//            i++;
//            qsort(o, book, sizeof(o[0]), cmp);
//        }
//        else if (a == 2)
//        {
//            gets(word);
//            for (int j = 0; j < book; j++)
//            {
//                if (strstr(p0[o[j]], word) != NULL)
//                {
//                    printf("%-50s%-20s%-30s%-10s\n", p0[o[j]], p1[o[j]], p2[o[j]], p3[o[j]]);
//                }
//            }
//        }
//        else if (a == 3)
//        {
//            gets(word);
//            for (int j = 0; j < book; j++)
//            {
//                if (strstr(p0[j], word) != NULL)
//                {
//                    p0[j][0] = NULL;
//                }
//            }
//        }
//    }
//    for (int j = 0; j < book; j++)
//    {
//        if (p0[o[j]][0] == NULL)continue;
//        sprintf(sss, "%-50s%-20s%-30s%-10s", p0[o[j]], p1[o[j]], p2[o[j]], p3[o[j]]);
//        //puts(sss);
//        fputs(sss, f2);
//        fputs("\n", f2);
//    }
//    fclose(f1);
//    fclose(f2);
//}
//






































































//字符串替换 in变out
//char s[101];
//char s1[101];
//char word1[11];
//char word2[11];
//int main()
//{
//    gets(word1);
//    gets(word2);
//    int len1 = strlen(word1);
//    int len2 = strlen(word2);
//    int flag = 0,j,k,x=0,y=0,i;
//    FILE* f1 = fopen("filein.txt", "r");
//    FILE* f2 = fopen("fileout.txt", "w");
//    if (f1 == NULL || f2 == NULL)
//    {
//        perror("cuowu"); exit(1);
//    }
//    while (fgets(s, 101, f1) != NULL)
//    /*while(gets(s)!=NULL)*/
//    {
//        int len = strlen(s);
//        //for (int i = 0; i < len; i++)
//        //{
//        //    s1[i] = s[i];
//        //}//
//        y = 0, x = 0,i=0;
//        for (i = 0; y < len; i++,y++)
//        {
//            s1[i] = s[y];
//            if ((islower(word1[x])&&(s[y] == word1[x]||s[y]==word1[x]+'A'-'a'))|| (isupper(word1[x]) && (s[y] == word1[x] || s[y] == word1[x] + 'a' - 'A'))) { flag++; x++; }
//            else { flag = 0; x = 0; }
//            if (flag == len1)//判断成功
//            {
//                for (j = i - len1 + 1,k=0; j < i - len1 + 1 + len2;k++, j++)
//                {
//                    s1[j] = word2[k];
//                }
//                i = i + len2 - len1;
//                flag = 0; x = 0;
//            }
//        }
//        s1[i] = '\0';
//        //
//        /*puts(s1);*/
//
//        //
//        fputs(s1, f2);
//
//        /*fputc('\n', f2);*/
//    }
//    fclose(f1);
//    fclose(f2);
//    return 0;
//}
























////第一次第三题
//char s[101];
//
//void wrap(int i,int direct)
//{
//    int tmp=0;
//    if (direct == 0)
//    {
//        tmp = s[i];
//        s[i] = s[i - 1];
//        s[i - 1] = tmp;
//    }
//    else
//    {
//        tmp = s[i];
//        s[i] = s[i + 1];
//        s[i + 1] = tmp;
//    }
//}
//
//
//int main()
//{
//    
//    gets(s);
//    int e = 0;
//    int len = strlen(s), i=1;
//    if (s[0] == '0' && s[1] == '.')//0.0几的情况
//    {
//        while (s[i - 1] == '0')
//        {
//            wrap(i, 1);
//            e--;
//            i++;
//        }
//        if (s[i + 1] == '\0')
//        {
//            for (int j = i - 1; j < len; j++)
//            {
//                if(s[j]!='.') printf("%c", s[j]);
//            }
//            printf("e%d", e);
//        }
//        else
//        {
//            for (int j = i - 1; j < len; j++)
//            {
//                printf("%c", s[j]);
//            }
//            printf("e%d", e);
//        }
//    }
//    else
//    {
//        e = 0;
//        for (i = 0; i < len; i++)
//        {
//            if (s[i] == '.') break;
//        }
//        e = i - 1;
//        printf("%c.", s[0]);
//        for (i = 1; i < len; i++)
//        {
//            if (s[i]=='.')
//            {
//                continue;
//            }
//            printf("%c", s[i]);
//        }
//        printf("e%d", e);
//    }
//    return 0;
//}










    











































/*
char a[123];//97-122
int flag[123];
int main()
{
    char s[100] = { '0' };
    gets(s);
    int i = 97, j = 0, flagg = 0;
    char z = 'z';
    for (i = 97, j = 0; i <= 122; j++)
    {

        if (s[j] == '\0') { flagg = 1; }
        if (flagg == 1)
        {
            if (flag[z] == 0)
            {
                a[i] = z;
                i++;
            }
            z--;
            continue;
        }
        if (flag[s[j]] == 0)
        {
            a[i] = s[j];
            flag[s[j]] = 1;
            i++;
        }
    }
    //for (i = 97; i <= 122; i++)
    //{
    //    printf("%c",a[i]);
    //}

    FILE* f1;
    FILE* f2;
    f1 = fopen("encrypt.txt", "r");
    f2 = fopen("output.txt", "w");
    int c;
    if (f1 == NULL || f2 == NULL)
    {
        perror("cuowu"); exit(1);
    }
    while ((c = fgetc(f1)) != EOF)
    {
        if (isalpha(c) == 0) { fputc(c, f2); }
        else { fputc(a[c], f2); }
    }
    fclose(f1);
    fclose(f2);
}
*/