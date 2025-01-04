def solve():
    n,a,b=map(int,input().split())
    s=input()
    x=y=0
    for i in range(10000):
        for j in s:
            if j == 'N':
                y+=1
            elif j=='S':
                y-=1
            elif j=='E':
                x+=1
            else:
                x-=1
            if x==a and y == b:
                print("YES")
                return
    print("NO")

t=int(input())
for _ in range(t):
    solve()