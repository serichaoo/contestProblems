numFlowers=int(input())
placeholder=input()
placeholder1=placeholder.split()
numFlowerPetals=[]
for i in range(numFlowers):
    numFlowerPetals.append(int(placeholder1[i]))

total=0

for i in range(numFlowers):
    for j in range(i, numFlowers):
        tempTotal=0
        for k in range(i, j+1):
            tempTotal+=numFlowerPetals[k]
        if tempTotal%(j+1-i)==0:
            tempTotal=tempTotal//(j+1-i)
            if tempTotal in numFlowerPetals[i:j+1]:
                total+=1
print(total)
