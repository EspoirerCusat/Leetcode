class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int r){
        int a1[mid-l+1];
        int a2[r-mid];
        int n1 = mid-l+1; int n2 = r-mid;
        int idx = 0;
        for(int i=l; i<=mid; i++) a1[idx++] = nums[i];
        idx = 0;
        for(int i=mid+1; i<=r; i++) a2[idx++] = nums[i];
        
        //merge
        int jdx = l;
        int i = 0; int j = 0;
        while(i < n1 && j < n2){
            if(a1[i] < a2[j]){
                nums[jdx++] = a1[i++]; 
            }else{
                nums[jdx++] = a2[j++];
            }
        }
        //bacha hua
        while(i < n1){
            nums[jdx++] = a1[i++];
        }
        while(j < n2){
            nums[jdx++] = a2[j++];
        }
    }
    void mergeSort(vector<int>& nums, int l, int r){
        if(l >= r) return;
        
        int mid = l + (r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        
        //merge
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};