package pipeline

import (
	"main/chiperalg"
	"math/rand"
	"time"
)

func XorFirst(task *PipeTask) *PipeTask {
	task.generated = true

	task.start_generating = time.Now()
	len_s := rand.Intn(100)
	task.source = chiperalg.GenerateRune(len_s)
	task.dst1 = chiperalg.XorChiperFirst(task.source, len_s)

	task.end_generatig = time.Now()

	return task
}

func Caesar(task *PipeTask) *PipeTask {
	task.skip_table_made = true

	task.start_table = time.Now()

	task.dst2 = chiperalg.CaesarChiper(task.dst1, len(task.dst1))
	task.end_table = time.Now()

	return task
}

func XorSecond(task *PipeTask) *PipeTask {
	task.pattern_mached = true

	task.start_match = time.Now()
	task.dst3 = chiperalg.XorChiperSecond(task.dst2, len(task.dst2))
	task.end_match = time.Now()

	return task
}

func Sync(count int) *Queue {

	//Создаем 3 очереди
	line_first := initQueue(count)
	line_second := initQueue(count)
	line_third := initQueue(count)

	for i := 0; i < count; i++ {
		pipe_task := new(PipeTask)
		pipe_task = XorFirst(pipe_task)
		line_first.enqueue(pipe_task)
		if len(line_first.queue) != 0 {
			pipe_task = Caesar(line_first.dequeue())
			line_second.enqueue(pipe_task)
			if len(line_second.queue) != 0 {
				pipe_task = XorSecond(line_second.dequeue())
				line_third.enqueue(pipe_task)
			}
		}
	}
	return line_third
}
