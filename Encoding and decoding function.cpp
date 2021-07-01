#include<iostream>
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

class Codec{
public:
    virtual void encode()=0;
    virtual void decode()=0;
    virtual ~Codec(){}	// Do nothing
    virtual void show(std::ostream& os) const=0;
    virtual bool is_encoded() const=0;
};
class RleCodec : public Codec {
public:
    RleCodec(std::string s):encoded{false},code_str{s}{}

    void encode();
    void decode();

    void show(std::ostream& os) const{
        os << code_str;
    }
    bool is_encoded() const{ return encoded; }
private:
    bool encoded;
    std::string code_str;
};

void RleCodec::encode(){
	int i,j,k;
	int len=code_str.length();
	string str;
	for(i=0;i<len;){
		int cnt=1;
		for(j=i+1;j<len;j++){
			if(code_str[i]==code_str[j]){
				cnt++;
			}else{
				break;
			}
		}
		//printf("cnt=%d,i=%d,j=%d\n",cnt,i,j);
		for(k=cnt;k>0;k-=26){
			str.push_back('Q');
			if(k>26){
				str.push_back('Z');
			}else{
				str.push_back('A'+k-1);
			}
			str.push_back(code_str[i]);
		}
		i=j;
	}
	code_str=str;
	str.clear();
	encoded=true;
}

void RleCodec::decode(){
	std::stringstream os;
	std::string int_str;
	char q = 'A';
	char number = ' ';
	int cnt = 0;
	for (auto c : code_str) {
        if (q=='A') {
            q = c;
		}else if(number == ' '){
            number = c;
		}else{
            int_str.push_back(c);
			int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
					os << c;
			int_str.clear();
			number = ' ';
			q = 'A';
		}
	}

	code_str = os.str();
	encoded = false;
}
