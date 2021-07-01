#include<stdio.h>
int main(void){
	/*i,j,w:迴圈變數
	n個數字
	幫他q次
	*/
    int i, j, w, n, q;
    scanf("%d",&n);
    /*arr1:記錄菜色
	arr2:記錄菜色出現次數
	arr3:記錄有同樣最小值的菜色號碼 
	*/ 
    int arr1[n], arr2[n], arr3[n];
	
    for(i = 0; i < n; i ++)
        scanf("%d", &arr1[i]);
        
    scanf("%d", &q);
    //幫他q次 
    for(w = 0; w < q; w ++){
        int a, b, k = 0;//a:左端點,b:右端點,k:陣列的index 
        scanf("%d %d", &a, &b);
		//初始化 
        for(i = 0; i < n; i ++){
        	arr2[i] = 0;
        	arr3[i] = 0;
    	}
    	//比較每個數字出現幾次，並記錄到arr2裡面 
        for(i = a-1; i < b; i ++){
            for(j = a - 1; j < b; j ++){
                if(arr1[i] == arr1[j]){
                    arr2[i] ++;
                }
            }
        }
        //將arr2的第一個數字指定給max 
        int max = arr2[0];
        for(i = 0; i < n; i ++){
            if(arr2[i] > max){
                max = arr2[i];//如果arr2的數字比max還大就更新max 
            }
        }
        
        for(i = 0; i < n; i ++){
            if(arr2[i] == max){
                arr3[k] = arr1[i];//將擁有相同最小值的菜色號記錄到arr3裡面 
                k ++;//k記得更新 
            }
        }
        
        int min = arr3[0];//將arr3的第一個菜色號指定給min 
        for(i = 0; i < k; i ++){
            if(arr3[i] < min){
                min = arr3[i];//如果arr3的菜色號比min還小就更新min 
            }
        }
		printf("%d\n",min);			
    }
    return 0;
}
