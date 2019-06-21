//容易出现编程的粗心小错误
//使用万能库，和swap（），sort（）函数简化程序
#include<bits/stdc++.h>
using namespace std;
struct rects
{
    int x;
    int y;
}rect[6];
bool cmp(rects a, rects b)
{
    if(a.x != b.x) return a.x > b.x;
    else return a.y > b.y;
}
bool ok()
{
    if(rect[0].x != rect[1].x || rect[0].y != rect[1].y)
       return false;
    if(rect[2].x != rect[3].x || rect[2].y != rect[3].y)
       return false;
    if(rect[4].x != rect[5].x || rect[4].y != rect[5].y)
       return false;
    if(rect[1].y != rect[5].x)
       return false;
    if(rect[1].x != rect[2].x)
       return false;
    if(rect[3].y != rect[4].y)
       return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&rect[0].x,&rect[0].y) != EOF)
    {
        if(rect[0].x < rect[0].y)
            swap(rect[0].x, rect[0].y);
        for(int i = 1; i < 6; i++)
        {
            scanf("%d%d",&rect[i].x,&rect[i].y);
            if(rect[i].x < rect[i].y)
                swap(rect[i].x, rect[i].y);
        }

        sort(rect,rect+6,cmp); //降序
        if(ok())
            puts("POSSIBLE");
        else
            puts("IMPOSSIBLE");
    }
    return 0;
}


/*

#include <bits/stdc++.h>
using namespace std;
struct node{
    int h, w;
}a[10];
bool cmp(node x,node y){//先按照w升序排序，再按照h升序排序
    if(x.w!=y.w)    return x.w<y.w;
    else return x.h<y.h;
}
bool ok(){//判断是否可以组成长方体
    if(a[0].h!=a[1].h||a[0].w!=a[1].w)
       return false;
    if(a[2].h!=a[3].h||a[2].w!=a[3].w)
       return false;
    if(a[4].h!=a[5].h||a[4].w!=a[5].w)
       return false;
    if(a[1].h!=a[5].w)
       return false;
    if(a[1].w!=a[2].w)
       return false;
    if(a[3].h!=a[4].h)
       return false;
    return true;
}
int main(){
    while(scanf("%d%d",&a[0].h,&a[0].w))//读入
        {
        if(a[0].h<a[0].w)
           swap(a[0].h,a[0].w);//保证h<w
        for(int i=1;i<6;i++)
            {
            scanf("%d%d",&a[i].h,&a[i].w);
            if(a[i].h<a[i].w)
               swap(a[i].h,a[i].w);//保证h<w
            }
        sort(a,a+6,cmp);//排序
        if(ok()) //输出 & AC
           puts("POSSIBLE");
        else
           puts("IMPOSSIBLE");
    }
    return 0;
}
*/
