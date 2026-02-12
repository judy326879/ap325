#include <iostream>
using namespace std;
int main(){
    int n, m;
    int sum;
    cin >> n;
    while(n--){
        cin >> m;
        sum = (m/50) + (m%50)/10 + (m%10)/5 + (m%5);
        cout << sum << endl;
    }
}
