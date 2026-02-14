#include <iostream>
using namespace std;
int main(){
    long long n, smax = 0, pmax = 0;
    cin >> n;
    for(int i=0;i<n;++i){
        long long p;
        cin >> p;
        pmax = (pmax>0)?pmax+p:p;
        smax = max(smax, pmax);
    }
    cout << smax << endl;
}
