#include <iostream>
using namespace std;
int n, sum = 0, sl;
string s;
int Map(int n1, int left){
    for(int i=0;i<4&&left<sl;++i){
        if(left>=sl||n1 == 0) return 0;
        else if(s[left] == '2'){
            left = Map(n1/2, left+1);
        }
        else if(s[left] == '1'){
            sum+=(n1*n1);
            left++;
        }
        else left++;
    }
    return left++;
}
int main(){
    cin >> s >> n;
    sl = s.size();
    Map(n/2, 1);
    cout << sum << endl;
}
