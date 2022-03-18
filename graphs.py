import matplotlib.pyplot as plt
import numpy as np

nums = np.transpose(np.loadtxt("cmake-build-debug/write.txt"))
x = np.arange(1, len(nums) + 1)

plt.plot(x, nums)
plt.grid()
plt.show()
