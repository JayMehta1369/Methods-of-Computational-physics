# -*- coding: utf-8 -*-
"""4G03-HW3.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1s12Gc2zF5e7ohBhyiaZxTdKzh2zfqXqe
"""

from matplotlib import pyplot as plt
import numpy as np

x, y = np.loadtxt("./drive/MyDrive/Data/E_0.txt", delimiter="\t", usecols=(0,1), unpack=True)
x0_14, y0_14 = np.loadtxt("./drive/MyDrive/Data/E_0_14.txt", delimiter="\t", usecols=(0,1), unpack=True)
x1, y1 = np.loadtxt("./drive/MyDrive/Data/E_1.txt", delimiter="\t", usecols=(0,1), unpack=True) 
x1_14, y1_14 = np.loadtxt("./drive/MyDrive/Data/E_1_14.txt", delimiter="\t", usecols=(0,1), unpack=True)
xd, yd = np.loadtxt("./drive/MyDrive/Data/diff.txt", delimiter="\t", usecols=(0,1), unpack=True) 

l, limit = np.loadtxt("./drive/MyDrive/Data/limit.txt", delimiter="\t", usecols=(0,1), unpack=True)

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(x, y)
ax.set_xlabel("Matrix size (M)", fontsize = '14')
ax.set_ylabel(r'$E_0$', fontsize = '14')
ax.set_title(r'$E_0$ vs $M$', fontsize = '16')
 
# Show plot

plt.savefig("E_0_10.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(x1, y1)
ax.set_xlabel("Matrix size (M)", fontsize = '14')
ax.set_ylabel(r'$E_{excited}$', fontsize = '14')
ax.set_title(r'$E_1$ vs $M$', fontsize = '16')
 
# Show plot

plt.savefig("E_1_10.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(xd, yd, label=r'$E_{L=10}^0 = −4.5154463544$')
ax.set_xlabel("Matrix size (M)", fontsize = '14')
ax.set_ylabel(r'$|E_0 - E_{L=10}^0|$', fontsize = '14')
ax.set_title(r'$|E_0 - E_{L=10}^0|$ vs $M$', fontsize = '16')

# Show plot
plt.legend()
plt.savefig("diff_10.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(x0_14, y0_14, label="L = 14")
ax.set_xlabel("Matrix size (M)", fontsize = '14')
ax.set_ylabel(r'$E_0$', fontsize = '14')
ax.set_title(r'$E_0$ vs $M$', fontsize = '16')
 
# Show plot
plt.legend()
plt.savefig("E_0_14.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(x1_14, y1_14, label="L = 14")
ax.set_xlabel("Matrix size (M)", fontsize = '14')
ax.set_ylabel(r'$E_{excited}$', fontsize = '14')
ax.set_title(r'$E_1$ vs $M$', fontsize = '16')
 
# Show plot
plt.legend()
plt.savefig("E_1_14.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(l, limit, label="M = 50")
ax.set_xlabel("Number of spins (L))", fontsize = '14')
ax.set_ylabel(r'$|E_1 - E_0|$', fontsize = '14')
ax.set_title(r'$|E_1 - E_0|$ vs $L$ as limit $L \longrightarrow \infty$', fontsize = '16')
 
# Show plot
plt.legend()
plt.savefig("limit.png",dpi=600)
plt.show()

fig, ax = plt.subplots(figsize =(8, 6))

ax.plot(l, limit, label="M = 50")
ax.set_xlabel("Number of spins (L))", fontsize = '14')
ax.set_ylabel(r'$|E_1 - E_0|$', fontsize = '14')
plt.yscale("log")
ax.set_title(r'$|E_1 - E_0|$ vs $L$ as limit $L \longrightarrow \infty$', fontsize = '16')
 
# Show plot
plt.legend()
plt.savefig("limit_log.png",dpi=600)
plt.show()

