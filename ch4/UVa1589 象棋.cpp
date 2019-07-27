#include<bits/stdc++.h>
using namespace std;
const int MAXN = 16;
int n, m, vExp[MAXN][MAXN], hExp[MAXN][MAXN], H[MAXN][MAXN],
V[MAXN][MAXN], Squares[MAXN];
int main()
{
    char buf[4];
    int x, y, t = 0;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        if(++t > 1)
            printf("\n**********************************\n\n");
        memset(vExp, 0, sizeof(vExp)), memset(hExp, 0, sizeof(hExp));
        memset(H, 0, sizeof(H)), memset(V, 0, sizeof(V)), memset(Squares, 0, sizeof(Squares));
        for(int i = 0; i < m; i++)
        {
            scanf("%s%d%d", buf, &x, &y);
            if(buf[0] == 'H')
                H[x][y] = 1;
            else
                V[y][x] = 1;
        }
        for(int i = n; i >= 1; i--)
            for(int j = n; j >=1 ; j--)
        {
            if(H[i][j]) hExp[i][j] = hExp[i][j+1] + 1;
            if(V[i][j]) vExp[i][j] = vExp[i+1][j] + 1;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
        {
            int maxS = min(hExp[i][j], vExp[i][j]);
            for(int s = 1; s <= maxS; s++)
                if(hExp[i+s][j] >= s && vExp[i][j+s] >= s)
                {
                    Squares[s]++;
                }
        }
        printf("Problem #%d\n\n", t);
        bool found = false;
        for(int i = 1; i <= n; i++)
            if(Squares[i])
        {
            found = true;
            printf("%d square (s) of size %d\n", Squares[i], i);
        }
        if(!found) puts("No completed squares can be found.");
    }
    return 0;
}
