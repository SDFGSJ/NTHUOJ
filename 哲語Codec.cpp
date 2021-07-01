#include <iostream>
#include <vector>
#include <string>
#include "function.h"
using namespace std;


class ReverseCodec:public BaseCodec{
public:
    string encode(const std::string& cmp){
        int len=cmp.length();
        string ans="";
        for(int i=len-1;i>=0;i--){
            ans+=cmp[i];
        }
        return ans;
    }
    string str;
};
class CompressCodec:public BaseCodec{
public:
     string encode(const std::string& cmp){
         int len=cmp.length();
         int cnt=0;
         string ans="";
         char tem=cmp[0];
         for(int i=0;i<len;i++){
            if(cmp[i]==tem){
                cnt++;
            }
            else{
                if(cnt<=2){
                    for(int j=0;j<cnt;j++){
                        ans+=tem;
                    }
                    cnt=1;
                    tem=cmp[i];
                }
                else{
                    int cp=0;
                    int tem_num=cnt;
                    char st[1000];
                    while(tem_num>0){
                        st[cp]=tem_num%10+'0';
                        cp++;
                        tem_num=tem_num/10;
                    }
                    for(int j=cp-1;j>=0;j--){
                        ans+=st[j];
                    }
                    ans+=tem;
                    tem=cmp[i];
                    cnt=1;
                }
            }
         }
         if(cnt<=2){
                for(int j=0;j<cnt;j++){
                    ans+=tem;
                }
        }
        else{
                    int cp=0;
                    int tem_num=cnt;
                    char st[1000];
                    while(tem_num>0){
                        st[cp]=tem_num%10+'0';
                        cp++;
                        tem_num=tem_num/10;
                    }
                    for(int j=cp-1;j>=0;j--){
                        ans+=st[j];
                    }
                    ans+=tem;
                }
            return ans;
     }
    string str;
};
class DelayCodec:public BaseCodec{
public:
    string encode(const std::string& cmp){
        if(cnt==0){
            cnt=1;
            store=cmp;
            return "None";
        }
        else{
            string temm=store;
            store=cmp;
            return temm;
        }
    }
    string store;
    int cnt=0;
};
BaseCodec* getCodec(const std::string& name){
    BaseCodec* n;
    if(name=="Reverse")
        n=new ReverseCodec;
    else if(name=="Compress")
        n=new CompressCodec;
    else if(name=="Delay")
        n=new DelayCodec;
    return n;
}
