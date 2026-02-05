#include <iostream>
#include <stack>
#include <list>
#include <string>
using namespace std;
stack<int> st;
list<string> li;
int main(){
    string n;
    while(cin >> n) li.push_back(n);
    int len = li.size();
    for(int i=0;i<len;++i){
        string s = li.back();
        li.pop_back();
        if(s == "f"&&!st.empty()){
            int n1 = st.top();
            st.pop();
            st.push(2*n1-3);
        }
        else if(s == "g"&&!st.empty()){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(2*n1+n2-7);
        }
        else if(s == "h"&&!st.empty()){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            int n3 = st.top();
            st.pop();
            st.push(3*n1-2*n2+n3);
        }
        else{
            st.push(stoi(s));
        }
    }
    int k = st.top();
    cout << k << endl;
}
