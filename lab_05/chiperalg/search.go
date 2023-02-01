package chiperalg

func search(text []rune, what rune) int {

	for i := range text {
		if text[i] == what {
			return i
		}
	}
	return -1
}

func CaesarChiper(src []rune, size int) []rune {
	var letters = []rune("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
	var smeshenie = 6
	var itog = make([]rune, size)
	for i := range src {
		var mesto = search(letters, src[i])
		var newmesto = (mesto + smeshenie) % len(letters)
		if search(letters, src[i]) > -1 {
			itog[i] = letters[newmesto]
		} else {
			itog[i] = src[i]
		}
	}
	return itog
}

func XorChiperFirst(src []rune, size int) []rune {

	var smeshenie = 8
	var itog = make([]rune, size)
	for i := range src {
		itog[i] = rune(int(src[i]) ^ smeshenie)
	}
	return itog
}

func XorChiperSecond(src []rune, size int) []rune {

	var smeshenie = 3
	var itog = make([]rune, size)
	for i := range src {
		itog[i] = rune(int(src[i]) ^ smeshenie)
	}
	return itog
}
