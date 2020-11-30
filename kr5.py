class GasStation:
    capacity = int(0)
    imeetsya = int(0)
    # Конструктор, принимающий один параметр - ёмкость резервуара колонки
    # Резервуар создаётся пустой
    def __init__(self, capacity):
        self.capacity = capacity

    # Залить в резервуар колонки n литров топлива
    # Если столько не влезает в резервуар - не заливать ничего, выбросить exception
    def fill(self, n):
        if self.capacity >= int(n):
            self.imeetsya +=n
        else:
            print("Failed to fill")


    # Заправиться, забрав при этом из резервура n литров топлива
    # Если столько нет в резервуаре - не забирать из резервуара ничего, выбросить exception
    def tank(self, n):
        if self.imeetsya >= int(n):
            self.imeetsya -= n
        else:
            print("Failed to tank")



    # Запросить остаток топлива в резервуаре
    def get_limit(self):
        return self.imeetsya