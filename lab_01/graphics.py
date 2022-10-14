import matplotlib.pyplot as plt
import numpy as np

f = open('smallGraphic.txt', 'r')
A = []
B = []

for line in f:
	k = line.find(" ")
	A.append(float(line[0: k]))
	B.append(float(line[k:]))

x1=np.linspace(5,len(A)+5,len(A))
plt.plot(x1, A, label = "Левенштейн нерекурсивный")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Дамерау-Левенштейн нерекурсивный")
plt.legend()
plt.savefig('graph.png')
plt.show()

f.close()

f = open('largeGraphic.txt', 'r')
A = []
B = []

for line in f:
	k = line.find(" ")
	A.append(float(line[0: k]))
	B.append(float(line[k:]))

x1=np.linspace(0,len(A),len(A))
plt.plot(x1, A, label = "Дамерау-Левенштейн рекурсивный")
plt.grid(True)
plt.title('')

plt.plot(x1, B, label = "Дамерау-Левенштейн рекурсивный с кэшем")
plt.legend()
plt.savefig('graph1.png')
plt.show()

f.close()