#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005] = {};

int dfs(int l, int r, int k, string s){
    if(r < l)return 0;
    if(l == r)return 1;
    if(dp[l][r])return dp[l][r];
    if(s[l] == s[r]){
        return dp[l][r] = dfs(l + 1, r - 1, k, s) + 2;
    }else{
        return dp[l][r] = max(dfs(l + 1, r, k - 1, s), dfs(l, r - 1, k - 1, s));
    }
}
void slove(int n, int m, string s){
    int re = dfs(0, n - 1, m, s);
    if(n -  re > m){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
void init(){
    memset(dp,0,sizeof(dp));
}
void test(int &n, int &m, string &s){
    n = rand()%10, m = rand()%10;
    for(int i = 0 ; i < n ; i++){
        s += 'a';
    }
    for(int i = 0 ; i < m ; i++){
        int now = rand()%s.size();
        s.insert(s.begin()+now,'b'+rand()%25);
    }
    n += m;
}
int main(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    slove(n, m, s);
    return 0;
}
