text=input()
numbers=text.split()
intNumbers=[]
for i in range(len(numbers)):
    intNumbers.append(int(numbers[i]))
intNumbers.sort()
a=intNumbers[-1]-intNumbers[-2]
b=intNumbers[-1]-intNumbers[-3]
c=intNumbers[-1]-a-b
print(str(a)+' '+str(b)+' '+str(c))
