class Publisher:
    def __init__(self,name=None):
        self.__name=name
    def display(self):
        print("Name of publisher : ",self.__name)

class Book(Publisher):
    def __init__(self,name,title=None,author=None):
        super().__init__(name)
        self.title=title
        self.__author=author
    def display(self):
        super().display()
        print("Title of the book : ",self.title)
        print("\nAuthor of the book : ",self.__author)

class Python(Book):
    def __init__(self,name,title,author,price=0,pages=0):
        super().__init__(name,title,author)
        self.__price=price
        self.pages=pages
    def display(self):
        super().display()
        print("Price of the book: ",self.__price)
        print("Number of pages : ",self.pages)

b1=Python('anna','fundamentals of python','sonia',250,120)
b1.display()