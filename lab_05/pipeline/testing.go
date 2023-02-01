package pipeline

import "fmt"

func Log(qu *Queue) {
	fmt.Println("")
	line := qu.queue
	for i := range line {
		if line[i] != nil {
			fmt.Printf("%3v & %10v & %10v & %10v & %10v &  \n", i, string(line[i].source), string(line[i].dst1), string(line[i].dst2), string(line[i].dst3))
		}
	}
}
