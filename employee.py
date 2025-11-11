class Person:
    def __init__(self,name=None,age=0):
        self.name=name
        self.age=age
    def display(self):
        print("name=",self.name)
        print("age=",self.age)
class Employee:
    def __init__(self,empID=0):
        self.empID=empID
    def display(self):
        super().display()
        print("Employee id=",self.empID)
class Faculty(Employee):
    def __init__(self,dept):
        self.dept=dept
    def display():
        super().display()
        print("dept=",self.dept)
class Researcher:
    def can_do_research():
        return f"{name} can do research"
class Professor(Faculty,Researcher):
    
