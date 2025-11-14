class Engine:
    def __init__(self, power=0, **kwargs):
        super().__init__(**kwargs)
        self.__power = power

    def display(self):
        print("Power =", self.__power)


class Wheels:
    def __init__(self, size=0, **kwargs):
        super().__init__(**kwargs)
        self.__size = size

    def display(self):
        super().display()
        print("Size =", self.__size)


class Car(Wheels, Engine):
    def __init__(self, model=None, power=0, size=0, **kwargs):
        super().__init__(power=power, size=size, **kwargs)
        self.__model = model

    def display(self):
        super().display()
        print("Model =", self.__model)


# Test
c1 = Car(model="Tesla Model S", power=500, size=19)
c1.display()
