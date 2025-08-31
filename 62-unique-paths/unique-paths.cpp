class Solution {
public:
    int uniquePaths(int m, int n) {
        int N=m+n-2;
        int r=min(m,n);
        double res=1;
        for(int i=1;i<r;i++){
            res=res*(N--)/i;
        }
        return (int)res;
    }
};