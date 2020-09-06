import copy

line = []
expected_out = []
stack = []
found = False
valid = True

car_size = int(input())

while car_size != 0:
    line.append(list(range(1,car_size+1))) # fill list of cars
    cars = copy.deepcopy(line)
    expected_out = [int(i) for i in input().split()]
    while expected_out[0] != 0: # go to next block
        for car in expected_out:
            while not found:
                if(car == cars[0]): # next in line
                    cars.pop(0)
                    found = True
                elif(len(stack) != 0 and car == stack[-1]): # top of stack
                    stack.pop()
                    found = True
                elif(len(cars) == 0 and car != stack[-1]): # no more cars in line, and top of stack isnt it
                    valid = False
                    break
                else: # put car in line
                    stack.append(cars.pop(0))
            found = False
        if(valid):
            print("Yes")
        else:
            print("No")
            valid = True
            cars = copy.deepcopy(line)
            stack.clear()
        expected_out.clear()
        expected_out = [int(i) for i in input().split()]
    car_size = int(input())
        


