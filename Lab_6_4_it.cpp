// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Ітераційний спосіб
// Варіант 30
 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
// Заповнює масив випадковими цілими числами з діапазону [Low, High]
void Create(int* a, const int size, const int Low, const int High);
 
// Виводить елементи масиву в один рядок (кожен елемент - 4 позиції)
void Print(const int* a, const int size);
 
// Повертає мінімальний за модулем елемент масиву
// (якщо таких кілька - перший з них)
int MinAbs(const int* a, const int size);
 
// Повертає індекс першого нульового елемента масиву
// (або -1, якщо нульових елементів немає)
int IndexOfFirstZero(const int* a, const int size);
 
// Повертає суму модулів елементів масиву, починаючи з індексу from
int SumAbsFrom(const int* a, const int size, const int from);
 
// Переставляє елементи масиву: у першій половині - елементи, що стояли
// в парних позиціях (2, 4, ...), у другій - елементи з непарних позицій
// (1, 3, ...); відносне розташування елементів зберігається
void MoveEvenPositionsFirst(int* a, const int size);
 
int main()
{
   int n;
   do
   {
       cout << "n = ";
       cin >> n;
   } while (n < 1);
 
   const int Low = -9;
   const int High = 9;
 
   srand((unsigned)time(NULL));
 
   int* a = new int[n];            // створили динамічний масив
 
   Create(a, n, Low, High);
   cout << "Початковий масив:" << endl;
   Print(a, n);
 
   cout << "1.1. Мінімальний за модулем елемент = " << MinAbs(a, n) << endl;
 
   int z = IndexOfFirstZero(a, n);
   if (z == -1)
       cout << "1.2. Нульових елементів немає, сума модулів = 0" << endl;
   else
       cout << "1.2. Сума модулів елементів після першого нуля = "
            << SumAbsFrom(a, n, z + 1) << endl;
 
   MoveEvenPositionsFirst(a, n);
   cout << "2. Перетворений масив:" << endl;
   Print(a, n);
 
   delete[] a;                     // знищили динамічний масив
 
   return 0;
}
 
void Create(int* a, const int size, const int Low, const int High)
{
   for (int i = 0; i < size; i++)
       a[i] = Low + rand() % (High - Low + 1);
}
 
void Print(const int* a, const int size)
{
   for (int i = 0; i < size; i++)
       cout << setw(4) << a[i];
   cout << endl;
}
 
int MinAbs(const int* a, const int size)
{
   int min = a[0];
   for (int i = 1; i < size; i++)
       if (abs(a[i]) < abs(min))
           min = a[i];
   return min;
}
 
int IndexOfFirstZero(const int* a, const int size)
{
   for (int i = 0; i < size; i++)
       if (a[i] == 0)
           return i;
   return -1;
}
 
int SumAbsFrom(const int* a, const int size, const int from)
{
   int s = 0;
   for (int i = from; i < size; i++)
       s += abs(a[i]);
   return s;
}
 
void MoveEvenPositionsFirst(int* a, const int size)
{
   int* t = new int[size];         // допоміжний динамічний масив
   int k = 0;
 
   for (int i = 1; i < size; i += 2)   // позиції 2, 4, ... (індекси 1, 3, ...)
       t[k++] = a[i];
   for (int i = 0; i < size; i += 2)   // позиції 1, 3, ... (індекси 0, 2, ...)
       t[k++] = a[i];
 
   for (int i = 0; i < size; i++)
       a[i] = t[i];
 
   delete[] t;
}
