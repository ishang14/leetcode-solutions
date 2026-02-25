class Solution {
public:
    #define pp pair<int,int>
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        for(int i=0;i<arr.size();i++){
            int bit=__builtin_popcount(arr[i]);
            pq.push({bit,arr[i]});
        }

        int i=0;
        while(pq.size()){
            arr[i]=pq.top().second;
            pq.pop();
            i++;
        }

        return arr;
    }
};