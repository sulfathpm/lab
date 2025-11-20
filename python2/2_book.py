
class Book:
    def __init__(self,title=None,author=None):
        self.title=title
        self.author=author

    def display(self):
        if hasattr(self,"publisher")and self.publisher.strip() != "":
            print(f"{self.title} is written by {self.author} is published by {self.publisher}")

        else:
            print("Unknown Publisher")

            
b=Book("Python", "Guido van Rossum")
b.publisher=input("Enter the publisher name : ")
b.display()
