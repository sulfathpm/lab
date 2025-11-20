class Person:
    def __init__(self,name=None,phn=0):
        self.name=name
        self.phn=phn
    def display(self):
        print("Name : ",self.name,"\nPhone : ",self.phn)

class Dept:
    def __init__(self,name=None,location=None):
        self.name=name
        self.location=location
    def display(self):
        print("Dept name :",self.name,"\nLocation : ",self.location)
class Employee(Dept,Person):
    def __init__(self, name=None, location=None,phn=0,designation=None,salary=None):
        super().__init__(name, location)
        Person.__init__(self,name,phn)
        self.designation=designation
        self.salary=salary
    def sal_increment(self):
        print("incremented salary : ",self.salary+=0.1*self.salary)
    def display(self):
        Person.display(self)
        Dept.display(self)
        print("Designation : ",self.designation,"\nSalary : ",self.salary)
