type Deque[T any] struct {
	data        []T
	head, tail  int
	size, count int
}

func NewDeque[T any](initialArray []T) *Deque[T] {
	var size int
	if len(initialArray) == 0 {
		size = 1
	} else {
		size = len(initialArray)
	}
	data := make([]T, size)
	copy(data, initialArray)
	return &Deque[T]{
		data: data,
		size: size,
	}
}

func (dq *Deque[T]) isEmpty() bool {
	return dq.count == 0
}

func (dq *Deque[T]) addRear(item T) {
	if dq.count == dq.size {
		dq.resize()
	}
	dq.data[dq.tail] = item
	dq.tail = (dq.tail + 1) % dq.size
	dq.count++
}

func (d *Deque[T]) addFront(value T) {
	if d.count == d.size {
		d.resize()
	}
	d.head = (d.head - 1 + d.size) % d.size
	d.data[d.head] = value
	d.count++
}

func (d *Deque[T]) removeFront() {
	if d.count == 0 {
		return 
	}
	
	d.head = (d.head + 1) % d.size
	d.count--
	return
}

func (d *Deque[T]) removeRear() {
	if d.count == 0 {
		return
	}
	d.tail = (d.tail - 1 + d.size) % d.size
	
	d.count--
	return
}

func (dq *Deque[T]) front() T {
	if dq.isEmpty() {
		var zero T
		return zero
	}
	return dq.data[dq.head]

}

func (dq *Deque[T]) rear() T {
	if dq.isEmpty() {
		var zero T
		return zero
	}
	return dq.data[(dq.tail-1+dq.size)%dq.size]
}

func (d *Deque[T]) resize() {
	newCapacity := d.size * 2
	newData := make([]T, newCapacity)
	if d.head < d.tail {
		copy(newData, d.data[d.head:d.tail])
	} else {
		copy(newData, d.data[d.head:])
		copy(newData[d.size-d.head:], d.data[:d.tail])
	}
	d.head = 0
	d.tail = d.count
	d.size = newCapacity
	d.data = newData
}

func longestOnes(nums []int, k int) int {
    l:=0
    r:=0
    maxLen := 0
    zeroCount:= 0
    dq := NewDeque[int]([]int{})

    for r<len(nums) {
        if nums[r] == 0 {
            dq.addFront(r);
            zeroCount++;
        }

        if(zeroCount >k){
            l = dq.rear() + 1
            dq.removeRear()
            zeroCount--
        }
        maxLen = max(r-l+1,maxLen)
        r++

    }
    return maxLen
    
}