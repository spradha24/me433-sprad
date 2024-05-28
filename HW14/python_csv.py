import csv

### READING CSV FILES

def read_csv(filename):
    t = []
    data = []
    with open(filename) as f:
    # open the csv file
        reader = csv.reader(f)
        for row in reader:
            # read the rows 1 one by one
            t.append(float(row[0])) # leftmost column
            data.append(float(row[1])) # second column
    return t, data

tA, dataA = read_csv('sigA.csv')
tB, dataB = read_csv('sigB.csv')
tC, dataC = read_csv('sigC.csv')
tD, dataD = read_csv('sigD.csv')

# for i in range(len(tA)):
    # print the data to verify it was read
#     print(str(tA[i]) + ", " + str(dataA[i]))