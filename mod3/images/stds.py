import matplotlib.pyplot as plt
import numpy as np
from scipy.special import factorial
from matplotlib.ticker import FuncFormatter

# Define the functions
def f1(n): return np.ones_like(n)
def f2(n): return np.log(n)
def f3(n): return np.sqrt(n)
def f4(n): return n
def f5(n): return n * np.log(n)
def f6(n): return n**2
def f7(n): return n**3
def f8(n): return 2**n
def f9(n): return 3**n
def f10(n): return factorial(n)

# Create a range of values for n
n_values = np.logspace(0, 2, base=10, num=100)

# Calculate the results for each function over the range of n values
f1_values = f1(n_values)
f2_values = f2(n_values)
f3_values = f3(n_values)
f4_values = f4(n_values)
f5_values = f5(n_values)
f6_values = f6(n_values)
f7_values = f7(n_values)
f8_values = f8(n_values)
f9_values = f9(n_values)
f10_values = f10(n_values)

# Create the plot with logarithmic axes
plt.figure(figsize=(8, 6))
plt.loglog(n_values, f1_values, label=r'$f_1(n)=1$')
plt.loglog(n_values, f2_values, label=r'$f_2(n)=\log(n)$')
plt.loglog(n_values, f3_values, label=r'$f_3(n)=\sqrt{n}$')
plt.loglog(n_values, f4_values, label=r'$f_4(n)=n$')
plt.loglog(n_values, f5_values, label=r'$f_5(n)=n\log(n)$')
plt.loglog(n_values, f6_values, label=r'$f_6(n)=n^2$')
plt.loglog(n_values, f7_values, label=r'$f_7(n)=n^3$')
plt.loglog(n_values, f8_values, label=r'$f_8(n)=2^n$')
plt.loglog(n_values, f9_values, label=r'$f_9(n)=3^n$')
# plt.loglog(n_values, f10_values, label=r'$f_{10}(n)=n!$')

# Add a legend to the plot
plt.legend()

# Set the title and axis labels
plt.title('Comparison of Functions on Logarithmic Scale')
plt.xlabel('n (Logarithmic Scale)')
plt.ylabel('Function Value (Logarithmic Scale)')

# Display the plot
plt.show()
