# Write a Python program to store first year percentage of students in array. Write function for sorting array of floating-point numbers in ascending order 
# using Quick sort and display top five scores.

class Qsort:
    def __init__(self):
        self.arr = []
        self.length = 0

    def takeInput(self):
        self.length = int(input("Enter number of elements in the array : "))
        for i in range(self.length):
            ele = int(input(f"Enter element {i+1} : "))
            self.arr.append(ele)

    def displayArr(self):
        print("Sorted array is : ")
        print(self.arr)

    def quickSort(self,start,end):
        if(start >  end):
            return -1
        else:
            pivot = self.arr[start]
            i = start + 1
            j = end
            while (i < j):
                while (i <= end and self.arr[i] < pivot):
                    i = i + 1

                while (j >= start and self.arr[j] > pivot):
                    j = j - 1

                if (i < j):
                    temp = self.arr[i]
                    self.arr[i] = self.arr[j]
                    self.arr[j] = temp
                    i = i + 1
                    j = j - 1

            temp = self.arr[start]
            self.arr[start] = self.arr[j]
            self.arr[j] = temp
            Qsort.quickSort(self, start, j - 1)
            Qsort.quickSort(self, j + 1, end)

obj = Qsort()
obj.takeInput()
print("Array before sorting : ")
obj.quickSort(0, obj.length - 1)
print("Array after sorting : ")
obj.displayArr()
