from random import randrange, seed
import matplotlib.pyplot as plt

times = [0,0.0453,3.63,13.4520,15.3863,132.1573]

x = list(range(1,len(times)+1))
y = times
plt.plot(x, y, marker='o')
plt.title('Comparison algorithms')
plt.xlabel('Input size')
plt.ylabel('Seconds')
plt.ylim(0, 60) # definir limite do eixo
plt.yticks(range(0, 61, 2)) # alterar escala do eixo
plt.xticks(range(40,200,40))
plt.show()