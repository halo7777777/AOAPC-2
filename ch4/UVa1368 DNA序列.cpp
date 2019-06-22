#include<cstdio>
#include<cstring>
#define MAXN 1005

char s[MAXN][MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[MAXN] = {0};     //用于存每列最多的数
        memset(s,0,sizeof(s));
        int m, n;
        int add = 0;
        scanf("%d%d",&m,&n);
        for(int i = 0; i < m; i++)
        {
            scanf("%s",s[i]);
        }
        for(int i = 0; i < n; i++)
        {
            char max = 0;
            int max_num = 0;
            int b[100] = {0};   //用于存ACTG的各个数
            for(int j = 0; j < m; j++)
            {
                b[s[j][i]]++;
            }
            for(int k = 0; k < 100; k++)
            {
                if(b[k] > max_num)
                {
                    max_num = b[k];
                    max = k;
                }
            }
            for(int k = 0; k < 100; k++)
            {
                if(k != max)
                {
                    add += b[k];
                }
            }
            a[i] = max;
        }
        for(int i = 0; i < n; i++)
            printf("%c",a[i]);
        printf("\n%d\n",add);
    }
    return 0;
}
