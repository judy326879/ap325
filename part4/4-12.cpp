#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    int Max = 0, begin = 0;
    cin >>  p[0];
    begin = p[0];
    for(int i=1;i<n;++i){
        cin >> p[i];
        if(Max<p[i]-begin) Max = p[i]-begin;
        else if(p[i]<begin) begin = p[i];
    }
    cout << Max << endl;
}
