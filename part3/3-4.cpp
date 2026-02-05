#include <iostream>
#include <stack>
using namespace std;
long long n, a[200001] = {};
stack<long long> st;
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> a[i];
    }
    st.push(0);
    a[0] = 10000001;
    long long sum = 0;
    for(int i=1;i<=n;++i){
        while(a[st.top()]<=a[i]){
            st.pop();
        }
        sum+=i-st.top();
        st.push(i);
    }
    cout << sum << endl;
}
