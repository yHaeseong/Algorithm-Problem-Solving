#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[v.size()-1];
}