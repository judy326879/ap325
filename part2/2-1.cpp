#include <iostream>
#include <set>
using namespace std;
set<int> st;
int main(){
    int n, a;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> a;
        st.insert(a);
    }
    int len = st.size();
    cout << len << endl;
    for(auto it = st.begin();it!=st.end();++it){
        cout << *it << " ";
    }
}
