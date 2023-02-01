import matplotlib.pyplot as plt
import numpy as np

y1 = [1, 1, 0.2, 0,0,0,0,0,0,0,0]
y2 = [0, 0.2, 0.8, 0.6,0,0,0,0,0,0,0]
y3 = [0, 0, 0.2, 0.4,0.6,0.2,0,0,0,0,0]
y4 = [0, 0, 0, 0.2,0.4,0.8,0.8,0.2,0,0,0]
y5 = [0, 0, 0, 0,0,0,0.4,0.8,0.6,0.6,0]
y6 = [0, 0, 0, 0,0,0,0,0,0.4,0.4,1]

x1= [0,5,10,15,20,25,30,35,40,45,50]
plt.grid(True)
plt.title('')

plt.plot(x1, y1, label = "очень маленький")
plt.plot(x1, y2, label = "маленький")
plt.plot(x1, y3, label = "небольшой")
plt.plot(x1, y4, label = "средний")
plt.plot(x1, y5, label = "большой")
plt.plot(x1, y6, label = "очень большой")
plt.legend()
plt.scatter(x1, y1, color='orange', s=20)
plt.scatter(x1, y2, color='green', s=20)
plt.scatter(x1, y3, color='blue', s=20)
plt.scatter(x1, y4, color='red', s=20)
plt.scatter(x1, y5, color='yellow', s=20)
plt.scatter(x1, y6, color='purple', s=20)
plt.ylabel('Принадлежность')
plt.xlabel('Размер отчета')
plt.savefig('graph_1.png')
plt.show()
