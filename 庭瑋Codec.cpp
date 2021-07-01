#include"function.h"
#include<string>
using namespace std;

string BaseCodec::encode(const string& ip){
    return ip;
}

class RcodeC : public BaseCodec{
public:
    ~RcodeC(){};
    string encode(const string& ip) override{
        string rt;
        for(int i = ip.length() - 1; i >= 0; i--){
            rt.push_back(ip[i]);
        }
        return rt;
    }
};

/*string RcodeC::encode(string& ip){
    return ip;
}*/

class CcodeC : public virtual BaseCodec{
public:
    ~CcodeC(){};

    string encode(const string& ip) override{
        int cnt = 1;
        char nowC = ip[0];
        string rt;
        for(int i = 1; i < ip.length(); i++){
            if(nowC != ip[i]){
                if(cnt > 2)
                    rt = rt + to_string(cnt) + nowC;
                else{
                    while(cnt--)
                        rt += nowC;
                }
                nowC = ip[i];
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        if(cnt > 2)
            rt = rt + to_string(cnt) + nowC;
        else{
            while(cnt--)
                rt += nowC;
        }
        return rt;
    }
};

class DcodeC : public virtual BaseCodec{
private:
    string prev;
public:
    ~DcodeC(){};

    string encode(const string& ip){
        string rt;
        if(prev == ""){
            prev = ip;
            rt = "None";
        }
        else{
            rt = prev;
            prev = ip;
        }
        return rt;
    }
};

BaseCodec* getCodec(const std::string& name){
    BaseCodec* rt = nullptr;

    if(name == "Reverse"){
        rt = new RcodeC;
    }
    else if(name == "Compress"){
        rt = new CcodeC;
    }
    else if(name == "Delay"){
        rt = new DcodeC;
    }
    return rt;
}
