package chiperalg

import (
	"math/rand"
	"time"
)

func GenerateRune(size int) []rune {
	var letters = []rune("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
	rand.Seed(time.Now().UnixNano())
	b := make([]rune, size)
	for i := range b {
		b[i] = letters[rand.Intn(len(letters))]
	}
	return b
}
