func totalFruit(fruits []int) int {

    fruitMap := make(map[int]int)
    l:=0
    r:=0
    maxFruits :=0

    for r< len(fruits){
        fruitMap[fruits[r]]++

        if len(fruitMap) >2{
            fruitMap[fruits[l]]--
            if  fruitMap[fruits[l]] ==0{
                delete(fruitMap, fruits[l])
            }
            l++
        }
        if len(fruitMap) <=2{
            maxFruits = max(maxFruits, r-l+1)
        }
        r++
    }
    return maxFruits
}