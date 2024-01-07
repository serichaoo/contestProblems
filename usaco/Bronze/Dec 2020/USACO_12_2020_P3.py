numCows=int(input())
cowInfo=[]
for i in range(numCows):
    placeholder=[]
    placeholder=input().split()
    placeholder[1]=int(placeholder[1])
    placeholder[2]=int(placeholder[2])
    placeholder.append(0)
    placeholder.insert(0, i)
    cowInfo.append(placeholder)
#cowInfo has now been fully set up
movingCows=[]
for i in range(numCows):
    movingCows.append(i)
eatenSquares=[]
tempSquares=[]
xPositionsN=[]
yPositionsE=[]
xPositionsE=[]
yPositionsN=[]
toBeRemoved=[]
for i in range(numCows):
    if cowInfo[i][1]=='N':
        xPositionsN.append(cowInfo[i][2])
        yPositionsN.append(cowInfo[i][3])
    else:
        yPositionsE.append(cowInfo[i][3])
        xPositionsE.append(cowInfo[i][2])
for i in movingCows:
    if cowInfo[i][1]=='E' and cowInfo[i][3]<min(yPositionsN):
        cowInfo[i][4]="Infinity"
        toBeRemoved.append(i)
    elif cowInfo[i][1]=='N' and cowInfo[i][2]<min(xPositionsE):
        cowInfo[i][4]="Infinity"
        toBeRemoved.append(i)
for i in toBeRemoved:
    movingCows.remove(i)
toBeRemoved=[]
#cows that will obviously go infinitely far are taken care of immediately
def move(cow, direction, xPos, yPos, step):
    if direction=='E':
        if ([xPos, yPos] not in eatenSquares) or ([xPos, yPos] in tempSquares):
            eatenSquares.append([xPos, yPos])
            cowInfo[cow][2]+=step
            cowInfo[cow][4]+=step
            tempSquares.append([xPos, yPos])
            if cowInfo[cow][2]>max(xPositionsN):
                cowInfo[cow][4]="Infinity"
                toBeRemoved.append(cow)
        else:
            toBeRemoved.append(cow)
    if direction=='N':
        if ([xPos, yPos] not in eatenSquares) or ([xPos, yPos] in tempSquares):
            eatenSquares.append([xPos, yPos])
            cowInfo[cow][3]+=step
            cowInfo[cow][4]+=step
            tempSquares.append([xPos, yPos])
            if cowInfo[cow][3]>max(yPositionsE):
                cowInfo[cow][4]="Infinity"
                toBeRemoved.append(cow)
        else:
            toBeRemoved.append(cow)

def strangeMin(spam):
    if len(spam)!=0:
        if min(spam)>0:
            return min(spam)
        else:
            return 1
    else:
        return 10000000000

def maxStep():
    minDistances=[]
    for i in movingCows:
        if cowInfo[i][1]=='E':
            tempMin=[]
            for j in xPositionsN:
                if j>cowInfo[i][2]:
                    tempMin.append(j-cowInfo[1][2])
            minDistances.append(strangeMin(tempMin))
        else:
            tempMin=[]
            for j in yPositionsE:
                if j>cowInfo[i][3]:
                    tempMin.append(j-cowInfo[1][3])
            minDistances.append(strangeMin(tempMin))
    if min(minDistances)==0:
        return 1
    else:
        return min(minDistances)

while len(movingCows)!=0:
    sstep=maxStep()
    for i in movingCows:
        move(cowInfo[i][0], cowInfo[i][1], cowInfo[i][2], cowInfo[i][3], sstep)
    tempSquares=[]
    for i in toBeRemoved:
        movingCows.remove(i)
    toBeRemoved=[]
    #breakpoint()
for i in range(numCows):
    print(cowInfo[i][4])
