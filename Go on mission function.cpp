#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
class BigInt
{
private:
    constexpr static int N = 150;
    constexpr static int WIDTH = 8, BASE = 100000000;
    bool sign;	//true+,false- 
    int bigInt[N];	//–柑常8计程150
public:
    // constructor
    BigInt();
    BigInt(char*);
    BigInt(const BigInt&);
    
    // copy assignment operator
    BigInt &operator = (const BigInt&);
    
    // comparison operator
    bool operator < (BigInt);
    bool operator > (BigInt);
    bool operator == (BigInt);
    bool operator >= (BigInt);
    bool operator <= (BigInt);
    
    // arithmetic operator
    BigInt operator + (BigInt);
    BigInt operator - (BigInt);
    
    // insertion & extraction operator
    friend istream& operator >> (istream&, BigInt&);
    friend ostream& operator << (ostream&, BigInt&);
};
// constructor
BigInt::BigInt():sign(true){
	int i;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
}
BigInt::BigInt(char* str):sign(true){
	int i,j;
	for(i=0;i<N;i++){
		bigInt[i]=0;
	}
	
	int len=strlen(str);
	int bigint_idx=0;
	for(i=len-1;i>7;i-=8){	//眖ゑ耕计–8计秨﹍矪瞶
		int n=0;
		for(j=i-7;j<=i;j++){
			n=n*10+str[j]-'0';
		}
		bigInt[bigint_idx++]=n;
	}
	
	int n=0;	//矪瞶逞ぃ骸8计
	for(j=0;j<=i;j++){
		n=n*10+str[j]-'0';
	}
	bigInt[bigint_idx]=n;
}
BigInt::BigInt(const BigInt& bi){
	*this=bi;
}
// copy assignment operator
BigInt& BigInt::operator = (const BigInt& bi){
	if(this == &bi){	//狦琌ン碞钡return
		return *this;
	}
	
	int i;
	sign=bi.sign;
	for(i=0;i<N;i++){
		bigInt[i]=bi.bigInt[i];
	}
	return *this;
}
// comparison operator
bool BigInt::operator < (BigInt right){	//this < right(?)
	int i;
	if(sign==true && right.sign==false){	//+ < -
		return false;
	}else if(sign==false && right.sign==true){	//- < +
		return true;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//眖程蔼计秨﹍ゑ
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return true;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//眖程蔼计秨﹍ゑ
			if(bigInt[i] > right.bigInt[i]){	//猔種璽腹:this < right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//猔種璽腹:this > right
				return false;
			}
		}
	}
	
	//Ч单
	return false;
}
bool BigInt::operator > (BigInt right){	//this > right(?)
	int i;
	if(sign==true && right.sign==false){	//+ > -
		return true;
	}else if(sign==false && right.sign==true){	//- > +
		return false;
	}else if(sign==true && right.sign==true){	//+ +
		for(i=N-1;i>=0;i--){	//眖程蔼计秨﹍ゑ
			if(bigInt[i] > right.bigInt[i]){	//this > right
				return true;
			}else if(bigInt[i] < right.bigInt[i]){	//this < right
				return false;
			}
		}
	}else if(sign==false && right.sign==false){	//- -
		for(i=N-1;i>=0;i--){	//眖程蔼计秨﹍ゑ
			if(bigInt[i] > right.bigInt[i]){	//猔種璽腹:this < right
				return false;
			}else if(bigInt[i] < right.bigInt[i]){	//猔種璽腹:this > right
				return true;
			}
		}
	}
	
	//Ч单
	return false;
}
bool BigInt::operator == (BigInt right){
	int i;
	if(sign!=right.sign){	//才腹ぃ妓荡癸ぃ妓
		return false;
	}
	for(i=N-1;i>=0;i--){
		if(bigInt[i]!=right.bigInt[i]){
			return false;
		}
	}
	return true;
}
bool BigInt::operator >= (BigInt right){
	if(*this > right || *this == right){
		return true;
	}else{
		return false;
	}
}
bool BigInt::operator <= (BigInt right){
	if(*this < right || *this == right){
		return true;
	}else{
		return false;
	}
}
// arithmetic operator
BigInt BigInt::operator + (BigInt right){
	int i;
	BigInt ans;	//bigint
	for(i=0;i<N;i++){	//眖ゑ耕计秨﹍+
		ans.bigInt[i] = bigInt[i] + right.bigInt[i];
		if(ans.bigInt[i] >= BASE){	//秈
			ans.bigInt[i]-=BASE;
			bigInt[i+1]+=1;	//ぃ糶Θans.bigInt[i+1]+=1伴癹伴穦э奔硂1
		}
	}
	return ans;
}
BigInt BigInt::operator - (BigInt right){	//this - right(right>=0)
	int i;
	BigInt ans;
	if(sign==true){	//this > 0
		if(*this==right){
			ans.sign=true;
			for(i=0;i<N;i++){
				ans.bigInt[i]=0;
			}
		}else if(*this > right){
			ans.sign=true;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					ans.bigInt[i] = bigInt[i] - right.bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + bigInt[i] - right.bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}else if(*this < right){	//跑Θright - this
			ans.sign=false;
			for(i=0;i<N;i++){
				if(bigInt[i] > right.bigInt[i]){
					right.bigInt[i+1]-=1;
					ans.bigInt[i] = BASE + right.bigInt[i] - bigInt[i];
				}else if(bigInt[i] < right.bigInt[i]){
					ans.bigInt[i] = right.bigInt[i] - bigInt[i];
				}else{
					ans.bigInt[i]=0;
				}
			}
		}
	}else{	//-a-b=-(a+b)
		//猔種硂ㄢ︽抖+穦㊣default constructor眖τㄏ眔sign跑true碞穦WA
		ans = *this + right;
		ans.sign = false;
	}
	return ans;
}
// insertion & extraction operator
istream& operator >> (istream& input,BigInt& num){
	char str[1205];
	cin>>str;
	num=BigInt(str);	//ノcopy constructor
	return input;
}
ostream& operator << (ostream& output,BigInt& num){
	int i;
	if(num.sign==false){
		cout<<"-";
	}
	bool start=false;
	bool first=true;
	for(i=149;i>=0;i--){
		if(num.bigInt[i]!=0){	//笿材獶0计碞秨﹍
			start=true;
		}
		if(start){
			if(first){	//笿材獶0计钡ㄓぃノ恨setwidth,setfill
				cout<<num.bigInt[i];
				first=false;
			}else{	//逞计Τぃ骸8计┮璶setwidth,setfill
				cout<<setw(8)<<setfill('0')<<num.bigInt[i];
			}
		}
	}
	
	//狦bigInt皚场常琌0璶肂矪瞶
	if(!start){
		cout<<"0";
	}
	
	return output;
}

void solution(BigInt &tanjiro, BigInt &zenitsu, BigInt &inosuke, int n){
	int i;
	for(i=0;i<n;i++){
		BigInt mission;
		cin>>mission;
		if(inosuke>=tanjiro && inosuke>=zenitsu){
			inosuke = inosuke - mission;
		}else if(tanjiro>=zenitsu && tanjiro>=inosuke){
			tanjiro = tanjiro - mission;
		}else if(zenitsu>=tanjiro && zenitsu>=inosuke){
			zenitsu = zenitsu - mission;
		}
	}
}
