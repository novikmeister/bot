class Garage:
    # Конструктор и деструктор, если нужны
    def __init__(self):
        self.__cars = []
    # Запарковать машину v
    def park(self, v):
        self.__cars.append(v)
        
    # Пересчитать машины заданного типа t.
    # Вернуть количество.
    def count(self, t):
        k = 0
        for i in range(len(self.__cars)):
            if isinstance(self.__cars[i], t):
                k += 1
        return k


    # Получить самую быструю машину заданного типа t.
    # Вернуть экземпляр.
    def get_fastest_of_type(self, t):
        fastest = 0
        for i in range(len(self.__cars)):
            if isinstance(self.__cars[i], t):
                if fastest == 0:
                    fastest = self.__cars[i]
                elif fastest.speed <= self.__cars[i].speed:
                    fastest = self.__cars[i]
        return fastest










