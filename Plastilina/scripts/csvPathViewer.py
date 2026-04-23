import pandas as pd
import matplotlib.pyplot as plt

# //////////////////////// LOAD DATA //////////////////////////////////////////

# Load true data
line = pd.read_csv("../true_line_path.csv")
circle = pd.read_csv("../true_circle_path.csv")

# Load GPS data
gpsLine = pd.read_csv("../gps_line_path.csv")
gpsCircle = pd.read_csv("../gps_circle_path.csv")

# Load KF data
gpsLineKF = pd.read_csv("../gps_line_KF_path.csv")
gpsCircleKF = pd.read_csv("../gps_circle_KF_path.csv")

# /////////////////////////// PLOT ////////////////////////////////////////////

# Plot true paths
plt.plot(line["x"], line["y"], label="Line")
plt.plot(circle["x"], circle["y"], label="Circle")

# Plot data from GPS sensors
plt.scatter(gpsLine["x"], gpsLine["y"], label="gpsLine", s=5)
plt.scatter(gpsCircle["x"], gpsCircle["y"], label="gpsCircle", s=5)

# Plot data from KF
plt.plot(gpsLineKF["x"], gpsLineKF["y"], label="KF_gpsLine_Estimates")
plt.plot(gpsCircleKF["x"], gpsCircleKF["y"], label="KF_gpsCircle_Estimates")

# /////////////////////////////////////////////////////////////////////////////

# Format
plt.axis("equal")
plt.grid()
plt.legend()

# Show
plt.show()