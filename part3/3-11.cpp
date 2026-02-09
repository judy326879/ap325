#include <iostream>
#include <vector>
#include <map>
using namespace std;
int c[200010] = {}, a[200010];
map<int, int> dic;
int main(){
    int n;
    cin >> n;
    int k = 1;
    for(int i=0;i<n;++i){
        cin >> a[i];
        auto iter = dic.find(a[i]);
        if(iter == dic.end()){
            dic[a[i]] = k;
            a[i] = k;
            ++k;
        }
        else{
            a[i] = dic[a[i]];
        }
    }
    int l = 0, r = 0, Max = 0;
    while(r<n){
        c[a[r]]++;
        if(c[a[r]]>1){
            while(c[a[l]]!=c[a[r]]){
                c[a[l]]--;
                l++;
            }
            c[a[l]]--;
            ++l;
        }
        Max = max(r-l+1, Max);
        ++r;
    }
    cout << Max << endl;
}
