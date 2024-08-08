class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxFruits=0;
        unordered_map<int,int>fruitCount;

        while(r<fruits.size()){
            fruitCount[fruits[r]]++;

            if(fruitCount.size()>2){
                fruitCount[fruits[l]]--;
                if(fruitCount[fruits[l]]==0){
                    fruitCount.erase(fruits[l]);
                }
                l++;
            }
            if(fruitCount.size()<=2){
                maxFruits = max(maxFruits,r-l+1);
            }
            r++;
        }
        return maxFruits;
    }
};


