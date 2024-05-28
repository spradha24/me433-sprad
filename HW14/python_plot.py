import matplotlib.pyplot as plt # for plotting

plt.plot(t_A,data1_A,'b-*', markersize = 1)
plt.xlabel('Time [s]')
plt.ylabel('Signal')
plt.title('Signal vs Time for Data A')
plt.show()

plt.plot(t_B,data1_B,'g-*', markersize = 1)
plt.xlabel('Time [s]')
plt.ylabel('Signal')
plt.title('Signal vs Time for Data B')
plt.show()

plt.plot(t_C,data1_C,'y-*', markersize = 1)
plt.xlabel('Time [s]')
plt.ylabel('Signal')
plt.title('Signal vs Time for Data C')
plt.show()

plt.plot(t_D,data1_D,'r-*', markersize = 1)
plt.xlabel('Time [s]')
plt.ylabel('Signal')
plt.title('Signal vs Time for Data D')
plt.show()