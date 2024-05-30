import matplotlib.pyplot as plt
import numpy as np

### PLOTTING FFT

def plot_fft(sample_rate, t, data, title, color):
    Fs = sample_rate # sample rate
    Ts = 1.0/Fs; # sampling interval
    ts = np.arange(0,t[-1],Ts) # time vector
    y = data # the data to make the fft from
    n = len(y) # length of the signal
    k = np.arange(n)
    T = n/Fs
    frq = k/T # two sides frequency range
    frq = frq[range(int(n/2))] # one side frequency range
    Y = np.fft.fft(y)/n # fft computing and normalization
    Y = Y[range(int(n/2))]

    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(t,y,color)
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    ax2.loglog(frq,abs(Y),color) # plotting the fft
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    fig.suptitle(title)
    plt.show()

    
plot_fft(10000, tA, dataA, 'Signal A', 'b')
plot_fft(10000, tB, dataB, 'Signal B', 'g')
plot_fft(10000, tC, dataC, 'Signal C', 'r')
plot_fft(10000, tD, dataD, 'Signal D', 'y')