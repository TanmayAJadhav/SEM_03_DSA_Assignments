# Write a Python program to compute following computation on matrix:
# a) Addition of two matrices
# b) Subtraction of two matrices
# c) Multiplication of two matrices
# d) Transpose of a matrix

class MyMatrix:
    def __init__(self,r,c):
        self.rows = r
        self.cols = c
        self.matrix = []

    def inputMat(self) :
        for i in range(self.rows):
            list1=[]
            for j in range(self.cols):
                list1.append(int(input("Enter the elements : ")))
            self.matrix.append(list1)    
           

    def displayMat(self):
        for row in self.matrix:
            for i in row:
                print(i,end="\t")
            print()

    def addMat(self, matrix2):
        add = MyMatrix(self.rows,self.cols)
        if  (self.rows != matrix2.rows and self.cols != matrix2.cols):
            return add
        else:
            for i in range(self.rows):
                list1 = []
                for j in range(self.cols):
                    list1.append(self.matrix[i][j] + matrix2.matrix[i][j])
                add.matrix.append(list1)
            return add
        

    def subtraction(self, matrix2):
        sub = MyMatrix(self.rows,self.cols)
        if (self.rows != matrix2.rows and self.cols != matrix2.cols):
            return sub
        else:
            for i in range(self.rows):
                list1 = []
                for j in range(self.cols):
                    list1.append(self.matrix[i][j] - matrix2.matrix[i][j])
                sub.matrix.append(list1)
            return sub

    def mulMat(self, matrix2):
        mul = MyMatrix(self.rows,self.cols)
        if  (self.rows != matrix2.cols):
            return mul
        else:
            for i in range(self.rows):
                list1 = []
                for j in range(matrix2.cols):
                    ele = 0
                    for k in  range(self.cols):
                        ele = ele + self.matrix[i][k] * matrix2.matrix[k][j]
                    list1.append(ele)
                mul.matrix.append(list1)
            return mul

    def transposeMatrix(self):
        trMat =  MyMatrix(self.rows,self.cols)
        col = 0
        for i in range(self.cols):
            list1 = []
            for j in range(self.rows):
                list1.append(self.matrix[j][col])
            trMat.matrix.append(list1)
            col = col + 1
        return trMat     


print("For matrix A: ")
r1 = int(input("Enter the number of rows : "))
c1 = int(input("Enter the number of columns : "))
obj1 = MyMatrix(r1,c1)
obj1.inputMat()
print("Matrix A: ")
obj1.displayMat()

print("For matrix B: ")
r2 = int(input("Enter the number ofpr rows : "))
c2 = int(input("Enter the number of columns : "))
obj2=MyMatrix(r2,c2)
obj2.inputMat()
print("Matrix B: ")
obj2.displayMat()

choice = 0
while choice != 5:
    print("---Menu---")
    print("1) Addition")
    print("2) Subtraction")
    print("3) Multiplication")
    print("4) Transpose")
    print("5) Exit") 
    choice = int(input("\nEnter the Choice (from 1 to 5) : "))
    if choice == 1:
        obj3=obj1.addMat(obj2)
        if not obj3.matrix:
            print("Matrix adddition is not possible")
        else:
            print("Addition Matrix: ")
            obj3.displayMat()

    elif choice == 2:
        obj4=obj1.subtraction(obj2)
        if not obj4.matrix:
            print("Matrix subtraction is not possible")
        else:
            print("Subtraction Matrix: ")
            obj4.displayMat()

    elif choice == 3:
        obj5=obj1.mulMat(obj2)
        if not obj5.matrix:
            print("Matrix multiplication is not possible")
        else:
            print("Multiplication Matrix: ")
            obj5.displayMat()

    elif choice == 4:
        obj6 = obj1.transposeMatrix()
        obj7 = obj2.transposeMatrix()
        print("Transpose of matrix A: ")
        obj6.displayMat()
        print("Transpose of matrix B: ")
        obj7.displayMat()
        
    elif choice == 5:        
        print("THANK YOU")

    else:
        print("Print from 1 to 5 only !")    
