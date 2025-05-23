class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum=accumulate(milestones.begin(), milestones.end(), 0LL);
        long long max=*max_element(milestones.begin(), milestones.end());
        long long remaining=sum-max;
        if(remaining>=max-1)
        {
            return sum;
        }else{
            return(2*remaining+1);
        }
    }
};