class Person:
    def __init__(self, name=None, age=0, **kwargs):
        super().__init__(**kwargs)
        self.name = name
        self.age = age

    def display(self):
        print("Name =", self.name)
        print("Age =", self.age)


class Employee(Person):
    def __init__(self, empID=0, **kwargs):
        super().__init__(**kwargs)
        self.empID = empID

    def display(self):
        super().display()
        print("Employee ID =", self.empID)


class Faculty(Employee):
    def __init__(self, dept=None, **kwargs):
        super().__init__(**kwargs)
        self.dept = dept

    def display(self):
        super().display()
        print("Department =", self.dept)


class Researcher:
    def __init__(self, field=None, **kwargs):
        super().__init__(**kwargs)
        self.field = field

    def can_do_research(self):
        return f"{self.name} can do research in {self.field}."


class Professor(Faculty, Researcher):
    def __init__(self, name, age, empID, dept, field):
        super().__init__(name=name, age=age, empID=empID, dept=dept, field=field)

    def display(self):
        super().display()
        print("Field =", self.field)


# Test it
p1 = Professor(name="Dr. Alice", age=45, empID=1001, dept="Computer Science", field="Artificial Intelligence")
p1.display()
print(p1.can_do_research())
