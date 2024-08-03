func searchMatrix(matrix [][]int, target int) bool {
    if len(matrix)==0 || len(matrix[0]) == 0{
        return false
    }

    start:= 0
     var rows int = len(matrix)
    var cols int = len(matrix[0])

    end:= rows*cols -1

    for start<=end{
        mid:= (start+end)/2
        midX:= mid/cols
        midY:= mid%cols
        if matrix[midX][midY] == target{
            return true
        }else if  matrix[midX][midY] >target{
            end = mid-1;
        }else{
            start = mid+1;
        }
    }

    return false

}