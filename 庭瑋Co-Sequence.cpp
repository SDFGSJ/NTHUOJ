#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

class Line{
public:
    vector<int> l;
    int moves = 0;
    int dis = 0;
    bool sorted = 0;
    Line(){
        for(int i = 0; i < 8; i++)
            l.emplace_back(-1);
    };
    Line(int ip[8]){
        for(int i = 0; i < 8; i++){
            l.emplace_back(ip[i]);
        }
    }
    //func
    void turn(){
        for(int i = 0; i < 7; i++){
            swap(l[i], l[7]);
        }
    }

    void change(int i){
        swap(l[i], l[(i+1)%8]);
    }

    void sortp(int le, int ri){
        if(sorted)
            return;
        sort(&l[le], &l[ri]);
        sorted = 1;
    }
    //overload
    Line& operator= (const Line& r){
        for(int i = 0; i < 8; i++){
            l[i] = r.l[i];
        }
        moves = r.moves;
        sorted = r.sorted;
        return *this;
    }
    bool operator== (const Line& r) const{
        for(int i = 0; i < 8; i++){
            if(l[i] != r.l[i])
                return false;
        }
        return true;
    }
//    bool operator< (const Line& r) const{
//    }
    friend ostream& operator<< (ostream& out, const Line& r){
        for(int i = 0; i < 8; i++){
            out << r.l[i] << " ";
        }
        out << "moves: " << r.moves;
        out << "\n";
        return out;
    }
};

int solve();

multiset<int> leftL, rightL;
//pair<int, int> taridx[8];
set<vector<int>> hasbeen;
Line ori, target;
queue<Line> state;

int main(){
    int T;
    cin >> T;
    //int lip[8], rip[8];

    while(T--){
        leftL.clear(), rightL.clear();
        for(int i = 0; i < 8; i++){
            cin >> ori.l[i];
            leftL.emplace(ori.l[i]);
        }
        for(int i = 0; i < 8; i++){
            cin >> target.l[i];
            rightL.emplace(target.l[i]);
            //taridx[i] = {target.l[i], i};
        }
        if(leftL != rightL)
            cout << -1 << "\n";
        else
            cout << solve() << "\n";
    }

    return 0;
}

int solve(){
    ori.moves = 0;
    state.push(ori);
    hasbeen.emplace(ori.l);
    Line now, next;
    while(!state.empty()){
        now = state.front();
        state.pop();
        if(now == target)
            return now.moves;
            
        //shift
        next = now;
        next.turn();
        if(hasbeen.find(next.l) == hasbeen.end()){
            next.moves++;
            hasbeen.emplace(next.l);
            state.push(next);
        }
        
        //change
        for(int i = 0; i < 7; i++){
            next = now;
            next.change(i);
            if(hasbeen.find(next.l) == hasbeen.end()){
                next.moves++;
                hasbeen.emplace(next.l);
                state.push(next);
            }
        }
        
        //sort
        if(!now.sorted){
            for(int i = 0; i < 7; i++){
                for(int j = i + 1;j <= 8;j++){
                    next = now;
                    next.sortp(i, j);
                    //cout << next << "\n";
                    if(hasbeen.find(next.l) == hasbeen.end()){
                        next.moves++;
                        hasbeen.emplace(next.l);
                        state.push(next);
                    }
                }
            }
        }
    }
    return -1;
}

