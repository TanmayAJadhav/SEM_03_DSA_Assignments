# Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determines the frequency of occurrence of particular character in the string
# c) To check whether given string is palindrome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string

class String:
    def __init__(self):
        self.list_words = []
        self.list_chars = []
        self.length_words = 0
        self.length_chars = 0

    @staticmethod
    def Strlen(str):
        count = 0
        for i in str:
            count = count + 1
        return count

    def Takeinput(self):
        str = input("Enter a string: ")
        temp = ''
        list1 = []
        for char in str:
            if char not in list1:
               self.list_chars.append(char)
        print(self.list_chars)        
        self.length_chars = String.Strlen(self.list_chars)
        for i in range(self.length_chars):
            if self.list_chars[i] == ' ':
                self.list_words.append(temp)
                print("temp", temp)
                temp = ''
                continue
            temp = temp + self.list_chars[i]
            if i == self.length_chars - 1:
                self.list_words.append(temp)
                break
            self.length_words = String.Strlen(self.list_words)
        print(self.list_words)    

    def LongestWord(self):
        count = 0 
        Max = 0
        for i in self.list_words:
            count = String.Strlen(i)
            if count > Max:
                Max = count
                continue
        for word in self.list_words:
            if Max == String.Strlen(word):
                print(word, end=' ')

    def Occurrence(self, char):
        count = 0
        for i in self.list_chars:
            if char[0] == i:
                count = count + 1
        return count

    def Palindrome(self):
        list1 = []
        Pd_list = []
        count =  0
        for i in self.list_chars:
            if i != ' ':
                list1.append(i)
                Pd_list.append(i)
                count += 1
        i = 0
        j = count - 1
        for i in range(int(count / 2)):
            Pd_list[i] = list1[j]
            i = i + 1
            j = j - 1
        if Pd_list == list1:
            return True
        else:
            return False    
      
    def StringSearch(self, Sub):
        count = String.Strlen(Sub.list_chars)
        print("coubt ",count)
        for i in range(self.length_chars):
            index_str = 0 
            temp_list = []
            if self.list_chars[i] == Sub.list_chars[index_str]:
                index_list = i
                while True:
                    temp_list.append(self.list_chars[index_list])
                    if temp_list == Sub.list_chars:
                        return index_list - count + 1
                    index_list = index_list + 1
                    index_str = index_str + 1
                    if index_list > self.length_chars - 1:
                        break
                    elif self.list_chars[index_list] == Sub.list_chars[index_str]:
                        continue
                    else:
                        break
        return -1

    def WordCount(self):
        list1 = []
        for i in self.list_words:
            if i not in list1:
                list1.append(i)
        for i in list1:
            count = 0
            for j in self.list_words:
                if i == j:
                    count = count + 1
            print(f"The Word '{i}' is {count} times in string")

s1 = String()
s1.Takeinput()
choice = 0
while choice != 6:
    print("-------MENU--------")
    print("1) To find longest word")
    print("2) To find occurence of character")
    print("3) To check palindrome")
    print("4) To search for substring")
    print("5) To find word count")
    print("6) Exit")
    choice = 0 
    choice = int(input("\nEnter your Choice (from 1 to 5) :")) 
    if choice == 1:
            s1.LongestWord()
            print("is the longest word.")
    elif choice == 2:
        char = input("Enter a character: ")
        print(f"'{char}' occurs {s1.Occurrence(char)} times in the string")
    elif choice == 3:
        if s1.Palindrome():
            print("The string is a palindrome")
        else:
            print("The string is not a palindrome")
    elif choice == 4:
        sub = String()
        sub.Takeinput()
        if s1.StringSearch(sub) == -1:
            print("Please enter valid substring")
        else:
            print(s1.StringSearch(sub))

    elif choice == 5:
        print("The number of words are",s1.WordCount())
    elif choice == 6:
        print("Thank you !")
    else:
        print("Please choose from 1 to 5")
    
