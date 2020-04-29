t = int(input())
for i in range(t):
    x,y = [int(s) for s in input().split(' ')]
    a,b = [int(s) for s in input().split(' ')]
    # print(x,y)
    price = abs(x-y)*a + min(x,y)*b
    print(price)