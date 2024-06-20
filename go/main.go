package main

import (
	"fmt"
	"time"
)

func main() {
	start := time.Now()
	for seed := uint64(1); seed <= 100_000_000; seed++ {
		res := collatz(seed)
		if seed%1_000_000 == 0 {
			fmt.Printf("Seed: %d Steps: %d\n", seed, res)
		}
	}

	fmt.Printf("Go Took %v\n", time.Since(start))
}

func collatz(seed uint64) uint64 {
	var cnt = uint64(0)

	for seed > 1 {
		cnt++
		if seed%2 == 0 {
			seed /= 2
		} else {
			seed = (seed * 3) + 1
		}
	}

	return cnt
}
