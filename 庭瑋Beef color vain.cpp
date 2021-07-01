#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

long long seq[100010];
//int used[100010];
char expr[1000010];
long long poly[100010];
long long power[1000010];
long long p, q;
int N, M, posA;
long long valTo;

long long makePow(int pow){
    static int cur = 0;
    long long ans = 0;
    if(expr[cur] == '\0')
        return ans;

    int position = -1;
    if(expr[cur] == 'f'){
        cur++;
        while(expr[cur] == '(' || expr[cur] == ',' || expr[cur] == ')')
            cur++;
        long long l = makePow(pow+1);

        while(expr[cur] == '(' || expr[cur] == ',' || expr[cur] == ')')
            cur++;
        long long r = makePow(pow);

        while(expr[cur] == '(' || expr[cur] == ',' || expr[cur] == ')')
            cur++;

        ans = ((l * p) + r) % q;
        return ans;
    }
    else if(isdigit(expr[cur])){
        position = 0;
        while(isdigit(expr[cur])){
            position = position * 10 + expr[cur]-'0';
            cur++;
        }
        //poly: seq[i] * ?
        //full poly: seq[i] * poly[i]

        poly[position] = (poly[position] + power[pow]) % q;
        ans = seq[position] % q;
        return ans;
    }
    return 0;
}

int main(){

    scanf("%d%d%d",&p,&q,&N);
    p %= q;
    seq[0] = -1;
    for(int i = 1; i <= N; i++)
        poly[i] = 0;

    for(int i = 1; i <= N;i++)
        scanf("%d",&seq[i]);
    scanf("%s%d",expr,&M);
    for(int i = 0; i < 1000010; i++){
        if(i == 0) power[i] = 1;
        else power[i] = (power[i-1] * p) % q;
    }

    //example
    //there may be Ai at p^6 and p^2
    //so poly cannot only record the highest power
    //=> poly[position] = p^6 + p^2

    //full polynominl = sum(Ai * poly[i])

    long long ans = makePow(0);

    while(M--){
        scanf("%d%lld",&posA, &valTo);
        valTo %= q;
        if(valTo == (seq[posA] % q)){
            seq[posA] = valTo;
            printf("%d\n",ans);
            continue;
        }
        else{
            //quick pow, but not used
            /*long long temp = 1, P = p;
            for(long long B = poly[posA]; B; B >>= 1){
                if(B & 1) temp*=P;
                P = (P * P) % q;
                temp %= q;
            }*/

            //original: seq[i]*poly[i]
            //new: valTo*poly[i]
            //=> ans - seq*poly + valTo*poly
            //may < 0 => +q
            ans = (ans - seq[posA] * poly[posA] % q + valTo * poly[posA] % q + q) % q;
            seq[posA] = valTo;
            printf("%d\n",ans);
        }
    }
    return 0;
}
