#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<stddef.h>
void qsort (void* base, size_t num, size_t size, int (*compar)(const void*, const void*))
{
    std::cout << "Please don't cheat.\n";
}
template <class RandomAccessIterator> 
void sort (RandomAccessIterator first, RandomAccessIterator last)
{
    std::cout << "Please don't cheat.\n";
}
template <class RandomAccessIterator, class Compare> 
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    std::cout << "Please don't cheat.\n";
}

template < class T >
void mysort(T arr[], int l, int r);

void solve();

long long left[200010];
long long right[200010];

int main(void) {
    int T;
    std::cin >> T;    
    
    // Handle multiple cases
    while (T--) {
        // use the funtion to read input, process data, and output answers.
        solve();
    }
    return 0;
}
void printinfor(int l,int r){
	int i;
	printf("left[]=");
	for(i=0;i<l;i++){
		printf("%lld,",left[i]);
	}
	printf("\nright[]=");
	for(i=0;i<r;i++){
		printf("%lld,",right[i]);
	}
	printf("\n");
}

template < class T >
void mysort(T arr[], int l, int r){	//quicksort
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
		
	//先比兩邊有沒有一樣的pair
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
	
	//同邊手套看有沒有pair，看哪邊的手套比較多就去比哪邊，比到兩邊的數量一樣為止
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
