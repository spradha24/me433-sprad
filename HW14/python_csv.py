import csv

t_A = [] # column 0
data1_A = [] # column 1

with open('sigA.csv') as f:
    # open the csv file
    reader = csv.reader(f)
    for row in reader:
        # read the rows 1 one by one
        t_A.append(float(row[0])) # leftmost column
        data1_A.append(float(row[1])) # second column
        # data2.append(float(row[2])) # third column

for i in range(len(t)):
    # print the data to verify it was read
    print(str(t_A[i]) + ", " + str(data1_A[i]))
    
t_B = [] # column 0
data1_B = [] # column 1

with open('sigB.csv') as f:
    # open the csv file
    reader = csv.reader(f)
    for row in reader:
        # read the rows 1 one by one
        t_B.append(float(row[0])) # leftmost column
        data1_B.append(float(row[1])) # second column
        # data2.append(float(row[2])) # third column

for i in range(len(t_B)):
    # print the data to verify it was read
    print(str(t_B[i]) + ", " + str(data1_B[i]))
    
t_C = [] # column 0
data1_C = [] # column 1

with open('sigC.csv') as f:
    # open the csv file
    reader = csv.reader(f)
    for row in reader:
        # read the rows 1 one by one
        t_C.append(float(row[0])) # leftmost column
        data1_C.append(float(row[1])) # second column
        # data2.append(float(row[2])) # third column

for i in range(len(t_C)):
    # print the data to verify it was read
    print(str(t_C[i]) + ", " + str(data1_C[i]))
    
t_D = [] # column 0
data1_D = [] # column 1

with open('sigD.csv') as f:
    # open the csv file
    reader = csv.reader(f)
    for row in reader:
        # read the rows 1 one by one
        t_D.append(float(row[0])) # leftmost column
        data1_D.append(float(row[1])) # second column
        # data2.append(float(row[2])) # third column

for i in range(len(t_D)):
    # print the data to verify it was read
    print(str(t_D[i]) + ", " + str(data1_D[i]))