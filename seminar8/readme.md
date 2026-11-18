Сборник задач по C++ (Ссылки, Перегрузки, Пространства имен, Строки и Векторы)
Задача 1. Пространства имён
Условие:
Дан следующий код:

cpp
namespace mipt
{
	namespace fefm
	{
		struct Point
		{
			int x, y;
		};
	}
	
	namespace frtk
	{
		void print(fefm::Point p)
		{
			std::cout << p.x << " " << p.y << std::endl;
		}
	}
}
Задание:
В функции main создай переменную типа Point (из пространства имён mipt::fefm) и инициализируй её поля значениями x = 10 и y = 20. Вызови функцию print из пространства имён mipt::frtk, передав ей созданную структуру.

Реши эту задачу тремя способами:

Без использования ключевого слова using.

С использованием директив using namespace.

С использованием using-объявлений.

Задача 2. Куб
Условие:
Напиши функцию cube, которая принимает одно число типа int по ссылке и возводит это число в куб. Вызови эту функцию из функции main.

cpp
#include <iostream>
// Тут нужно написать функцию cube

int main()
{
	int a = 5;
	cube(a);
	std::cout << a << std::endl;  // Должно напечатать 125
}
Задача 3. Обмен
Условие:
Напиши функцию swap, которая будет обменивать значения двух переменных типа int.

cpp
#include <iostream>
// Тут нужно написать функцию swap

int main()
{
	int a = 10;
	int b = 20;
	std::cout << a << " " << b << std::endl;  // Должно напечатать 10 20
	
	swap(a, b);
	std::cout << a << " " << b << std::endl;  // Должно напечатать 20 10
}
Задача 4. Возврат ссылки на максимум
Условие:
Дан код с использованием указателей:

cpp
#include <iostream>
int* getPointerToMax(int* pa, int* pb)
{
	if (*pa > *pb)
		return pa;
	else
		return pb;
}

int main()
{
	int a = 10;
	int b = 20;
	
	*getPointerToMax(&a, &b) += 1;
	
	std::cout << a << " " << b << std::endl;
}
Задание: Перепиши этот код, но вместо указателей используй ссылки. В коде не должно остаться ни одного указателя. Название функции getPointerToMax измени на getRefToMax.

Задача 5. Передача структуры по ссылке
Условие:
Дана структура:

cpp
struct Book
{
    std::string title;
    int pages;
    float price;
};
Напиши функцию addPrice, которая принимает на вход структуру Book по ссылке и число x типа float. Функция должна увеличивать цену переданной книги на x. Протестируй функцию в main.

Задача 6. Передача структуры по константной ссылке
Условие:
Дана та же структура Book.
Напиши функцию isExpensive, которая принимает на вход структуру Book по константной ссылке. Функция должна возвращать bool. Если цена книги больше 1000, вернуть true, иначе false. Протестируй функцию в main.

Задача 7. Выбор перегрузки (Тест)
Условие:
Даны перегруженные функции:

cpp
void cat(char x)      {std::cout << "Char" << std::endl;}
void cat(int x)       {std::cout << "Int" << std::endl;}
void cat(long long x) {std::cout << "Long Long" << std::endl;}
Определи, какая из перегрузок будет выбрана (или будет ошибка), при следующих вызовах:

cat(10)

cat(10LL)

cat(static_cast<short>(10))

cpp
char a = 10;
char b = 20;
cat(a + b);
cat(1.0f)

Даны перегруженные функции:

cpp
void dog(int& x)        {std::cout << "Ref" << std::endl;}
void dog(const int& x)  {std::cout << "CRef" << std::endl;}
Определи, какая из перегрузок будет выбрана при вызовах:
6.

cpp
int a = 10;
dog(a);
cpp
const int a = 10;
dog(a);
dog(10);

cpp
int a = 10;
dog(static_cast<int>(a));
cpp
int a = 10;
dog(static_cast<int&>(a));
cpp
int a = 10;
dog(+a);
cpp
int func() {return 10;}
int main() { dog(func()); }
Даны перегруженные функции:

cpp
void cow(const char* str)        {std::cout << "C-string" << std::endl;}
void cow(const std::string& str) {std::cout << "std::string" << std::endl;}
Определи, какая из перегрузок будет выбрана при вызовах:
13.

cpp
char a[10] = "Hello";
cow(a);
cpp
std::string a = "Hello";
cow(a);
cow("Hello");

cow(std::string("Hello"));

cpp
using namespace std::string_literals;
int main() { cow("Hello"s); }
cpp
std::string a = "Hello";
cow(a.c_str());
Задача 8. Добавление скобок
Условие:
Напиши функцию addBrackets, которая добавляет к строке квадратные скобки. Протестируй на коде:

cpp
#include <iostream>
#include <string>
int main()
{
	std::string a = "Cat";
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [Cat]
	
	addBrackets(a);
	std::cout << a << std::endl;  // Должно напечатать [[Cat]]
}
Задача 9. Подсчёт символов
Условие:
Напиши функцию:

cpp
void countLetters(const std::string& str, int& numLetters, int& numDigits)
Функция принимает строку str и подсчитывает число букв и цифр в ней. Количество букв записывается по ссылке numLetters, цифр — по ссылке numDigits. Используй библиотеку cctype. Вызови функцию из main.

Задача 10. Повтор числа в строке
Условие:
Напиши функцию repeat, которая принимает целое число n и возвращает строку, содержащую это число в десятичной записи, повторённое n раз. Протестируй:

cpp
#include <iostream>
int main()
{
	std::cout << repeat(5)  << std::endl;  // Должно напечатать 55555
	std::cout << repeat(10) << std::endl;  // Должно напечатать 10101010101010101010
	std::cout << repeat(-1) << std::endl;  // Не должно ничего печатать
}
Задача 11. Доменное имя
Условие:
Напиши функцию isDomainName, которая принимает строку. Если строка начинается на www. и заканчивается на .com, функция возвращает true, иначе false. Используй методы строки starts_with и ends_with.

cpp
#include <iostream>
#include <string>
// Тут нужно написать функцию isDomainName

int main()
{
	std::cout << isDomainName("www.google.com") << std::endl;         // Напечатает 1
	std::cout << isDomainName("abc") << std::endl;                    // Напечатает 0
	std::cout << isDomainName("hello.com") << std::endl;              // Напечатает 0
}
Задача 12. Удвоение вектора
Условие:
Напиши функцию doubling, которая принимает вектор целых чисел и увеличивает вектор в два раза, путём повтора всех элементов.

cpp
#include <iostream>
#include <string>
#include <vector>
void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
// Тут нужно написать функцию doubling

int main()
{
    std::vector<int> v {10, 20, 30};
    doubling(v);
    print(v);  // Должно напечатать 10 20 30 10 20 30
}
Задача 13. Склейка строк
Условие:
Напиши функцию concatenate, которая принимает вектор из строк и возвращает строку — результат конкатенации всех строк вектора.

cpp
#include <iostream>
#include <string>
#include <vector>
// Тут нужно написать функцию concatenate

int main()
{
	std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
	std::cout << concatenate(v) << std::endl; // Должно напечатать CatDogMouseTigerElk
}