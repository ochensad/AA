package pipeline

import (
	"fmt"
	"time"
)

func PerfLog(qu_conc, qu_sync *Queue) {
	var (
		first_line_sleep_conc  time.Duration
		second_line_sleep_conc time.Duration
		third_line_sleep_conc  time.Duration

		first_line_sleep_sync  time.Duration
		second_line_sleep_sync time.Duration
		third_line_sleep_sync  time.Duration
	)

	line_conc := qu_conc.queue
	line_sync := qu_sync.queue
	start_conc := line_conc[0].start_generating
	start_sync := line_sync[0].start_generating
	fmt.Printf("%-37v│%-33v\n", "Параллельно, ns", "Синхронно, ns")
	for i := range line_conc {
		if line_conc[i] != nil {
			fmt.Printf("%-3v %-10v %-10v %-10v │ %-10v %-10v %-10v\n", i,
				line_conc[i].start_generating.Sub(start_conc).Nanoseconds(),
				line_conc[i].start_table.Sub(start_conc).Nanoseconds(),
				line_conc[i].start_match.Sub(start_conc).Nanoseconds(),
				line_sync[i].start_generating.Sub(start_sync).Nanoseconds(),
				line_sync[i].start_table.Sub(start_sync).Nanoseconds(),
				line_sync[i].start_match.Sub(start_sync).Nanoseconds())
		}
	}
	var (
		max_wait_first_sync  time.Duration
		max_wait_first_conc  time.Duration
		max_wait_second_sync time.Duration
		max_wait_second_conc time.Duration
		max_wait_third_sync  time.Duration
		max_wait_third_conc  time.Duration

		min_wait_first_sync  time.Duration
		min_wait_first_conc  time.Duration
		min_wait_second_sync time.Duration
		min_wait_second_conc time.Duration
		min_wait_third_sync  time.Duration
		min_wait_third_conc  time.Duration

		val time.Duration
	)
	for i := 0; i < len(line_conc)-1; i++ {
		if i == 0 {
			max_wait_first_conc = line_conc[i+1].start_generating.Sub(start_conc) - line_conc[i].end_generatig.Sub(start_conc)
			max_wait_second_conc = line_conc[i+1].start_table.Sub(start_conc) - line_conc[i].end_table.Sub(start_conc)
			max_wait_third_conc = line_conc[i+1].start_match.Sub(start_conc) - line_conc[i].end_match.Sub(start_conc)
		}
		val = line_conc[i+1].start_generating.Sub(start_conc) - line_conc[i].end_generatig.Sub(start_conc)
		if max_wait_first_conc < val {
			max_wait_first_conc = val
		}
		first_line_sleep_conc += val
		val = line_conc[i+1].start_table.Sub(start_conc) - line_conc[i].end_table.Sub(start_conc)
		if max_wait_second_conc < val {
			max_wait_second_conc = val
		}
		second_line_sleep_conc += val
		val = line_conc[i+1].start_match.Sub(start_conc) - line_conc[i].end_match.Sub(start_conc)
		if max_wait_third_conc < val {
			max_wait_third_conc = val
		}
		third_line_sleep_conc += val
	}
	for i := 0; i < len(line_sync)-1; i++ {
		if i == 0 {
			max_wait_first_sync = line_sync[i+1].start_generating.Sub(start_sync) - line_sync[i].end_generatig.Sub(start_sync)
			max_wait_second_sync = line_sync[i+1].start_table.Sub(start_sync) - line_sync[i].end_table.Sub(start_sync)
			max_wait_third_sync = line_sync[i+1].start_match.Sub(start_sync) - line_sync[i].end_match.Sub(start_sync)

			min_wait_first_sync = line_sync[i+1].start_generating.Sub(start_sync) - line_sync[i].end_generatig.Sub(start_sync)
			min_wait_second_sync = line_sync[i+1].start_table.Sub(start_sync) - line_sync[i].end_table.Sub(start_sync)
			min_wait_third_sync = line_sync[i+1].start_match.Sub(start_sync) - line_sync[i].end_match.Sub(start_sync)
		}
		val = line_sync[i+1].start_generating.Sub(start_sync) - line_sync[i].end_generatig.Sub(start_sync)
		if max_wait_first_sync < val {
			max_wait_first_sync = val
		}
		if min_wait_first_sync > val {
			min_wait_first_sync = val
		}

		first_line_sleep_sync += val
		val = line_sync[i+1].start_table.Sub(start_sync) - line_sync[i].end_table.Sub(start_sync)
		if max_wait_second_sync < val {
			max_wait_second_sync = val
		}
		if min_wait_second_sync > val {
			min_wait_second_sync = val
		}

		second_line_sleep_sync += val
		val = line_sync[i+1].start_match.Sub(start_sync) - line_sync[i].end_match.Sub(start_sync)
		if max_wait_third_sync < val {
			max_wait_third_sync = val
		}
		if min_wait_third_sync > val {
			min_wait_third_sync = val
		}
		third_line_sleep_sync += val
	}

	fmt.Printf("%-37v│%-33v\n", "Простой линий(П)", "Простой линий(С)")
	fmt.Printf("    %-10v %-10v %-10v │ %-10v %-10v %-10v\n", first_line_sleep_conc.Nanoseconds(),
		second_line_sleep_conc.Nanoseconds(),
		third_line_sleep_conc.Nanoseconds(),
		first_line_sleep_sync.Nanoseconds(),
		second_line_sleep_sync.Nanoseconds(),
		third_line_sleep_sync.Nanoseconds())
	fmt.Printf("%-37v│%-33v\n", "Макс. простой (П)", "Макс. простой (С)")
	fmt.Printf("    %-10v %-10v %-10v │ %-10v %-10v %-10v\n", max_wait_first_conc.Nanoseconds(),
		max_wait_second_conc.Nanoseconds(),
		max_wait_third_conc.Nanoseconds(),
		max_wait_first_sync.Nanoseconds(),
		max_wait_second_sync.Nanoseconds(),
		max_wait_third_sync.Nanoseconds())
	fmt.Printf("%-37v│%-33v\n", "Мин. простой (П)", "Мин. простой (С)")
	fmt.Printf("    %-10v %-10v %-10v │ %-10v %-10v %-10v\n", min_wait_first_conc.Nanoseconds(),
		min_wait_second_conc.Nanoseconds(),
		min_wait_third_conc.Nanoseconds(),
		min_wait_first_sync.Nanoseconds(),
		min_wait_second_sync.Nanoseconds(),
		min_wait_third_sync.Nanoseconds())
	fmt.Printf("%-37v│%-33v\n", "Ср. простой(П)", "Ср. простой(С)")
	fmt.Printf("    %-10v %-10v %-10v │ %-10v %-10v %-10v\n", (first_line_sleep_conc / time.Duration(len(qu_conc.queue))).Nanoseconds(),
		(second_line_sleep_conc / time.Duration(len(qu_conc.queue))).Nanoseconds(),
		(third_line_sleep_conc / time.Duration(len(qu_conc.queue))).Nanoseconds(),
		(first_line_sleep_sync / time.Duration(len(qu_conc.queue))).Nanoseconds(),
		(second_line_sleep_sync / time.Duration(len(qu_conc.queue))).Nanoseconds(),
		(third_line_sleep_sync / time.Duration(len(qu_conc.queue))).Nanoseconds())

	var (
		max_task_time_conc time.Duration
		min_task_time_conc time.Duration
		sum_task_time_conc time.Duration
		avg_task_time_conc time.Duration
		task_time_conc     time.Duration

		max_task_time_sync time.Duration
		min_task_time_sync time.Duration
		sum_task_time_sync time.Duration
		avg_task_time_sync time.Duration
		task_time_sync     time.Duration
	)

	for i := 0; i < len(line_conc)-1; i++ {
		if i == 0 {
			max_task_time_conc = line_conc[i].end_match.Sub(line_conc[i].start_generating)
			min_task_time_conc = line_conc[i].end_match.Sub(line_conc[i].start_generating)
			sum_task_time_conc = 0
		}
		task_time_conc = line_conc[i].end_match.Sub(line_conc[i].start_generating)
		if max_task_time_conc < task_time_conc {
			max_task_time_conc = task_time_conc
		}
		if min_task_time_conc > task_time_conc {
			min_task_time_conc = task_time_conc
		}
		sum_task_time_conc += task_time_conc
	}
	avg_task_time_conc = sum_task_time_conc / time.Duration(len(qu_conc.queue))

	for i := 0; i < len(line_sync)-1; i++ {
		if i == 0 {
			max_task_time_sync = line_sync[i].end_match.Sub(line_sync[i].start_generating)
			min_task_time_sync = line_sync[i].end_match.Sub(line_sync[i].start_generating)
			sum_task_time_sync = 0
		}
		task_time_sync = line_sync[i].end_match.Sub(line_sync[i].start_generating)
		if max_task_time_sync < task_time_sync {
			max_task_time_sync = task_time_sync
		}
		if min_task_time_sync < task_time_sync {
			min_task_time_sync = task_time_sync
		}
		sum_task_time_sync += task_time_sync
	}
	avg_task_time_sync = sum_task_time_sync / time.Duration(len(qu_conc.queue))

	fmt.Printf("%-37v│%-37v\n", "Макс. время заявки в системе(П)", "Макс. время заявки в системе(C)")
	fmt.Printf("%-37v│%-37v\n", max_task_time_conc.Nanoseconds(), max_task_time_sync.Nanoseconds())

	fmt.Printf("%-37v│%-37v\n", "Мин. время заявки в системе(П)", "Мин. время заявки в системе(C)")
	fmt.Printf("%-37v│%-37v\n", min_task_time_conc.Nanoseconds(), min_task_time_sync.Nanoseconds())

	fmt.Printf("%-37v│%-37v\n", "Сред. время заявки в системе(П)", "Сред. время заявки в системе(C)")
	fmt.Printf("%-37v│%-37v\n", avg_task_time_conc.Nanoseconds(), avg_task_time_sync.Nanoseconds())
}
