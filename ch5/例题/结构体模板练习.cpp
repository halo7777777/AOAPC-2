#include<iostream>
using namespace std;

/*
struct Point
{
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y) {}
};

Point operator + (const Point& A, const Point& B)   //引用传入数据,运算符重载
{
    return Point(A.x + B.x, A.y + B.y);
}

ostream& operator <<(ostream &out, const Point& p)  //引用传入数据，运算符重载
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
int main()
{
    Point a, b(1, 2);
    a.x = 3;
    cout << a+b << "\n";
}
*/
/*--------------------------------------------------模板------------------------------------------------------------------*/

template <typename T>
struct Point
{
    T x, y;
    Point(T x = 0, T y = 0): x(x), y(y) {}
};

template <typename T>
Point<T> operator + (const Point<T>& A, const Point<T>& B)
{
    return Point<T>(A.x + B.x, A.y + B.y);
}

template <typename T>
ostream& operator << (ostream &out, const Point<T>& p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
int main()
{
    Point<int> a(1, 2), b(3, 4);
    Point<double> c(1.1, 2.2), d(3.3, 4.4);
    cout << a+b << " " << c+d << "\n";
    return 0;
}


