# a) Write a Python program to store roll numbers of student in array who attended training program in random order. Write function for searching whether 
# particular student attended training program or not, using Linear search and Sentinel search.
# b) Write a Python program to store roll numbers of student array who attended training program in sorted order. Write function for searching whether
# particular student attended training program or not, using Binary search and Fibonacci search.

class Search:
    def __init__(self):
        self.Arr = []
        self.N = 0
        self.sortedArr = []

    def TakeInput(self):
        self.N = int(input("Enter number of elememts of array : "))
        for i in range(self.N):
            ele = int(input(f"Enter element {i+1} : "))
            self.Arr.append(ele)

    def LinearSearch(self, ele):
        for i in range(0, self.N):
            if ele == self.Arr[i]:
                return i
        return -1

    def BinarySearch(self, elem):
        self.sortedArr = self.Arr.copy()
        self.sortedArr.sort()
        Low = 0
        High = (self.N) - 1
        while(Low <= High):
            Mid = int((Low + High)/2)
            if (self.sortedArr[Mid] == elem):
                return Mid
            elif (self.sortedArr[Mid] < elem):
                Low = Mid + 1
            else:
                High = Mid - 1
        return -1

    def sentinelSearch(self, ele):
        last = self.Arr[self.N - 1]
        self.Arr[self.N - 1] = ele
        i = 0
        while (self.Arr[i] != ele) :
            i = i + 1
            self.Arr[self.N - 1] = last
        if ((i < self.N - 1) or (ele == self.Arr[self.N - 1])) :
            return i
        else:
            return -1

    @staticmethod
    def fibonacciValue(n):
        a = b = c = 1
        if n == 0 or n == 1:
            return 0
        else:
            while c < n:
                c = a + b
                a = b
                b = c
        return a

    def fibonaccisearch(self, x):
        sortArr = self.Arr.copy()
        sortArr.sort()
        first = 0
        last = self.N - 1
        flag = 0
        loc = -1
        index = 0
        n = self.N
        while (flag != 1 and first <= last):
            index = Search.fibonacciValue(n)
            if x == sortArr[index + first]:
                flag = 1
                loc = index
                break
            elif (x > sortArr[index + first]):
                first = first + index + 1
            else:
                last = first + index - 1
            n = last - first + 1
        if (flag == 1):
            return (loc + first + 1)
        else:
            return -1
        

def Menu():
    print("----Menu----")
    print("1) Linear search")
    print("2) Binary search")
    print("3) Sentinel Search")
    print("4) Fibonacci Search")
       

a = Search()
a.TakeInput()
ele = int(input("Enter elements to be searched : "))
choice = 1

while choice != 5:
    Menu()
    choice = int(input("\nEnter the Choice (from 1 to 4) : "))
    if choice == 1:
        if a.LinearSearch(ele) == -1:
            print("Element not found")
        else:
            print("Element found in array at index ",a.LinearSearch(ele))

    elif choice == 2:
        if a.BinarySearch(ele) == -1:
            print("Element not found")
        else:
            print("Element found in array at index ",a.BinarySearch(ele))

    elif choice == 3:
        if a.sentinelSearch(ele) == -1:
            print("Element not found")
        else:
            print("Element found in array at index ",a.sentinelSearch(ele))

    elif choice == 4:
        if a.fibonaccisearch(ele) == -1:
            print("Element not found")
        else:
            print("Element found in array at index ",a.fibonaccisearch(ele))
