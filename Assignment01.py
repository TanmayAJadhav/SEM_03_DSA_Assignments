# In second year, computer engineering class, group A student's play cricket, group B students play badminton and group C students play football. Write a Python program using functions to compute following: -
# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton.
# (Note- While realizing the group, duplicate entries should be avoided, do not use SET built-in functions)

class Sports:
    def __init__(self,lst,sportsname):
        self.lst=lst
        self.sportsname=sportsname
          
    def inputlist(self):
        no = int(input(f"Enter the number of students who play {self.sportsname}: "))
        for i in range(0,no):
            std = int(input("Enter Roll no: "))
            if std not in self.lst:
                self.lst.append(std)
        self.lenlist1 = len(self.lst)        
        print(f"The list of students who play {self.sportsname}: {self.lst}")
        print(f"The number of students who play {self.sportsname} is : {self.lenlist1}")
        
    def intersection(self,obj):
        inter = Sports([],"Intersection")
        for j in obj.lst:
            if j in self.lst:
                inter.lst.append(j)
        return inter
    
    def union(self,obj):
        uni=Sports([],"Union")
        for k in obj.lst:
            uni.lst.append(k)
        for l in self.lst:
            if l not in uni.lst:
                uni.lst.append(l)
        return uni
    
    def difference(self,obj):
        diff = Sports([],"Difference")
        for l in self.lst:
            if l not in obj.lst:
                diff.lst.append(l)
        return diff

    def Symmetric_differencef(self,obj):
        sym_diff=Sports([],"Symmetric Difference")
        for n in (self.lst+obj.lst):
            if ((n in self.lst) and (n not in obj.lst)) or ((n in obj.lst) and (n not in self.lst)):
                sym_diff.lst.append(n)
        return sym_diff

    def Menu():
        print("********************")
        print("-------MENU--------")
        print("********************")
        print("1) The list of students who play both cricket and badminton")
        print("2) The lst of students who play either cricket or badminton but not both")
        print("3) The list of students who play neither cricket nor badminton")
        print("4) The number of students who play cricket and football but not badminton")
        print("5) The total list of students in second year computer engineering class")
        global choice
        choice = int(input("\nEnter your Choice (from 1 to 5) :"))    

cric=[]
bad=[]
foot=[]
cricket=Sports(cric,"cricket")
badminton=Sports(bad,"badminton")
football=Sports(foot,"football")

cricket.inputlist()
badminton.inputlist()
football.inputlist()

SeCompT = Sports(Sports.union(cricket,badminton).lst,"SeCompT")
SeCompTotal = SeCompT.union(football).lst

Se = Sports(SeCompTotal,"TotalSE")
UnionCNB = Sports(Sports.union(cricket,badminton).lst,"UnionCNB")  

interCNB = cricket.intersection(badminton).lst
sym_diffCNB = cricket.Symmetric_differencef(badminton).lst
diff_SeNUnionCNB = Se.difference(UnionCNB).lst
UnionCNF = cricket.union(football).lst 
union1 = Sports(UnionCNF,"intert")
diff_InterNB = union1.difference(badminton).lst

Sports.Menu()

if choice == 1:
    print("The list of students who play both cricket and badminton is: ", interCNB,"\n")

elif choice == 2:
    print("The list of students who play either cricket or badminton but not both is:", sym_diffCNB,"\n")

elif choice == 3:
    print("The number of students who play neither cricket nor badminton is: ",len(diff_SeNUnionCNB),"\n")

elif choice == 4:
    print("The number of students who play cricket and football but not badminton is: ",len(diff_InterNB),"\n")

elif choice == 5:
    print("The total list of students in second year computer engineering class is: ",SeCompTotal)
elif choice == 6:
    print("Choose only from 1 to 5")    
