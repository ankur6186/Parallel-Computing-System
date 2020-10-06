import random
f = open("data1.txt","a+")
for i in range(10000):
	S = str(random.randint(0,1000))+","+str(random.randint(0,800))+","+str(random.randint(1,10))+"\n"
	f.write(S)