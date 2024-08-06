func maxScore(cardPoints []int, k int) int {
      sum:=0;
         maxSum:=0;
         rIndex := len(cardPoints) -1; 
        for lIndex:=0;lIndex<k;lIndex++{
            sum+=cardPoints[lIndex];
        }
        maxSum = sum;
        
        for lIndex:=k-1;lIndex>=0;lIndex--{
            sum = sum - cardPoints[lIndex];
            sum = sum+ cardPoints[rIndex];
            maxSum = max(maxSum,sum);
            rIndex--;
        }

        return maxSum;

}

func max(a,b int)int{
    if a>b{
        return a;
    }
    return b;
}