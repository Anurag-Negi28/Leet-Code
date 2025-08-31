class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*
        vector<int> res;
        map<int,int> mp;
        int n=nums.size();
        int count=(int)(n/3)+1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==count) res.push_back(nums[i]);
            if(res.size()==2) break;
        }
        return res;
        */

        //Optimal Approach Moore's Voting Algorithm
        int n=nums.size();
        vector<int> res;
        int cnt1=0;int cnt2=0;
        int el1=INT_MIN;int el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                cnt1=1;
                el1=nums[i];
            }else if(cnt2==0 && nums[i]!=el1){
                cnt2=1;
                el2=nums[i];
            }else if(el1==nums[i]){
                cnt1++;
            }else if(el2==nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt3=0;int cnt4=0;
        for(int i=0;i<n;i++){
            if(el1==nums[i]) cnt3++; 
            if(el2==nums[i]) cnt4++; 
        }
        if(cnt3>(int)(n/3)) res.push_back(el1);
        if(cnt4>(int)(n/3)) res.push_back(el2);
        return res;
    }
};