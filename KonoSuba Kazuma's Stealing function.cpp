#include<bits/stdc++.h>
// TODO: Implement the sorting algorithm
template < class T >
void mysort(T arr[], int l, int r);
// TODO: Implement the funtion to read input, process data, and output answers.
void solve();

long long left[200010];
long long right[200010];

// TODO: Implement the sorting algorithm
template < class T >
void mysort(T arr[], int l, int r){
	if(l<r){
		int i=l,j=r+1,pivot=arr[l];
		do{
			do{
				i++;
			}while(arr[i]>pivot);
			do{
				j--;
			}while(arr[j]<pivot);
			if(i<j){
				std::swap(arr[i],arr[j]);
			}
		}while(i<j);
		std::swap(arr[l],arr[j]);
		mysort(arr,l,j-1);
		mysort(arr,j+1,r);
	}
} 
// TODO: Implement the funtion to read input, process data, and output answers.
void solve(){
	int i,j;
	long long n,l,r,cost;
	long long left_l,left_r,mid;
	long long ans=0;
	
	scanf("%lld%lld%lld%lld",&n,&l,&r,&cost);
	for(i=0;i<l;i++){
		scanf("%lld",&left[i]);
	}
	for(i=0;i<r;i++){
		scanf("%lld",&right[i]);
	}
	
	mysort(left,0,l-1);
	mysort(right,0,r-1);
		
	//先比兩邊有沒有一樣的
	left_l=l,left_r=r;
	i=0,j=0;
	while(i<l && j<r){
		if(left[i]>right[j]){
			i++;
		}else if(left[i]<right[j]){
			j++;
		}else{
			left[i]=right[j]=0;
			i++,j++;
			left_l--,left_r--;
		}
	}
	
	//比完兩邊再sort一次
	mysort(left,0,l-1);
	mysort(right,0,r-1);
	
	//看哪邊的手套比較多就去比哪邊，比到兩邊的數量一樣為止
	if(left_l>left_r){
		i=0;
		while(i<l-1 && left_l>left_r){			
			if(left[i]==left[i+1] && left[i]!=0){
				left[i]=left[i+1]=0;
				left_l-=2;
				i+=2;
				ans+=cost;
			}else{
				i++;
			}
		}
	}else if(left_l<left_r){
		i=0;
		while(i<r-1 && left_r>left_l){			
			if(right[i]==right[i+1] && right[i]!=0){
				right[i]=right[i+1]=0;
				left_r-=2;
				i+=2;
				ans+=cost;
			}else{
				i++;
			}
		}
	}
	
	mid=(left_l+left_r)/2;	//平分手套
	ans+=abs(mid-left_l)*cost;	//平分手套的$
	ans+=mid*cost;	//改成一樣的$
	
	printf("%lld\n",ans);
}
