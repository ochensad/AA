package aco

import "fmt"

func makeColony(gr_matrix [][]int, iters int, conf_filename string) *Colony {

	// Создаем колонию
	colony := new(Colony)

	// Парсим конфиг файл получаем коэф для рассчетов
	conf := ParceConfigFile(conf_filename)

	if (conf == nil) {
		return nil
	}

	// Записываем в колонию данные
	colony.conf = *conf

	colony.gr_matrix = gr_matrix
	colony.iters = iters
	colony.phero_matrix = make([][]float64, len(colony.gr_matrix))

	for i := 0; i < len(colony.gr_matrix); i++ {
		colony.phero_matrix[i] = make([]float64, len(colony.gr_matrix[i]))

		for j := range colony.phero_matrix[i] {
			colony.phero_matrix[i][j] = colony.conf.PHERO_INIT
		}
	}
	return colony
}

func (col *Colony) placeAnt(start int) *Ant {
	ant := new(Ant)
	ant.colony   = col
	ant.tour     = make([][]int, len(col.gr_matrix))
	ant.memory   = make([][]bool, len(col.gr_matrix))
	ant.position = start
	ant.start    = start

	for i := range col.gr_matrix {
		ant.tour[i] = make([]int, len(col.gr_matrix[i]))
		copy(ant.tour[i], col.gr_matrix[i])
	}

	for i := range ant.memory {
		ant.memory[i] = make([]bool, len(col.gr_matrix))
	}

	return ant
}

func ACOWrapper(gr_matrix [][]int, iters int, conf_filename string) *[]int {
	shortest := make([]int, len(gr_matrix))

	colony := makeColony(gr_matrix, iters, conf_filename)
	if (colony == nil) {
		return nil
	}
	fmt.Println(colony.conf.TRACE_WEIGHT)
	fmt.Println(colony.conf.TOUR_VISIB)
	fmt.Println(colony.conf.EVAP_RATE)
	fmt.Println(colony.conf.Q)
	shortest_tours := make([][]int, len(gr_matrix))
	for i := range gr_matrix {
		shortest_tours[i] = make([]int, len(gr_matrix[i]))
	}

	for i := 0; i < colony.iters; i++ {
		for j := 0; j < len(colony.gr_matrix) - 7; j++ {
			ant := colony.placeAnt(j)
			ant.elit_ant = true;
			ant.startTour()
			current := ant.tourLength()
			if (current < shortest[j] || shortest[j] == 0) && len(ant.memory_tour) ==  len(colony.gr_matrix){
				shortest[j] = current
				colony.shortest_tour = ant.memory_tour
				copy(shortest_tours[j], ant.memory_tour)
			}
		}
		for j := len(colony.gr_matrix) - 7; j < len(colony.gr_matrix); j++ {
			ant := colony.placeAnt(j)
			ant.elit_ant = false
			ant.startTour()
			current := ant.tourLength()
			if (current < shortest[j] || shortest[j] == 0) && len(ant.memory_tour) ==  len(colony.gr_matrix){
				shortest[j] = current
				colony.shortest_tour = ant.memory_tour
				copy(shortest_tours[j], ant.memory_tour)
			}
		}
	}
	fmt.Println("------")
	fmt.Println(shortest_tours)
	return &shortest
}

