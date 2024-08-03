func maximumLengthSubstring(s string) int {
    var l,r,maxLen,exceedCount int =0, 0, 0, 0

    charCountMap:= make(map[string]int)

    for r<2 {
        value, exists := charCountMap[string(s[r])]
        if exists {
            value++
            charCountMap[string(s[r])] = value
        }else{
           charCountMap[string(s[r])] = 1
        }
        maxLen++
        r++
    }
    for r< len(s){
        value, exists := charCountMap[string(s[r])]
        if exists {
            value++
            charCountMap[string(s[r])] = value
            if charCountMap[string(s[r])] ==3{
                exceedCount++
            }
        }else{
           charCountMap[string(s[r])] = 1
        }

        if(exceedCount>0){
            charCountMap[string(s[l])]--
            if charCountMap[string(s[l])] ==2 {
                exceedCount--
            }
            l++
        }else{
            maxLen = maxInt(maxLen,r-l+1)
        }
        r++
        
    }
    return maxLen


}

func maxInt(a, b int) int {
    if a > b {
        return a
    }
    return b
}