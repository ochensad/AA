package pipeline

import "time"

type PipeTask struct {
	// helpers
	num             int
	generated       bool
	skip_table_made bool
	pattern_mached  bool

	// time labels
	start_generating time.Time
	end_generatig    time.Time
	start_table      time.Time
	end_table        time.Time
	start_match      time.Time
	end_match        time.Time

	// data
	source []rune
	dst1   []rune
	dst2   []rune
	dst3   []rune
}

type Queue struct {
	queue [](*PipeTask)
	size  int
}
