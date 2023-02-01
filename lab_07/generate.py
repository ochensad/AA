import csv
import random

with open('data.csv', 'w', newline='') as file:
	writer = csv.writer(file, delimiter=';')
	i = 0
	for j in range(0, 800):
		print(j)
		writer.writerow(["Отчет №" + str(i), random.randint(0, 50)])
		i+=1