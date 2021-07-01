#include<bits/stdc++.h>
using namespace std;
struct state{
    int lv,hp,mhp,dist;
    state(int lv,int hp,int mhp,int dist=0):lv(lv),hp(hp),mhp(mhp),dist(dist){}
};
bool visited[20][310][410];
int main(){
    int i;
    int lv,hp,mhp,mdmg;
    int damage[20],heal[20];

    cin>>lv>>hp>>mhp>>mdmg;
    for(i=1;i<=lv;i++){
        cin>>damage[i]>>heal[i];
    }

    queue<state> q;
    q.push(state(1,hp,mhp));
    while(!q.empty()){
        state s=q.front();
        //printf("monster hp=%d\n",s.mhp);
        if(s.mhp==0){
            break;
        }
        q.pop();

        //level up
        if(s.hp-mdmg>0 && s.lv<lv){ //還沒到最後一關 && 還沒被怪物打死
            state t(s.lv+1 , s.hp-mdmg , s.mhp , s.dist+1);
            if(!visited[t.lv][t.hp][t.mhp]){
                visited[t.lv][t.hp][t.mhp]=true;
                q.push(t);
            }
        }
        //attack
        if(s.hp-mdmg>0 || s.mhp-damage[s.lv]<=0){
            state t(s.lv , s.hp-mdmg , max(0,s.mhp-damage[s.lv]) , s.dist+1);
            if(!visited[t.lv][t.hp][t.mhp]){
                visited[t.lv][t.hp][t.mhp]=true;
                q.push(t);
            }
        }
        //heal
        if(s.hp-mdmg>0 && heal[s.lv]>mdmg){
            state t(s.lv , min(hp,s.hp+heal[s.lv])-mdmg , s.mhp , s.dist+1);
            if(!visited[t.lv][t.hp][t.mhp]){
                visited[t.lv][t.hp][t.mhp]=true;
                q.push(t);
            }
        }
    }



    if(q.empty()){
        cout<<"-1\n";
    }else{
        cout<<q.front().dist<<"\n";
    }
    return 0;
}
