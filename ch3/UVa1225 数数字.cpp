//************使用sprintf时注意当前的地址，或者边输入边输出，避免地址的改变******
//************UVa题目末位不能输出无效的空格，否则WA********************
#include<cstdio>
#include<cstring>
#define MAXN 100005
/*
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n = 0;
        char a[MAXN] = {0};
        char *adress = a;
        int b[MAXN] = {0};
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            int d = i;
            int j = 0;
            for(j = 0; d > 0; j++)
            {
                d = d/10;
            }
            sprintf(adress,"%d",i);
            adress += j;
        }
        for(int i = 0; a[i] != 0; i++)
        {
            int c = a[i]-'0';
            b[c]++;
        }
        for(int i = 0; i < 10; i++)
        {
            printf("%d%c",b[i],i == 9?'\n':' ');
        }
    }
    return 0;
}
*/



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n = 0;
        char a[MAXN] = {0};
        int b[MAXN] = {0};
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            sprintf(a,"%d",i);
            for(int j = 0; j < strlen(a); j++)
            {
                b[a[j]-'0']++;
            }
            memset(a,0,sizeof(a));
        }
        for(int i = 0; i < 10; i++)
        {
            printf("%d%c",b[i],i == 9?'\n':' ');
        }
    }
    return 0;
}
