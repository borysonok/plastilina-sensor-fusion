import pandas as pd
import matplotlib.pyplot as plt

# Load true data
line = pd.read_csv("../true_line_path.csv")
circle = pd.read_csv("../true_circle_path.csv")

# Load GPS data
gpsLine = pd.read_csv("../gps_line_path.csv")
gpsCircle = pd.read_csv("../gps_circle_path.csv")

# Plot true paths
plt.plot(line["x"], line["y"], label="Line")
plt.plot(circle["x"], circle["y"], label="Circle")

# Plot data from GPS sensors
plt.plot(gpsLine["x"], gpsLine["y"], label="gpsLine")
plt.plot(gpsCircle["x"], gpsCircle["y"], label="gpsCircle")

# Format
plt.axis("equal")
plt.grid()
plt.legend()

# Show
plt.show()