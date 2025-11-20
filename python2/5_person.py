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
    def display(self):
        # Person.display(self)
        Marks.display(self)
        if(self.maths>=50 and self.computer>=50):
            print("Pass")
        else:
            print("Fail")
p1=Student('Anna',6,98,99)
p1.display()
p2=Student('abc',2,49,50)
p2.display()