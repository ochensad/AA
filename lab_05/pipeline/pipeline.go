package pipeline

import (
	"main/chiperalg"
	"math/rand"
	"time"
)

// Принимает размер очереди, возвращает пулл обработанных заявок
func Pipeline(count int, ch chan int) *Queue {

	//Создаем ОУ
	first := make(chan *PipeTask, count)
	second := make(chan *PipeTask, count)
	third := make(chan *PipeTask, count)

	//Создаем очередь
	line := initQueue(count)

	//Первый ОУ
	gen_string := func() {
		for {
			select {
			case pipe_task := <-first:
				pipe_task.generated = true

				len_s := rand.Intn(10)
				pipe_task.source = chiperalg.GenerateRune(len_s)
				pipe_task.start_generating = time.Now()
				pipe_task.dst1 = chiperalg.XorChiperFirst(pipe_task.source, len_s)

				pipe_task.end_generatig = time.Now()
				Log(line)
				second <- pipe_task
			}
		}
	}

	//Второй ОУ
	get_table := func() {
		for {
			select {
			case pipe_task := <-second:
				pipe_task.skip_table_made = true

				pipe_task.start_table = time.Now()

				pipe_task.dst2 = chiperalg.CaesarChiper(pipe_task.dst1, len(pipe_task.dst1))
				pipe_task.end_table = time.Now()
				Log(line)
				third <- pipe_task
			}
		}
	}
	//Третий ОУ
	match := func() {
		for {
			select {
			case pipe_task := <-third:
				pipe_task.pattern_mached = true

				pipe_task.start_match = time.Now()
				pipe_task.dst3 = chiperalg.XorChiperSecond(pipe_task.dst2, len(pipe_task.dst2))
				pipe_task.end_match = time.Now()
				Log(line)
				line.enqueue(pipe_task)
				if pipe_task.num == count-1 {
					ch <- 0
				}
			}
		}
	}

	//Запуск ОУ
	go gen_string()
	go get_table()
	go match()

	// Создаем таски
	for i := 0; i < count; i++ {
		pipe_task := new(PipeTask)
		pipe_task.num = i + 1
		first <- pipe_task
	}
	return line
}
