### INFINITE IMPULSE RESPONSE

def calc_iir(t, data, a, b):
    data_iir = [data[0]] # empty array to store iir values
    for i in range(1, len(t)):
        iir = a*data_iir[i-1] + b*data[i]
        data_iir.append(iir)
    return data_iir

def plot_iir(sample_rate, t, data, title):
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

    ax1.plot(t,data, 'k')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    
    ax2.loglog(frq,abs(Y),'k') # plotting the fft for unfiltered data
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')

    fig.suptitle(title)
    plt.show()
    
def plot_fft_iir(sample_rate, t, data_iir, title):
    Fs = sample_rate # sample rate
    Ts = 1.0/Fs; # sampling interval
    ts = np.arange(0,t[-1],Ts) # time vector
    y = data_iir # the data to make the fft from
    n = len(y) # length of the signal
    k = np.arange(n)
    T = n/Fs
    frq = k/T # two sides frequency range
    frq = frq[range(int(n/2))] # one side frequency range
    Y = np.fft.fft(y)/n # fft computing and normalization
    Y = Y[range(int(n/2))]
    
    y_iir = data_iir # the data to make the fft from
    Y_iir = np.fft.fft(y_iir)/n # fft computing and normalization
    Y_iir = Y_iir[range(int(n/2))]

    fig, (ax1, ax2) = plt.subplots(2, 1)
    
    ax1.plot(t,data_iir, 'r')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    
    ax2.loglog(frq,abs(Y_iir),'r') # plotting the fft for IIR
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    
    fig.suptitle(title)
    plt.show()
    
    
a_A = 0.99
b_A = 1 - a_A
dataA_iir = calc_iir(tA, dataA, a_A, b_A)
plot_iir(10000, tA, dataA, 'Signal A: IIR')
plot_fft_iir(10000, tA, dataA_iir, 'Signal A: IIR, a = 0.99')

a_B = 0.95
b_B = 1 - a_B
dataB_iir = calc_iir(tB, dataB, a_B, b_B)
plot_iir(10000, tB, dataB, 'Signal B: IIR')
plot_fft_iir(10000, tB, dataB_iir, 'Signal B: IIR, a = 0.95')

a_C = 0.6
b_C = 1 - a_C
dataC_iir = calc_iir(tC, dataC, a_C, b_C)
plot_iir(10000, tC, dataC, 'Signal C: IIR')
plot_fft_iir(10000, tC, dataC_iir, 'Signal C: IIR, a = 0.6')

a_D = 0.99
b_D = 1 - a_D
dataD_iir = calc_iir(tD, dataD, a_D, b_D)
plot_iir(10000, tD, dataD, 'Signal D: IIR')
plot_fft_iir(10000, tD, dataD_iir, 'Signal D: IIR, 0.99')