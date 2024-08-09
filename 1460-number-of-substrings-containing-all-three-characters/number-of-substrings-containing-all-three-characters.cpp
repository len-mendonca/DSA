class Solution {
public:
    int numberOfSubstrings(string s) {
        int recentABCpositions[3] ={-1,-1,-1};
        int count=0;

        for(int i=0;i<s.size();i++){
            recentABCpositions[s[i]-'a'] = i;

            if(recentABCpositions[0]!=-1 && recentABCpositions[1]!=-1 && recentABCpositions[2]!=-1){
                count += (min(recentABCpositions[0],min(recentABCpositions[1],recentABCpositions[2]))+1);
            }

        }
        return count;
    }
};