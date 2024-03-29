#include<bits/stdc++.h>
using namespace std;
struct seg{
	int left,right;
	seg(int l,int r):left(l),right(r){}
};
struct cmp{
	bool operator()(const seg& lhs,const seg& rhs) const {
		int l_len=(lhs.right-lhs.left)/2;
		int r_len=(rhs.right-rhs.left)/2;
		if(l_len!=r_len){
			return l_len>r_len;
		}else{
			return lhs.left<rhs.left;
		}
	}
};
int main(){
	int i;
	char cmd;
	int n,m,s,x,d;
	
	set<int> pos;	//為了取出鄰居
	set<seg,cmp> segment;
	vector<int> seat;
	
	cin>>n>>m>>s;
	d=n+1;	//INF
	seat.resize(m+1,1);	//將vector的大小變成m+1
	
	pos.insert(0);	//wall也要insert進去，不然在移除第一個人的時候it++,it--時可能會取不到wall的idx，造成RE
	pos.insert(n+1);
	segment.insert(seg(0,n+1));	//一開始的segment
	
	for(i=0;i<2*m;i++){
		cin>>cmd>>x;
		if(cmd=='i'){
			auto it=segment.begin();	//因為set有按照cmp排序，所以取出的第一個元素一定是len最大
			int l=it->left,r=it->right;
			int mid=(l+r)/2;	//決定他要坐哪
			
			//當這個segment其中一邊是wall一邊是人 || 兩邊�m是人就要更新distance
			if(l!=0){
				d=min(mid-l,d);
			}
			if(r!=n+1){
				d=min(r-mid,d);
			}
			
			segment.erase(it);
			segment.insert(seg(l,mid));
			segment.insert(seg(mid,r));
			seat[x]=mid;
			pos.insert(mid);
		}else{
			int mid=seat[x];	//找出id=x這個人坐在哪裡
			
			auto it=pos.find(mid);	//用pos找他的鄰居
			auto left_it=it,right_it=it;
			int left=*(--left_it);
			int right=*(++right_it);
			
			segment.erase(seg(left,mid));
			segment.erase(seg(mid,right));
			segment.insert(seg(left,right));
			seat[x]=-1;
			pos.erase(mid);
		}
	}
	
	if(d>=s){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
	if(d==n+1){
		cout<<"INF\n";
	}else{
		cout<<d<<"\n";
	}

	return 0;
}
