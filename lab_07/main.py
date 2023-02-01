import csv

data = {}

def read_data():
	with open('data.csv', newline='') as File:
		reader = csv.reader(File)
		for row in reader:
			i = row[0].find(';')
			data[row[0][:i]] = int(row[0][i+1:])

def read_request():
	s = input("Введите запрос: ")
	s = s.lower()
	flags_term = []
	flags_alg = []

	razdel_i = 0
	tmp = s
	while tmp.find(" и ") != -1:
		tmp = tmp[tmp.find(" и ") + 1:]
		razdel_i += 1
	razdel_ili = 0
	tmp2 = s
	while tmp2.find(" или ") != -1:
		tmp2 = tmp2[tmp2.find(" или ") + 1:]
		razdel_ili += 1

	podstroki = []
	k_i = s.find(" и ")
	k_ili = s.find(" или ")

	for i in range(razdel_i + razdel_ili):
		buf = ''
		k_i = s.find(" и ")
		k_ili = s.find(" или ")
		if k_ili != -1 and k_i != -1:
			if s.find(" и ") < s.find(" или "):
				buf = s[:s.find(" и ")]
				s = s[k_i + 2:]
				podstroki.append(buf)
				flags_alg.append("и")
			else:
				buf = s[:s.find(" или ")]
				s = s[k_ili + 4:]
				podstroki.append(buf)
				flags_alg.append("или")
		elif k_i != -1:
			buf = s[:s.find(" и ")]
			s = s[k_i + 2:]
			podstroki.append(buf)
			flags_alg.append("и")
		elif k_ili != -1:
			buf = s[:s.find(" или ")]
			s = s[k_ili + 4:]
			podstroki.append(buf)
			flags_alg.append("или")
	if k_i < k_ili:
		buf = s[:s.find(" и ")]
		s = s[k_i + 1:]
		podstroki.append(buf)
	else:
		buf = s[:s.find(" или ")]
		s = s[k_ili + 1:]
		podstroki.append(buf)
	
	for c in podstroki:
		tmp = []
		if "небольш" in c:
			tmp.append("небольшой")
		if "не " in c:
			tmp.append("не")
		if "очень малень" in c:
			tmp.append("очень маленький")
		if "малень" in c and "очень " not in c:
			tmp.append("маленький")
		if "средн" in c:
			tmp.append("средний")
		if "очень больш" in c:
			tmp.append("очень большой")
		if "больш" in c and "очень " not in c and "неб" not in c:
			tmp.append("большой")
		flags_term.append(tmp)
	return flags_term, flags_alg

def find_all(begin, end, not_s = -1, not_e = -1):
	res = []
	for l in data.keys():
		if not_s == -1 and not_e == -1:
			if data.get(l) >= begin and data.get(l) <= end:
				res.append([l,data.get(l)])
		else:
			if data.get(l) >= begin and data.get(l) <= not_s:
				res.append([l,data.get(l)])
			elif data.get(l) >= not_e and data.get(l) <= end:
				res.append([l,data.get(l)])
	return res


def find_data(request_raz, request_term):

	answer_arrays = []
	for c in request_term:
		if 'не' in c:
			if 'большой' in c:
				answer_arrays.append(find_all(0,50, 35, 45))
			if 'очень большой' in c:
				answer_arrays.append(find_all(0,45))
			if 'средний' in c:
				answer_arrays.append(find_all(0,50,25,35))
			if 'небольшой' in c:
				answer_arrays.append(find_all(0,50, 15,20))
			if 'маленький' in c:
				answer_arrays.append(find_all(0,50, 10,15))
			if 'очень маленький' in c:
				answer_arrays.append(find_all(0,50, 0,10))
		else:
			if 'большой' in c:
				answer_arrays.append(find_all(35, 45))
			if 'очень большой' in c:
				answer_arrays.append(find_all(45,50))
			if 'средний' in c:
				answer_arrays.append(find_all(25,35))
			if 'небольшой' in c:
				answer_arrays.append(find_all(15,20))
			if 'маленький' in c:
				answer_arrays.append(find_all(10,15))
			if 'очень маленький' in c:
				answer_arrays.append(find_all(0,10))
	answer = []
	i = 0
	for raz in request_raz:
		if 'и' in raz and 'или' not in raz:
			if i == 0:
				for a in answer_arrays[i]:
					if a in answer_arrays[i+1]:
						answer.append(a)
				i += 2
			else:
				for a in answer:
					if a not in answer_arrays[i]:
						answer.remove(a)
				i+=1
		if 'или' in raz:
			if i == 0:
				for a in answer_arrays[i]:
					answer.append(a)
				for a in answer_arrays[i+1]:
					if a not in answer:
						answer.append(a)
				i += 2
			else:
				for a in answer_arrays[i]:
					if a not in answer:
						answer.append(a)
				i+=1
	if len(request_raz) == 0:
		for a in answer_arrays[0]:
			answer.append(a)
	return answer

def print_data(answer):
	print("Результаты поиска:")
	for c in answer:
		print(c[0], " с размером ", c[1])

def main():
	read_data()
	request_term, request_raz = read_request()
	answer = find_data(request_raz, request_term)
	print_data(answer)

if __name__ == "__main__":
	main()