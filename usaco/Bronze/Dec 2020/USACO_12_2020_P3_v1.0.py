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
movingCows=[]
for i in range(numCows):
    movingCows.append(i)
eatenSquares=[]
tempSquares=[]
def move(cow, direction, xPos, yPos):
    if direction=='E':
        if ([xPos, yPos] not in eatenSquares) or ([xPos, yPos] in tempSquares):
            eatenSquares.append([xPos, yPos])
            cowInfo[cow][2]+=1
            cowInfo[cow][4]+=1
            tempSquares.append([xPos, yPos])
            if cowInfo[cow][2]>100:
                cowInfo[cow][4]="Infinity"
                movingCows.remove(cow)
        else:
            movingCows.remove(cow)
    if direction=='N':
        if ([xPos, yPos] not in eatenSquares) or ([xPos, yPos] in tempSquares):
            eatenSquares.append([xPos, yPos])
            cowInfo[cow][3]+=1
            cowInfo[cow][4]+=1
            tempSquares.append([xPos, yPos])
            if cowInfo[cow][3]>100:
                cowInfo[cow][4]="Infinity"
                movingCows.remove(cow)
        else:
            movingCows.remove(cow)
while len(movingCows)!=0:
    for i in movingCows:
        move(cowInfo[i][0], cowInfo[i][1], cowInfo[i][2], cowInfo[i][3])
    tempSquares=[]
for i in range(numCows):
    print(cowInfo[i][4])
