class Person:
    def __init__(self, name=None, age=0):
        self.name = name
        self.age = age

    def display(self):
        print("Name:", self.name)
        print("Age:", self.age)


class Employee(Person):
    def __init__(self, name=None, age=0, empID=0):
        super().__init__(name, age)
        self.empID = empID

    def display(self):
        super().display()
        print("Employee ID:", self.empID)


class Faculty(Employee):
    def __init__(self, name=None, age=0, empID=0, dept=None):
        super().__init__(name, age, empID)
        self.dept = dept

    def display(self):
        super().display()
        print("Department:", self.dept)


class Researcher:
    def can_do_research(self):
        return f"{self.name} can do research"


class Professor(Faculty, Researcher):
    def __init__(self, name=None, age=0, empID=0, dept=None, subject=None):
        super().__init__(name, age, empID, dept)
        self.subject = subject

    def display(self):
        super().display()
        print("Subject:", self.subject)
        print(self.can_do_research())
p1 = Professor("Dr. Alice", 45, 1024, "Computer Science", "AI")
p1.display()
