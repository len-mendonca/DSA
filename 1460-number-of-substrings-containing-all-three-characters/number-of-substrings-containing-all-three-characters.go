func numberOfSubstrings(s string) int {
    recentABCpositions := [3]int{-1,-1,-1}
    count:=0
    
    for i:=0;i<len(s);i++ {
        recentABCpositions[s[i] -'a'] =i

        if(recentABCpositions[0] != -1 && recentABCpositions[1] != -1 && recentABCpositions[2] != -1){
            count += min(recentABCpositions[0],recentABCpositions[1],recentABCpositions[2])+1
        }
    }
    return count
}