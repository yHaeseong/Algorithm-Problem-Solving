#include <bits/stdc++.h>

using namespace std;
int N, ret;
int a[1001], cnt[1001];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    for (int i = 0; i < N; i++){
        int maxValue = 0;
        for (int j = 0; j < i; j++){
            if ((a[j] < a[i]) && (maxValue < cnt[j])) maxValue = cnt[j];
        }
        cnt[i] = maxValue + 1;
        ret = max(ret, cnt[i]);
    }
    cout << ret;
}