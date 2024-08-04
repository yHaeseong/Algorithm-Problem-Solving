#include <bits/stdc++.h>

using namespace std;

int dp[10000001];
int n;

int go(int i){
    if (i == 1) return 0;
    if (i == 2) return 1;
    int &ret = dp[i];
    if (ret) return ret;
    ret = go(i-1) + 1;
    if (n%3 == 0) ret = min(go(i/3)+1, ret);
    else if (n%2 == 0) ret = min(go(i/2)+1, ret);
    return ret;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << go(n);
}