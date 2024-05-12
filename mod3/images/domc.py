import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FuncFormatter

# Define the functions
def f1(n): return 9*n**2 / (9*n**2 + 99*n + 999*np.log(n) + 9999)
def f2(n): return 99*n / (9*n**2 + 99*n + 999*np.log(n) + 9999)
def f3(n): return 999*np.log(n) / (9*n**2 + 99*n + 999*np.log(n) + 9999)
def f4(n): return 9999 / (9*n**2 + 99*n + 999*np.log(n) + 9999)

# Create a range of values for n
n_values = np.logspace(0, 6, 100)

# Calculate the results for each function over the range of n values
f1_values = f1(n_values)
f2_values = f2(n_values)
f3_values = f3(n_values)
f4_values = f4(n_values)

# Function to format the y-axis as percentages with three decimal places
def to_percent(y, position):
    return f'{100 * y:.3f}%'

# Create the plot
plt.figure(figsize=(8, 6))
plt.semilogx(n_values, f1_values, label=r'$c_1(n)=\frac{9n^2}{9n^2 + 99n + 999\log n + 9999}$')
plt.semilogx(n_values, f2_values, label=r'$c_2(n)=\frac{99n}{9n^2 + 99n + 999\log n + 9999}$')
plt.semilogx(n_values, f3_values, label=r'$c_3(n)=\frac{999\log n}{9n^2 + 99n + 999\log n + 9999}$')
plt.semilogx(n_values, f4_values, label=r'$c_4(n)=\frac{9999}{9n^2 + 99n + 999\log n + 9999}$')

# Set the formatter for the y-axis as percentages
formatter = FuncFormatter(to_percent)
plt.gca().yaxis.set_major_formatter(formatter)

# Add a legend to the plot
plt.legend()

# Set the title and axis labels
plt.title('Which term is dominant?')
plt.xlabel('n (Logarithmic Scale)')
plt.ylabel('Component ratio')

# Display the plot
plt.show()
