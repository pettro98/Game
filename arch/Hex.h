#pragma once

#include "General.h"
#include "Unit.h"


namespace game_module
{
	class Unit;
	class Capital;
	/*!
	\brief Класс моделирует ячейку игрового поля.
	- Геометрически ячейка является првильным шестиугольником.
	- Другое имя класса, используемое в докуметации - гекс.
	*/
	class Hex
	{
	private:
		/*!
		\brief Координаты гекса.
		- Координаты неотрицательны.
		- Первая координата указывает номер строки игровой карты, в которой находится гекс.
		- Вторая координата указывает номер столбца игровой карты, в котором находится гекс.
		*/
		Pair Coordinates;
		/*!
		\brief! Цвет гекса.
		- Цвет гекса совпадает с цветом владельца гекса.
		*/
		hex_color Color;
		/*!
		\brief Указатель на юнит, находящийся в гексе.
		- В случае если юнита нет указатель равен nullptr.
		*/
		Unit * HexUnit;
		/*!
		\brief Указатель на столицу области, которой принадлежит гекс.
		- В случае если гекс не принадлежит области указатель равен nullptr.
		*/
		Capital * HexCapital;
	public:
		/*!
		\brief Деструктор.
		- Освобождает память из под юнита, который находится в гексе.
		*/
		~Hex();
		/*!
		\brief Конструктор.
		- Цвет гекса по умолчанию blank.
		- Все указатели по умолчанию nullptr.

		\param coord1 Значение для инициализации первой координаты гекса.
		\param coord2 Значение для инициализации второй координаты гекса.
		*/
		Hex(size_type coord1, size_type coord2);
		/*!
		\brief Метод возвращает поле Coordinates объекта класса. 
		*/
		Pair coordinates() const;
		/*!
		\brief Метод возвращает поле Color объекта класса. 
		*/
		hex_color color() const;
		/*!
		\brief Метод возвращает тип юнита, находящегося в гексе.
		- Если в гексе нет юнита возвращает тип none.
		*/
		unit_type get_unit_type() const;
		/*!
		\brief Метод возвращает поле HexUnit объекта класса.
		*/
		Unit * get_unit();
		Unit * get_unit() const;
		/*!
		\brief Метод возвращает поле HexCapital объекта класса.
		*/
		Capital * get_capital();
		/*!
		\brief Метод сообщает хранится ли в гексе юнит.
		*/
		bool occupied() const;
		/*!
		\brief Оператор сравнения двух объектов класса.
		- Сравниваются поля Coordinates двух гексов.

		\param hex Гекс, с которым сравнивается данный.
		*/
		bool operator == (const Hex & hex) const;
		/*!
		\brief Метод заменяет цвет гекса на переданный.

		\param new_color Новый цвет гекса.
		*/
		void set_color(hex_color new_color);
		/*!
		\brief Метод связывает новый юнит и данный гекс.
		- Метод удаляет старый юнит гекса.
		- Связывание подразумевает, что юнит и гекс хранят указатели друг на друга.

		\param unit Указатель на юнит, с которым происходит связывание.
		*/
		void set_unit(Unit * unit);
		/*!
		\brief Метод устанавливает новую столицу области гекса.
		- Если переданный параметр new_capital равен nullptr, это значение записывается в HexCapital.
		- Если гекс new_capital содержит юнит столицы, HexCapital начинает указывать на него.
		- Иначе HexCapital начинает указывать на столицу области гекса new_capital.

		\param new_capital Указатель на гекс, по которому устанавливается новая столица области данного гекса.
		*/
		void set_capital(Hex * new_capital);
		/*!
		\brief Метод убирает юнита из гекса.
		- Полю HexUnit объекта класса присваивает значение nullptr;
		*/
		void remove_unit();
		/*!
		\brief Метод удаляет юнит гекса.
		- Очищает память из под поля HexUnit и присваивает ему значение nullptr;
		*/
		void delete_unit();
	};
	/*!
	\brief Оператор сравнения двух гексов.
	- Используется оператор сравнения класса Hex.

	\param hex1 Первый гекс, проходящий сравнение.
	\param hex2 Второй гекс, проходящий сравнение.
	*/
	bool operator != (const Hex & hex1, const Hex & hex2);
	/*!
	\brief Метод возвращает дистанцию между двумя гексами.
	- Дистанция между двумя гексами есть минимальное, кол-во гексов которое нужно "пройти",
	чтобы попасть из одного в другой.
	- "Пройти" из данного гекса можно только в соседний ему.
	- Соседними гексами называются гексы имеющие общее ребро.
	- Расстояние между двумя соседними гексами равно 1, расстояние между гексом и им самим равно 0.

	\param hex1 Координаты первого гекса, для которого производится расчёт дистанции.
	\param hex2 Координаты второго гекса, для которого производится расчёт дистанции.
	*/
	size_type get_distance(const Pair & hex1, const Pair & hex2);
}