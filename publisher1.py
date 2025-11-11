class Publisher:
    def __init__(self, name=None):
        self.__name = name

    def display(self):
        print("Name of publisher:", self.__name)


class Book(Publisher):
    def __init__(self, name=None, title=None, author=None):
        super().__init__(name)  # call Publisher constructor
        self.title = title
        self.__author = author

    def display(self):
        super().display()  # call Publisher.display()
        print("Title of the book:", self.title)
        print("Author of the book:", self.__author)


class Python(Book):
    def __init__(self, name=None, title=None, author=None, price=0, pages=0):
        super().__init__(name, title, author)  # call Book constructor
        self.__price = price
        self.pages = pages

    def display(self):
        super().display()  # call Book.display()
        print("Price of the book:", self.__price)
        print("Number of pages:", self.pages)


# Create an object
b1 = Python('Anna Publishers', 'Fundamentals of Python', 'Sonia', 250, 120)

# Display details
b1.display()
