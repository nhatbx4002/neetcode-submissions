class Solution {
public:

    bool checkHourValid(vector<int>& piles, int k , int h){
        long long total_hours = 0 ; 

        for(int pile : piles){
            total_hours += (pile + k - 1)/k;
        }

        return (total_hours <= h);

    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int res = 0 ;

        int left = 1 ; 
        int right = *max_element(piles.begin(), piles.end());

        while(left <= right){
            
            int mid = left + (right - left)/2;

            if(checkHourValid(piles,mid,h)){
                res = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return res;
    }
};
