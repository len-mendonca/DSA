class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0,r=0,maxlen=0,countExceed=0;
        unordered_map<char, int> charCountMap;
        while(r<2){
            auto it = charCountMap.find(s[r]);
            if(it != charCountMap.end()){
                it->second++;
            }else{
                charCountMap[s[r]] =1;
            }
            maxlen++;
            r++;
        }
        while(r<s.size()){
            auto it = charCountMap.find(s[r]);
            if(it != charCountMap.end()){
                it->second++;
                if(it->second==3){
                    countExceed++;
                }
            }else{
                charCountMap[s[r]] =1;
            }
            if(countExceed>0){
                it = charCountMap.find(s[l]);
                it->second--;
                if(it->second ==2){
                    countExceed --;
                }
                l++;
            }else{
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};