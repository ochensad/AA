import matplotlib.pyplot as plt
import numpy as np

f = open('Luch.txt', 'r')
A = []
B = []
C = []

for line in f:
	k = line.find(" ")
	m = line.rfind(" ")
	A.append(float(line[0: k]))
	B.append(float(line[k:m]))
	C.append(float(line[m:]))

print(A)
x1= [1, 10, 50, 100, 250, 500, 1000]
plt.plot(x1, A, label = "Плавная сортировка")
plt.plot(x1, C, label = "Сортировка слияением")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Сортировка расчёской")
plt.legend()
plt.scatter(x1, A, color='blue', s=20)
plt.scatter(x1, B, color='green', s=20)
plt.scatter(x1, C, color='orange', s=20)
plt.ylabel('Время (мс)')
plt.xlabel('Размер массива')
plt.savefig('graph_1.png')
plt.show()

f.close()

f = open('Hud.txt', 'r')
A = []
B = []
C = []

for line in f:
	k = line.find(" ")
	m = line.rfind(" ")
	A.append(float(line[0: k]))
	B.append(float(line[k:m]))
	C.append(float(line[m:]))

print(A)
x1= [1, 10, 50, 100, 250, 500, 1000]
plt.plot(x1, A, label = "Плавная сортировка")
plt.plot(x1, C, label = "Сортировка слияением")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Сортировка расчёской")
plt.legend()
plt.scatter(x1, A, color='blue', s=20)
plt.scatter(x1, B, color='green', s=20)
plt.scatter(x1, C, color='orange', s=20)
plt.ylabel('Время (мс)')
plt.xlabel('Размер массива')
plt.savefig('graph_2.png')
plt.show()

f.close()

f = open('Proizv.txt', 'r')
A = []
B = []
C = []

for line in f:
	k = line.find(" ")
	m = line.rfind(" ")
	A.append(float(line[0: k]))
	B.append(float(line[k:m]))
	C.append(float(line[m:]))

print(A)
x1= [1, 10, 50, 100, 250, 500, 1000]
plt.plot(x1, A, label = "Плавная сортировка")
plt.plot(x1, C, label = "Сортировка слияением")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Сортировка расчёской")
plt.legend()
plt.scatter(x1, A, color='blue', s=20)
plt.scatter(x1, B, color='green', s=20)
plt.scatter(x1, C, color='orange', s=20)
plt.ylabel('Время (мс)')
plt.xlabel('Размер массива')
plt.savefig('graph_3.png')
plt.show()

f.close()