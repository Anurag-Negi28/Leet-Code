class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto& p:mp){
            if(p.second>(n/2)) return p.first;
        }
        return 0;
        */

        //Boyer Moore Majority Voting Algorithm
         int n=nums.size();
         int cnt=0;
         int el;
         for(int i =0;i<=n-1;i++){
            if(cnt==0){
                cnt=1;
                el=nums[i];
            }
            else if(el==nums[i]){
                cnt++;
            }else{
                cnt--;
            }
         }
         int cnt1=0;
         for(int i=0;i<n;i++){
            if(el==nums[i]) cnt1++;
         }
         if(cnt1>(int)(n/2)) return el;
         return -1;
    }
};