class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int> ans;
        unordered_map<char,int>sub; //stores unique char of substring p in map
        for(int i=0;i<p.length();i++){ //assigns the occurences of each char in map
            if(sub.count(p[i])){
                sub[p[i]]++;
            }else{
                sub[p[i]]=1;
            }
        }
        int count = sub.size(); //when count is 0, it is an anagram
        int i=0,j=0;
        while(j<s.size()){  //finding out the number of anagrams
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
                    ans.push_back(i); //pushing the index into the result
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
