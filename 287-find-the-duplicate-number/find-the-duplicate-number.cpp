class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        //Phase1-Detect the cycle by moving slow 1 step and fast 2step a time
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        //Phase 2-Once the cycle is detected change fast to start
        fast=nums[0];
        //Phase 3-Then move slow and fast 1 step a time and the point where the collide is the duplicate
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};