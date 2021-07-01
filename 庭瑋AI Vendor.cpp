#include<bits/stdc++.h>
using namespace std;

struct cmpv{
    bool operator()(const pair<int, int>& l, const pair<int, int>& r) const{
        if(l.first != r.first)
            return l.first > r.first;
        else
            return l.second < r.second;
    }
};

multiset<pair<int, int>> wtov;
multiset<pair<int, int>, cmpv> vtow;
int N, q;
int mov, wei, val;
int w, v;

int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
    //leave output in buffer
    //flush: clean buffer to screen
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> wei >> val;
        wtov.emplace(wei, val);
        vtow.emplace(val, wei);
    }
    cin >> q;
    while(q--){
        cin >> mov;
        if(mov == 1){
           cin >> wei >> val;
           wtov.emplace(wei, val);
           vtow.emplace(val, wei);
        }else if(mov == 2){
            cin >> wei >> val;
            auto it = wtov.find({wei, val});
            if(it->first == wei && it->second == val){
                auto it2 = vtow.find({val, wei});
                wtov.erase(it);
                vtow.erase(it2);
                cout << "OK\n";
            }
            else
                cout << "No Item\n";
        }else if(mov == 3){
            cin >> wei;
            auto it = wtov.lower_bound({wei, -1});
            if(it == wtov.end())
                cout << "No Item\n";
            else{
                w = it->first, v = it->second;
                auto it2 = vtow.find({v, w});
                cout << "OK ";
                cout << w << " " << v << "\n";
                wtov.erase(it);
                vtow.erase(it2);
            }
        }else if(mov == 4){
            cin >> val;
            auto it = vtow.upper_bound({val, -1});
            if(it == vtow.end())
                cout << "No Item\n";
            else{
                v = it->first, w = it->second;
                auto it2 = wtov.find({w, v});
                cout << "OK ";
                cout << w << " " << v << "\n";
                wtov.erase(it2);
                vtow.erase(it);
            }
        }
    }
    return 0;
}

