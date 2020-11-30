class cell
{
public:
    // Вертикаль, от 'A' до 'H'
    char v;
    // Горизонталь, от '1' до '8'
    unsigned short int h;

    // Конструктор клетки по умолчанию, создаёт пока ещё несуществующую на поле клетку
    cell(): v(0), h(0) {}

    // Конструктор заданной клетки поля с параметрами
    cell(char v, unsigned short int h): v(v), h(h) {}
};

// Базовый класс шахматной фигуры
class Piece {
protected:
    cell fig;
public:
    // Конструктор и деструктор, а также иные методы, если они нужны

    // Вернуть текущую позицию фигуры
    virtual cell position() const
    {
        return v;
    }

    // Получить множество всех достижимых полей
    virtual vector<cell> moves() const{

    }

    // Проверка, может ли данная фигура ходить на данное поле
    virtual bool available(const cell& q) const{
        return false;
    }
};
// Король, ходит на 1 клетку в любом направлении
class King : public Piece{
public:
    cell position() const {}
    vector<cell> moves() const{

    }
    bool available(const cell& q) const{
        if()
    } 

}

// Слон, ходит только по диагонали в любом направлении на любое количество клеток
class Bishop : public virtual Piece{
    virtual cell position() const {}
    virtual bool available(const cell& q) const{
        if()
    } 

}

// Ладья, ходит только по вертикали и горизонтали в любом направлении на любое количество клеток
class Rook : public virtual Piece{
    virtual cell position() const {}
    virtual bool available(const cell& q) const{
        if()
    }
}

// Ферзь, ходит по диагонали, вертикали и горизонтали в любом направлении на любое количество клеток
// (наследуется от слона и ладьи, это не единственный возможный подход, но в данной задаче это так)
class Queen : public Bishop, public Rook {};