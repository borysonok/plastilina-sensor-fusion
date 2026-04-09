import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("../true_line_path.csv")

plt.plot(df["x"], df["y"])
plt.axis("equal")
plt.show()