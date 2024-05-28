import matplotlib.pyplot as plt # for plotting

### PLOTTING SIGNALS

def plot_signals(t, data, title, color, shape, markersize):
    plt.plot(t, data, color+shape, markersize = markersize)
    plt.xlabel('Time [s]')
    plt.ylabel('Signal')
    plt.title(title)
    plt.show()
    
plot_signals(tA, dataA, 'Signal A vs Time', 'b', '-*', markersize = 1)
plot_signals(tB, dataB, 'Signal B vs Time', 'g', '-*', markersize = 1)
plot_signals(tC, dataC, 'Signal C vs Time', 'r', '-*', markersize = 1)
plot_signals(tD, dataD, 'Signal D vs Time', 'y', '-*', markersize = 1)