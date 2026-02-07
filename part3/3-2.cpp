#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s1;
    while(cin >> s1){
        int a = 1;
        stack<char> s;
        int k = 0;
        for(char c:s1){
            if(k == 0){
                ++k;
                s.push(c);
                continue;
            }
            char c1;
            if(!s.empty()) c1 = s.top();
            if(c == ']'){
                if(c1 == '[')
                    s.pop();
                else{
                    a = 0;
                    cout << "no" << endl;
                    break;
                }
            }
            else if(c == '}'){
                if(c1 == '{')
                    s.pop();
                else{
                    a = 0;
                    cout << "no" << endl;
                    break;
                }
            }
            else if(c == ')'){
                if(c1 == '(')
                    s.pop();
                else{
                    a = 0;
                    cout << "no" << endl;
                    break;
                }
            }
            else s.push(c);
        }
        if(a == 1) cout << "yes" << endl;
    }
}
