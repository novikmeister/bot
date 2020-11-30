class MoneyBox:
    # Конструктор и деструктор, если нужны
    def __init__(self):
        self.k = int(0)
        self.s = int(0)
    # Добавить монетку достоинством value

    def add_coin(self, value):
        self.k += 1
        self.s += value
    # Получить текущее количество монеток в копилке

    def get_coins_number(self):
        return self.k

    # Получить текущее общее достоинство всех монеток
    def get_coins_value(self):
        return self.s

