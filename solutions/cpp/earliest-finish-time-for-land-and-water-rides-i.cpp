class Solution {
public:
    int earliestFinishTime(vector<int>& A1, vector<int>& A2, vector<int>& B1, vector<int>& B2) {
        int min=0;
        int mini=INT_MAX;
        for(int i=0;i<A1.size();i++){
          int s=A1[i]+A2[i];
            for(int j=0;j<B1.size();j++){
                if(s>=B1[j])
                    min=s+B2[j];
                else
                    min=B1[j]+B2[j];
                if(min<mini)
                        mini=min;
            }
        }
        for(int i=0;i<B1.size();i++){
          int s=B1[i]+B2[i];
            for(int j=0;j<A1.size();j++){
                if(s>=A1[j])
                    min=s+A2[j];
                else
                   min=A1[j]+A2[j];        
                if(min<mini)
                        mini=min;
            }
        }
        return mini;
    }
};