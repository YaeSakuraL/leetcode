#include <iostream>
#include <vector>
#include<numeric>
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> candy(ratings.size(), 1);
        for(int i=0;i<ratings.size()-1;i++){
            if(ratings[i+1]>ratings[i])
            {
                candy[i+1]=candy[i]+1;
            }
        }
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i])
            {
                candy[i-1]=std::max(candy[i]+1,candy[i-1]);
            }
        }
        return std::accumulate(candy.begin(),candy.end(),0);
    }
};

int main()
{
    Solution s;
    std::vector<int> ratings{1,2,87,87,87,2,1};
    std::cout<<s.candy(ratings)<<std::endl;
    return 0;
}