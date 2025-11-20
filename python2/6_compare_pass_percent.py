class Person:
    def __init__(self,name=None,roll=0):
        self.name=name
        self.roll=roll
    def display(self):
        print("Name:",self.name,"\nRoll no:",self.roll)

class Marks:
    def __init__(self,maths=0,computer=0):
        self.maths=maths
        self.computer=computer
         

    def display(self):
        super().display()
        print("Marks\nMaths:",self.maths,"\nComputer:",self.computer)
        


class Student(Marks,Person):
    def __init__(self, name=None,roll=0 ,maths=0, computer=0):
        super().__init__(maths, computer)
        Person.__init__(self,name,roll)
        self.percentage = (self.maths + self.computer) / 2 
    def display(self):
        Marks.display(self)
        print("Percentage:", self.percentage)

        
p1=Student('fg',6,58,79)
p1.display()
p2=Student('abc',2,100,50)
p2.display()
print("\n--- Comparison ---")
if p1.percentage > p2.percentage:
    print(p1.name," has the higher percentage.")
elif p1.percentage < p2.percentage:
    print(p2.name," has the higher percentage.")
else:
    print("Both students have equal percentage.")