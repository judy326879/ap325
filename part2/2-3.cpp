#include <iostream>
using namespace std;
long long exp(long long x, long long y, long long p){
    if(y == 0) return 1;
    if(y & 1) return (exp(x, y-1, p)*x)%p;

    long long t = exp(x, y/2, p);
    return (t*t)%p;
}
/*
long long exp1(long long x, long long y, long long p){
    long long t = 1, xi = x, i = 1;
    while(y>0){
        if(y & 1)
            t = (t*xi)%p;

            y = y>>1;
            xi = (xi*xi)%p;
            i*=2;
    }
    return t;
}
*/
int main(){
    long long x, y, p, res;
    cin >> x >> y >>  p;
    cout << exp(x, y, p);
}
