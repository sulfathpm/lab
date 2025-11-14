class Currency:
    def __init__(self, unit, amount=0):
        self.amount = amount
        self.unit = unit

    def display(self):
        print("Amount =", self.amount)
        print("Unit =", self.unit)

    def __eq__(self, other):
        if isinstance(other, Currency):
            return self.amount == other.amount and self.unit == other.unit
        return False
c1 = Currency("USD", 100)
c2 = Currency("USD", 100)
c3 = Currency("EUR", 100)
c4 = Currency("USD", 50)

print(c1 == c2)  
print(c1 == c3) 
print(c1 == c4)  
