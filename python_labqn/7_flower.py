class Flower:
    def __init__(self,name=None):
        self.name=name
        self.petalColor=input("Enter the petal color : ")
    def display(self):
        if self.petalColor is None or self.petalColor == "":
            print("Unknown flower")
        else:    
            print("Name:",self.name,"\nPetal color:",self.petalColor)
f1 = Flower("Rose")
f1.display()

f2 = Flower()
f2.display()
