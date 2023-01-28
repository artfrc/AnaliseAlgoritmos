import matplotlib.pyplot as plt

inputSizeRecDir = [40,80,160,280]
timeRecDir = [0,0.0047,2.9313,106.0977]

inputSizeMemo = [40,80,160,280,1000,25000,80000]
timeMemo = [0,0,0,0,0.0003,0.0133,0.0390]

inputSizePD = [40,80,160,280,1000,25000,80000,500000,1000000,2000000]
timePD = [0,0,0,0.0003,0.0010,0.0250,0.0873,0.4920,0.9973,2.0330]

inputSizeAprox = [40,80,160,280,1000,25000,80000,500000,1000000,2000000]
timeAprox = [0,0,0,0,0,0,0,0,0,0]

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