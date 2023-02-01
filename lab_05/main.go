package main

import (
	"fmt"
	"main/pipeline"
	"runtime"
)

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())
	// count := 20
	var count int
	fmt.Print("Queue size: ")
	fmt.Scan(&count)

	ch := make(chan int)
	//ch - канал типа int
	//Pipeline - создает конвеер
	pipeline_qu := pipeline.Pipeline(count, ch)
	_ = pipeline_qu
	<-ch

	// Запускает конвеер
	pipeline_qu_sync := pipeline.Sync(count)
	_ = pipeline_qu_sync

	pipeline.PerfLog(pipeline_qu, pipeline_qu_sync)
}
