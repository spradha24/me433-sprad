### FINITE IMPULSE RESPONSE

def calc_fir(coeff, t, data):
    data_fir = [] 
    t_fir = []
    x = len(coeff)
    for i in range(len(t) - x + 1):
        fir = 0
        for j in range(x):
            fir += coeff[j]*data[i + j]
        data_fir.append(fir)
        t_fir.append(t[i + x - 1])
    return data_fir, t_fir

def plot_fft_fir(sample_rate, t_fir, data_fir, title):
    Fs = sample_rate # sample rate
    Ts = 1.0/Fs; # sampling interval
    ts_fir = np.arange(0,t_fir[-1],Ts) # time vector
    y_fir = data_fir # the data to make the fft from
    n_fir = len(y_fir) # length of the signal
    k_fir = np.arange(n_fir)
    T_fir = n_fir/Fs
    frq_fir = k_fir/T_fir # two sides frequency range
    frq_fir = frq_fir[range(int(n_fir/2))] # one side frequency range
    Y_fir = np.fft.fft(y_fir)/n_fir # fft computing and normalization
    Y_fir = Y_fir[range(int(n_fir/2))]

    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(t_fir,y_fir,'r')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    ax2.loglog(frq_fir,abs(Y_fir),'r') # plotting the fft
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    fig.suptitle(title)
    plt.show()

dataA_fir, tA_fir = calc_fir(coeffA, tA, dataA)
plot_fft(10000, tA, dataA, 'Signal A')
plot_fft_fir(10000, tA_fir, dataA_fir, 'Signal A FIR')

dataB_fir, tB_fir = calc_fir(coeffA, tB, dataB)
plot_fft(10000, tB, dataB, 'Signal B')
plot_fft_fir(10000, tB_fir, dataB_fir, 'Signal B FIR')

dataC_fir, tC_fir = calc_fir(coeffC, tC, dataC)
plot_fft(10000, tC, dataC, 'Signal C')
plot_fft_fir(10000, tC_fir, dataC_fir, 'Signal C FIR')

dataD_fir, tD_fir = calc_fir(coeffA, tD, dataD)
plot_fft(10000, tD, dataD, 'Signal D')
plot_fft_fir(10000, tD_fir, dataD_fir, 'Signal D FIR')