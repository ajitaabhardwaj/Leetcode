class Solution {
public:
    int candy(vector<int>& r) 
    {
        int total = 0;
        int count = 0;
        vector<int> candies(r.size(), 1);
        if(candies.size() ==1 )
        {
            return 1;
        }
        
        for(int i=1; i<r.size()-1; i++)
        {
            if(r[i]>r[i-1] && candies[i]<=candies[i-1])
            {
                    candies[i] = candies[i-1]+1;
            }
            if(r[i]>r[i+1] && candies[i]<=candies[i+1])
            {
                candies[i] = candies[i+1]+1;
            }
        }

        for(int i=candies.size()-2; i>0; i--)
        {
            if(r[i]>r[i-1] && candies[i]<=candies[i-1])
            {
                    candies[i] = candies[i-1]+1;
            }
            if(r[i]>r[i+1] && candies[i]<=candies[i+1])
            {
                candies[i] = candies[i+1]+1;
            }
        }
        for(int i=0; i<candies.size(); i++)
        {
            total = total+candies[i];
        }

        if(r[candies.size()-1]>r[candies.size()-2] && candies[candies.size()-1]<=candies[candies.size()-2])
        {
            total = total + (candies[candies.size()-2]- candies[candies.size()-1]) +1;
        }
        if(r[0]>r[1] && candies[0]<=candies[1])
        {
            total = total+ (candies[1] - candies[0]) +1;
        }
        return total;
    }
};