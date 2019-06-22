//注意输出格式，中间要一空行
#include<cstdio>
#include<cstring>
#define MAXN 1000
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        char s[MAXN] = {0};
        scanf("%s",s);
        int len = strlen(s);
        int k = len;
        for(int i = len/2; i >= 1; i--)
        {
            int cmp = 1;
            if(len%i == 0)
            {
                for(int j = 0; j < len - i; j++)
                {
                    if(s[j] != s[j+i])
                    {
                        cmp = 0;
                    }
                }
                if(cmp == 1)
                {
                    k = i;
                }
            }
        }
        printf("%d\n",k);
        if(N) printf("\n");
    }
    return 0;
}
