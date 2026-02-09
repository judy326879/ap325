#include <iostream>
#include <map>
using namespace std;
int a[200010], c[200010] = {};
map<int, int> dic;
int main(){
    int m, n, k = 1;
    cin >> m >> n;
    for(int i=0;i<n;++i){
        cin >> a[i];
        auto iter  = dic.find(a[i]);
        if(iter == dic.end()){
            dic[a[i]] = k;
            a[i] = k;
            ++k;
        }
        else{
            a[i] = dic[a[i]];
        }
    }
    int sum = 0;
    int r = 0, l = 0;
    while(r<n){
        c[a[r]]++;
        if(c[a[r]]>1){
            while(a[l]!=a[r]){
                c[a[l]]--;
                l++;
            }
            c[a[l]]--;
            l++; 
        }
        if(r-l+1 == m) sum++;
        ++r;
    }
    cout << sum << endl;
}
