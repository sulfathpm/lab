class Engine:
    def __init__(self,power=0):
        self.__power=power
    def display(self):
        print("Power=",self.__power)

class Wheels:
    def __init__(self,size=0):
        self.__size=size
    def display(self):
        super().display
        print("Size = ",self.__size)
        
class Car(Wheels,Engine):
    def __init__(self, model=None,power=0,size=0):
        super().__init__(size)
        Engine.__init__(self,power)
        self.__model=model
    def display(self):
        super().display()
        print("Model=",self.__model)

c1 = Car(model="Tesla Model S", power=500, size=19)
c1.display()
        