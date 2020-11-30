class Car:
    def __init__(self, capacity, speed, number):
        self.capacity, self.speed, self.number = capacity, speed, number

    def __repr__(self):
        return "<Car capacity:{} speed:{} number:{}>".format(self.capacity, self.speed, self.number)

    def __str__(self):
        return "<Car capacity:{} speed:{} number:{}>".format(self.capacity, self.speed, self.number)

    def __eq__(self, other):
        try:
            return self.number == other.number
        except:
            return "False"
    def __hash__(self):
        return hash(self.number)


