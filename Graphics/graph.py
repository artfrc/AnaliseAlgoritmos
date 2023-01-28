import matplotlib.pyplot as plt

inputSizeRecDir = [40,80,160,280]
timeRecDir = []

inputSizeMemo = [40,80,160,280,1000,25000,80000]
timeMemo = []

inputSizePD = [40,80,160,280,1000,25000,80000,500000,1000000,2000000]
timePD = []

inputSizeAprox = [40,80,160,280,1000,25000,80000,500000,1000000,2000000]
timeAprox = []

plt.title("Comparison Algorithms")
plt.xlabel("Input Size")
plt.ylabel("Time")
plt.plot(inputSizeRecDir,timeRecDir,color = "blue",linewidth = 2,label = "Direct Recursive")
plt.plot(inputSizeMemo,timeMemo,color = "purple",linewidth = 2,label = "Memoization")
plt.plot(inputSizePD,timePD,color = "green",linewidth = 2,label = "Top Down")
plt.plot(inputSizeAprox,timeAprox,color = "red",linewidth = 2,label = "Approximation")
plt.legend()
plt.ylim(0,1.6)
#plt.xlim(0,100000)
plt.show()