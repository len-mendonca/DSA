class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;
        unordered_map<char,int>sub;
        for(int i=0;i<p.length();i++){
            if(sub.count(p[i])){
                sub[p[i]]++;
            }else{
                sub[p[i]]=1;
            }
        }
        int count = sub.size();
        int i=0,j=0;
        while(j<s.size()){
            if(sub.count(s[j])){
                sub[s[j]]--;
                if(sub[s[j]]==0){
                    count--;
                }
            }
            if(j-i+1<p.size()){
                j++;
            }else if(j-i+1 == p.size()){
                if(count==0){
                    ans.push_back(i);
                }
                if(sub.count(s[i])){
                    sub[s[i]]++;
                    if(sub[s[i]] ==1){
                        count++;
                    }
                }
                i++;
                j++;
            }


        }
        return ans;

    }
};