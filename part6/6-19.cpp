#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    int len;
    char s[100];
    //[位數][number]
    LL step[20][10], total = 0;
    cin >> s;
    len = strlen(s);
    for(int i=0;i<len;++i) s[i]-='0';
    for(int j=1;j<10;++j){
        step[1][j] = 1;
    }
    step[1][0] = 0;
    for(int i=2;i<=len;++i){
        step[i][9] = 1;
        for(int j=8;j>=0;--j){
            step[i][j] = step[i-1][j] + step[i][j+1];
        }
    }
    int k;
    for(int i=0;i<s[0];++i) total+=step[len][i];
    for(k=1;k<len;++k){
        if(s[k]<s[k-1]) break;//不符合
        for(int j=s[k-1];j<s[k];++j){
            total+=step[len-k][j];
        }
    }
    if(k==len) total++;//本身是階梯數字(cause only until len-1)
    cout << total << endl;
}
