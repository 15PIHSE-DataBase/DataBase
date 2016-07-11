##Перепишите структуру по образцу 39 таска и измените расширение у файлов на *.c
##Вводим новую терминологию##

База данных представляет из себя ДЕРЕВО, состоящее из множества УЗЛОВ, в каждом из которых хранится множетво ЗНАЧЕНИЙ, каждому из которых присвоен свой уникальный КЛЮЧ

##Модель ключа##
Пока это будет некий неповторяющийся int.
Реализация через глобальную переменную.

## Проект: База данных
Лидер группы: Дёмочкин Кирилл  
Разработчики: Бажмин Сергей, Обрезков Вячеслав, Чердакова Алина, Матутин Василий  

##Задачи:  
~~Добавление значения в узел~~

~~Присваивание уникального ключа каждому значению~~

~~Поиск по ключу в конкретном узле или по всему дереву~~

~~Удаление значения из узла~~

Сохранение значений/ключей в файл

Загрузка значений/ключей из файла

Придумать больше функций для работы с базой данных

~~Из-за ключа требуется переделать функции удааления(добавление в массив освободившихся ключей), добавление(присвоение нового ключа), выгрузка дерева из файла(присвоение каждому элементу нового уникального ключа).~~
 
###Иерархическая база данных  
####Основной фунционал:  
Создание новой базы данных  
Удаление базы данных  
Создание нового объекта в базе данных  
Удаление объекта из базы данных  
Поиск по базе данных  

##Вопросы:  
 ~~По какому принципу происходит сортировка?~~  
 ~~какая структура дерева?~~  
 ~~что конкретно подразумевается под "иерархией"?~~  
 ~~как хранить указатели на "потомков"? массивом?~~(список)  
 ~~какие типы данных храним?~~(long, float, bool, char, строка и бинарный)   
 ~~максимальное число потомков?~~(бесконечно)  
 ~~как нам быть с синхронизацией, чтобы не было конфликтов?~~

