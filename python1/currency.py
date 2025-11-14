class currency:
    def __init__(self,amount=0,unit):
        self.amount=amount
        self.unit=unit
    def display(self):
        print("amount=",self.amount)
        print("Unit=",self.unit)
    def __eq__(self, other):
        if()