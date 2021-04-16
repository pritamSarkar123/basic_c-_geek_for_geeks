

def sol1():
	arr=[3,1,2,4,0,1,3,2]
	fv=[0]*len(arr)
	bv=[0]*len(arr)

	# forward pass
	leader=arr[0]
	for i in range(1,len(arr)-1):
		if(arr[i]<leader):
			fv[i]=leader-arr[i]
			if(arr[i]>arr[i+1]):
				leader=arr[i]
		else:
			leader=arr[i]
	print(fv)

	#backward pass
	leader=arr[-1]
	for i in range(len(arr)-2,0,-1):
		if(arr[i]<leader):
			bv[i]=leader-arr[i]
			if(arr[i]<arr[i-1]):
				leader=arr[i-1]
		else:
			leader=arr[i]

	print(bv)

	sum_=0
	for i in range(len(arr)):
		sum_+=min(bv[i],fv[i])

	print(sum_)


def sol2():
	# anuj bhai : https://www.youtube.com/watch?v=UZG3-vZlFM4
	arr=[3,1,2,4,0,1,3,2]
	left_high=[0]*len(arr)
	right_high=[0]*len(arr)
	#l to r
	left_high[0]=arr[0]
	for i in range(1,len(arr)):
		left_high[i]=max(arr[i],left_high[i-1])

	# r to l
	l=len(arr)
	right_high[-1]=arr[-1]
	for i in range(l-2,-1,-1):
		right_high[i]=max(arr[i],right_high[i+1])

	print(left_high)
	print(right_high)

	sum_=0
	for i in range(l):
		sum_+=(min(left_high[i],right_high[i])-arr[i])
	print(sum_)



def sol3():
	arr=[3,1,2,4,0,1,3,2]
	left_high_building=arr[0]
	right_high_building=arr[-1]
	water=0
	l=len(arr)
	m=max(arr)+1
	for i in range(1,l-1):
		left_leader=max(left_high_building,arr[i])
		arr[i]=(arr[i]+m*left_high_building)
	print(arr)
	for i in range(l-2,0,-1):
		right_leader=max(right_high_building,(arr[i]%m))
		arr[i]=(min(right_high_building,(arr[i]//m))-arr[i]%m)
	print(arr)
	for i in range(arr):
		water+=i
	print(water)


sol1()
sol2()
sol3()
