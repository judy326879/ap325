#include <iostream>
using namespace std;
long long exp(long long x, long long y, long long p){
    if(y == 0) return 1;
    if(y & 1) return (exp(x, y-1, p)*x)%p;

    long long t = exp(x, y/2, p);
    return (t*t)%p;
}
int main(){
    string x;
    long long x1 = 0;
    long long y, p;
    cin >> x >> y >>  p;
    int len = x.size();

    x1 = x[0] - '0';
    for(int i=1;i<len;++i){
        x1*=10;
        x1%=p;
        x1 += (x[i]-'0');
        x1%=p;
    }
    cout << exp(x1+p, y, p);
}
