#!usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

avgs1  = []
bests1 = []
with open("report_0_0.txt") as fd:
    lines = fd.read().strip().split("\n")
    for line in lines:
        start = line.index("Average") + 16
        end = line.index(" ", start)
        avgs1.append(float(line[start: end]))
        start = end + 14
        bests1.append(float(line[start:]))

avgs2  = []
bests2 = []
with open("report_1_0.txt") as fd:
    lines = fd.read().strip().split("\n")
    for line in lines:
        start = line.index("Average") + 16
        end = line.index(" ", start)
        avgs2.append(float(line[start: end]))
        start = end + 14
        bests2.append(float(line[start:]))

avgs3  = []
bests3 = []
with open("report_2_0.txt") as fd:
    lines = fd.read().strip().split("\n")
    for line in lines:
        start = line.index("Average") + 16
        end = line.index(" ", start)
        avgs3.append(float(line[start: end]))
        start = end + 14
        bests3.append(float(line[start:]))

# Data
df=pd.DataFrame({'Generation': range(0, 251), 'K_POINT': bests1, 'UNIFORM': bests2, 'SINGLE_POINT': bests3 })

# multiple line plot
plt.title("Generation vs Best Fitness")
plt.plot( 'Generation', 'K_POINT', data=df, color='red')
plt.plot( 'Generation', 'UNIFORM', data=df, color='green')
plt.plot( 'Generation', 'SINGLE_POINT', data=df, color='blue')
plt.legend()
plt.savefig("plot1.png")

# Data
df=pd.DataFrame({'Generation': range(0, 251), 'K_POINT': avgs1, 'UNIFORM': avgs2, 'SINGLE_POINT': avgs3 })

# multiple line plot
plt.title("Generation vs Average Fitness")
plt.plot( 'Generation', 'K_POINT', data=df, color='red')
plt.plot( 'Generation', 'UNIFORM', data=df, color='green')
plt.plot( 'Generation', 'SINGLE_POINT', data=df, color='blue')
plt.legend()
plt.savefig("plot2.png")