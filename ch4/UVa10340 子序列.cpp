#include<cstdio>
#include<cstring>
#define MAXN 100024
char s[MAXN] = {0};
char t[MAXN] = {0};
int main()
{
    while(scanf("%s %s",s,t) != EOF)
    {
        int flag = 0;
        int ans = 1;
        int slen = strlen(s), tlen = strlen(t);
        for(int i = 0, j = 0; i < slen; i++,j++)
        {
            for(; j < tlen && s[i] != t[j]; j++)
            if(j == tlen)
            {
                ans = 0;
                break;
            }
        }
        printf("%s\n", ans?"Yes":"No");
    }
    return 0;
}
