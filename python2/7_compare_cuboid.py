class Rectangle:
    def __init__(self,length=0,breadth=0):
        self.length=length
        self.breadth=breadth
    def display(self):
        print("Length : ",self.length,"Breadth : ",self.breadth)
class Cuboid(Rectangle):
    def __init__(self,height=0, length=0, breadth=0):
        super().__init__(length, breadth)
        self.height=height
    def display(self):
        super().display()
        print("Height : ",self.height)
    def volume(self):
        return self.breadth*self.height*self.length
    def __le__(self, other):
        return self.volume()<=other.volume()

c1=Cuboid(5,2,3)
c2=Cuboid(2,3,4)
print("c1<=c2 :",c1<=c2)