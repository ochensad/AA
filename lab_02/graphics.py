import matplotlib.pyplot as plt
import numpy as np

f = open('Odd.txt', 'r')
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
x1= [0, 100, 300, 500]
plt.plot(x1, A, label = "Классический алгоритм")
plt.plot(x1, C, label = "Алгоритм Винограда с оптимизацией")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Алгоритм Винограда")
plt.legend()
plt.scatter(x1, A, color='blue', s=20)
plt.scatter(x1, B, color='green', s=20)
plt.scatter(x1, C, color='orange', s=20)
plt.ylabel('Время (мс)')
plt.xlabel('Размер массива')
plt.savefig('graph_1.png')
plt.show()

f.close()

f = open('Even.txt', 'r')
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
x1= [0,200, 400, 600]
plt.plot(x1, A, label = "Классический алгоритм")
plt.plot(x1, C, label = "Алгоритм Винограда с оптимизацией")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Алгоритм Винограда")
plt.legend()
plt.scatter(x1, A, color='blue', s=20)
plt.scatter(x1, B, color='green', s=20)
plt.scatter(x1, C, color='orange', s=20)
plt.ylabel('Время (мс)')
plt.xlabel('Размер массива')
plt.savefig('graph_2.png')
plt.show()

f.close()
