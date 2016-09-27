import matplotlib.pyplot as plt
import numpy as np
import random

# Generate random data.
random_data = random.sample(range(10), 10)
# Add outliers.
random_data = [-15, -12, -10, -7, -5] + random_data + [15, 20, 23, 25, 30]
random_data = sorted(random_data)

# Plot random data
fig, ax = plt.subplots(figsize=(12,8))
ax.scatter(random_data, [0] * len(random_data), label='Dataset', color='Cyan')

# Plot mean
"""
MEAN:
- The mean is misleading when there are extreme outliers.
- When sampling a normal or bell-shaped population, the sample mean will tend
to be stable and quite representative of the sample.
"""
ax.scatter(np.mean(random_data), [0], label='Mean', color='Red')

# Plot median
"""
MEDIAN:
- It is the middle value once the data is sorted from min to max.
"""
ax.scatter(np.median(random_data), [0], label='Median', color='Black')

"""
QUARTILES:
- Roughly speaking, quartiles divide the data set into four equal parts, with
the observations above the third quartile constituting the upper quarter of
the data set, the second quartile being identical to the median, and the first
quartile separating the lower quarter from the upper three-quarters.
"""

# Plot 0%, 25%, 50% and 100% percentile.
"""
PERCENTILES:
- The 99th percentile separates the highest 1% from the bottom 99%.
- Unless the number of observations is a multiple of 100, care must be exercised
in obtaining percentiles.
"""
ax.plot([np.percentile(random_data, 0)]*3, range(-1,2, 1), label='0% Percentile', color='Orange')
ax.plot([np.percentile(random_data, 25)]*3, range(-1,2, 1), label='25% Percentile', color='Orange')
ax.plot([np.percentile(random_data, 50)]*3, range(-1,2, 1), label='50% Percentile', color='Orange')
ax.plot([np.percentile(random_data, 100)]*3, range(-1,2, 1), label='100% Percentile', color='Orange')

"""
TRIMMED MEAN:
- A trimmed mean is a compromise between x and |x . A 10% trimmed mean would be
computed by eliminating the smallest 10% and the largest 10% of the sample and
then averaging what remains.
"""

"""
SUMMARY:
- The mean is quite sensitive to a single outlier, whereas the median is
impervious to many outliers.
"""

# Plot settings.
ax.set_xlabel('Random data')
ax.set_title("Measures of location")

# Show plot
ax.legend()
plt.show()
