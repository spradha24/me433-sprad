### MOVING AVERAGE FILTER, modified for better plots

def calc_maf(t, data, x):
    data_maf = [] # empty array to store maf values
    t_maf = [] # empty array to store trimmed t range
    for i in range(len(t) - x + 1):
        maf = sum(data[i:i+x])/x
        data_maf.append(maf)
        t_maf.append(t[i + x - 1])
    return t_maf, data_maf

def plot_fft(sample_rate, t, data, title):
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
    ax1.plot(t,y,'k')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    ax2.loglog(frq,abs(Y),'k') # plotting the fft
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    fig.suptitle(title)
    plt.show()

def plot_fft_maf(sample_rate, t_maf, data_maf, title):
    Fs = sample_rate # sample rate
    Ts = 1.0/Fs; # sampling interval
    ts_maf = np.arange(0,t_maf[-1],Ts) # time vector
    y_maf = data_maf # the data to make the fft from
    n_maf = len(y_maf) # length of the signal
    k_maf = np.arange(n_maf)
    T_maf = n_maf/Fs
    frq_maf = k_maf/T_maf # two sides frequency range
    frq_maf = frq_maf[range(int(n_maf/2))] # one side frequency range
    Y_maf = np.fft.fft(y_maf)/n_maf # fft computing and normalization
    Y_maf = Y_maf[range(int(n_maf/2))]

    fig, (ax1, ax2) = plt.subplots(2, 1)
    ax1.plot(t_maf,y_maf,'r')
    ax1.set_xlabel('Time')
    ax1.set_ylabel('Amplitude')
    ax2.loglog(frq_maf,abs(Y_maf),'r') # plotting the fft
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')
    fig.suptitle(title)
    plt.show()

tA_maf, dataA_maf = calc_maf(tA, dataA, 2000)
plot_fft(10000, tA, dataA, 'Signal A')
plot_fft_maf(10000, tA_maf, dataA_maf, 'Signal A MAF')

tB_maf, dataB_maf = calc_maf(tB, dataB, 1750)
plot_fft(10000, tB, dataB, 'Signal B')
plot_fft_maf(10000, tB_maf, dataB_maf, 'Signal B MAF')

tC_maf, dataC_maf = calc_maf(tC, dataC, 50)
plot_fft(10000, tC, dataC, 'Signal C')
plot_fft_maf(10000, tC_maf, dataC_maf, 'Signal C MAF')

tD_maf, dataD_maf = calc_maf(tD, dataD, 500)
plot_fft(10000, tD, dataD, 'Signal D')
plot_fft_maf(10000, tD_maf, dataD_maf, 'Signal D MAF')