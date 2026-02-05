#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    stack<char> st1,st3;
    stack<long long> st, st2, st4;
    cin >> s;
    int len = s.size();
    for(int i=0;i<len;++i){
        if(s[i] == '+'||s[i] == '-'){
            st1.push(s[i]);
        }
        else if(s[i] == '*'){
            int a = st.top();
            st.pop();
            ++i;
            st.push(a*(s[i]-'0'));
        }
        else if(s[i] == '/'){
            int a = st.top();
            st.pop();
            ++i;
            st.push(a/(s[i]-'0'));
        }
        else{
            st.push(s[i] - '0');
        }
    }
    while(!st.empty()){
        long long a = st.top();
        st.pop();
        st2.push(a);
    }
    while(!st1.empty()){
        char c = st1.top();
        st1.pop();
        st3.push(c);
    }
    long long a = st2.top();
    st2.pop();
    st4.push(a);
    while(!st3.empty()){
        char c = st3.top();
        st3.pop();
        long long a = st4.top();
        st4.pop();
        long long b = st2.top();
        st2.pop();
        if(c == '+'){
            st4.push(a+b);
        }
        else{
            st4.push(a-b);
        }
    }
    cout << st4.top() << endl;
}
