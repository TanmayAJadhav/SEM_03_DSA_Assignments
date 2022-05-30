# Write a Python program to store second year percentage of students in array, Write function for sorting array of floating point numbers in ascending orderusing 
# a) Insertion sort
# b) Shell Sort and display top five scores.

class SortTech:
    def __init__(self):
        self.arr = []
        self.length = 0

    def TakeInput(self):
        self.length = int(input("Enter number of elememts of array : "))
        for i in range(self.length):
            ele = int(input(f"Enter element {i + 1} : "))
            self.arr.append(ele)

    def bubbleSort(self):
        for i in range(self.length):
            flag = False
            for j in range(self.length - i - 1):
                if self.arr[j] > self.arr[j+1]:
                    flag = True
                    temp = self.arr[j]
                    self.arr[j] = self.arr[j+1]
                    self.arr[j+1] = temp
            if(flag == False):
                break

    def selectionSort(self):  # minimum value che elements left side la sort hotat
        for i in range(self.length):
            min_index = i
            for j in range(min_index + 1, self.length):
                if self.arr[min_index] > self.arr[j]:
                    min_index = j
            temp = self.arr[i]
            self.arr[i] = self.arr[min_index]
            self.arr[min_index] = temp

    def insertionSort(self):
        for i in range(1, self.length):  # iterate from arr[1] to arr[n]
            # save value of cuurrent arr[i] in current variable
            current = self.arr[i]
            j = i - 1  # intialise j to i - 1
            # compare current to its predecessor and j should not be less than zero, if temp is smaller than predecessor
            while ((j >= 0) and (self.arr[j]) > current):
                # move greater elements one position up
                self.arr[j+1] = self.arr[j]
                j -= 1
            self.arr[j+1] = current

    def shellSort(self):  # compare elements by gap interval
        n = self.length
        # here gap is number of elements by 2 and every eteration i dividing gap by to till gap not equal to 1
        gap = int(n / 2)
        while gap > 0:
            for i in range(gap, n):  # then here in for loop i iterate it  with gap to n-1
                current = self.arr[i]
                j = i
                while (j >= gap and (self.arr[j - gap]) > current):
                    self.arr[j] = self.arr[j - gap]
                    j = j - gap
                self.arr[j] = current
            gap = int(gap / 2)

    def displayArray(self):
        print("The sorted array is: ")
        print(self.arr)


def Menu():
    print("------MENU------")
    print("1) Bubble Sort")
    print("2) Selection Sort")
    print("3) Insertion Sort")
    print("4) Shell Sort")

obj = SortTech()
obj.TakeInput()
choice = 1
while choice != 5:
    Menu()
    choice = int(input("Enter your choice: "))
    if choice == 1:
        obj.bubbleSort()
        obj.displayArray()
    elif choice == 2:
        obj.selectionSort()
        obj.displayArray()
    elif choice == 3:
        obj.insertionSort()
        obj.displayArray()
    elif choice == 4:
        obj.shellSort()
        obj.displayArray()
    else:
        print("Invalid choice")
