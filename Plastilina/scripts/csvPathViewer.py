import pandas as pd
import matplotlib.pyplot as plt

# Load files
line = pd.read_csv("../true_line_path.csv")
circle = pd.read_csv("../true_circle_path.csv")

# Plot
plt.plot(line["x"], line["y"], label="Line")
plt.plot(circle["x"], circle["y"], label="Circle")

# Format
plt.axis("equal")
plt.grid()
plt.legend()

# Show
plt.show()