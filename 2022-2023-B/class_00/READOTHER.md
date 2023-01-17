
# Введение в теорию алгоритмов

## Что такое алгоритм?

Несмотря на то, что алгоритм является интуитивно понятным понятием, приведём
одно из возможных определений. 

**Алгоритм** - это любая корректно определенная вычислительная процедура, на вход
которой подаётся некоторая величина или набор величин и результатом выполнения
которой, являетя выходная последовательность.

С понятием алгоритм связано важное понятие его **корректности**. Алгоритм
называется **корректным**, если для любых его входных данных результатом его работы
являются корректные выходные данные.

Рассмотрим в качестве примера одну из классических задач - задачу
**сортировки**. Дадим ей формальное определение:

**Вход:** Последовательность из <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> чисел <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/c0ec7c9b59f884c4c3cab9c219186008.svg?invert_in_darkmode" align=middle width=106.38505184999998pt height=24.65753399999998pt/>.

**Выход:** Перестановка <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/b43311a70868cc5536fddb982dddd02a.svg?invert_in_darkmode" align=middle width=99.07916864999999pt height=24.7161288pt/> входной
последовательности, такая, что <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a8dad6b01830b003b491d86843b463b8.svg?invert_in_darkmode" align=middle width=133.87328624999998pt height=24.7161288pt/>.

Задачу сортировки можно решать многими алгоритмами, приведём для примера один из самых
простых - **сортировку вставками** (**insertion sort**). 

Псевдокод сортировки вставками:

```
for j = 2 to A.length
    key = A[j]
    i = j - 1
    while i > 0 and A[i] > key
        A[i+1] = A[i]
        i = i - 1
    A[i+1] = key
```

Пусть задана последовательность <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/bf884713f064a948d04c79f15ee751e1.svg?invert_in_darkmode" align=middle width=98.63010629999998pt height=24.65753399999998pt/>. Тогда после
каждого прохода цикла `for` будем иметь:

<p align="center"><img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/20ccf454c8c6a9c3cfda14fbb5dc1448.svg?invert_in_darkmode" align=middle width=2096.19488595pt height=20.84357715pt/></p>

## Корректность алгоритма

Докажем корректность алгоритма сортировки вставками с помощью **инварианта цикла**. 

**Инвариант цикла** -- логическое выражение, 
которое остаётся истинным после каждого прохода тела цикла. 
Алгоритм является корректным, если инвариант цикла обладает тремя свойствами:
1. **Инициализация** -- справедливость инварианта цикла перед первой итерацией.
2. **Сохранение** -- если инвариант истинен перед <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/63bb9849783d01d91403bc9a5fea12a2.svg?invert_in_darkmode" align=middle width=9.075367949999992pt height=22.831056599999986pt/>-ой итерацией, то он
   истинен и перед $k+1$-ой итерацией.
3. **Завершение** -- если инвариант истинен, то ответ верный. 


Введём инвариант цикла для нашего алгоритма выше: *после каждой итерации `for` подмассив <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/70c3010dc6243afb80c026c5d2d14cdb.svg?invert_in_darkmode" align=middle width=90.35858204999998pt height=24.65753399999998pt/>
состоит из элементов, которые изначально находились в <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/70c3010dc6243afb80c026c5d2d14cdb.svg?invert_in_darkmode" align=middle width=90.35858204999998pt height=24.65753399999998pt/>, но
теперь отсортированы*. 

Докажем три свойства:
1. **Инициализация:** изначально <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/1fa3fc145a313b9fb0313e57e76415df.svg?invert_in_darkmode" align=middle width=37.84725779999999pt height=21.68300969999999pt/>, <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/bd3ac41de901bf1626487059dede8615.svg?invert_in_darkmode" align=middle width=179.11600079999997pt height=24.65753399999998pt/>.
2. **Сохранение:** неформально говоря, в теле `for` происходит сдвиг элементов
   $A[j-1], A[j-2], \ldots$ на одну позицию вправо пока не найдется *подходящее* место для
   $A[j]$, т. е. такое, что $A[j]$ (находясь на новом месте) не меньше предыдущего и строго меньше
   следующего. Таким образом подмассив $A[1 \ldots j]$ станет отсортированным.
   После $j = j + 1$ будет выполнен инвариант.
3. По завершении имеем <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/9864a4754081957805e2aa8a0696d4a4.svg?invert_in_darkmode" align=middle width=67.80532604999999pt height=21.68300969999999pt/> и <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/8c3510503293c16adbcab7c026b035c1.svg?invert_in_darkmode" align=middle width=90.35858204999998pt height=24.65753399999998pt/> - отсортирован, т. к.
   выполнен инвариант, значит
   отсортирован $A[1 \ldots n]$.

Корректность алгоритма сортировки вставками доказана. <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/365841a3c2f20d1b1a7fa5bf49ebb8ea.svg?invert_in_darkmode" align=middle width=12.785434199999989pt height=22.19178720000002pt/>


## Анализ алгоритмов

Анализ алгоритма заключается в том, чтобы предсказать требуемые для  его
выполнения ресурсы. Чаще всего оценивается время. Но также иногда мы будем 
оценивать количество памяти. Встаёт вопрос как оценивать? При детальном его
рассмотрении вопрос весьма сложный. Мы ограничимся лишь немногими определениями.
И сделаем упор на интуитивное восприятие.

**Время работы алгоритма** измеряется в количестве элементарных операций, которые
надо выполнить. 

Под "элементарной операцией" будем понимать арифметическую или логическую
операцию с целым числом (в том числе сравнение). 

**Размер входных данных** зависит от задачи. Во многих задачах это просто
количество входных элементов.

### Анализ сортировки вставками

приведём еще раз код, алгоритма и возле каждой строки пометим сколько раз она
выполняется в алгоритме:

| Строка | Количество повторений |
| ------ | ------ |
| `for j = 2 to A.length` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> |
| `key = A[j]` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/3eeee545b1fbecf1f5a508b7304d7d5c.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> |
| `i = j - 1` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/3eeee545b1fbecf1f5a508b7304d7d5c.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> |
| `while i > 0 and A[i] > key` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/0cd8d4219ea9bfb9edb741d8fa8972c6.svg?invert_in_darkmode" align=middle width=55.70223119999999pt height=26.438629799999987pt/> |
| `A[i+1] = A[i]` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/5dfb66e7fbe590c59aefb5c226d43a16.svg?invert_in_darkmode" align=middle width=94.88029979999999pt height=26.438629799999987pt/> |
| `i = i - 1` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/5dfb66e7fbe590c59aefb5c226d43a16.svg?invert_in_darkmode" align=middle width=94.88029979999999pt height=26.438629799999987pt/> |
| `A[i+1] = key` | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/3eeee545b1fbecf1f5a508b7304d7d5c.svg?invert_in_darkmode" align=middle width=38.17727759999999pt height=21.18721440000001pt/> |

где <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/c8f804b30c49e59f8206cdefe7fb0ec4.svg?invert_in_darkmode" align=middle width=12.040606049999992pt height=20.221802699999984pt/> - количество проверок условия `while` на <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/36b5afebdba34564d884d347484ac0c7.svg?invert_in_darkmode" align=middle width=7.710416999999989pt height=21.68300969999999pt/>-ой итерации внешнего
цикла `for`.

Пусть входная последовательность уже отсортирована, тогда на каждом шаге, мы
будем осуществлять лишь одну проверку в `while`, то есть <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/0aab9642b679df35b488d5b83df4629b.svg?invert_in_darkmode" align=middle width=42.99934154999999pt height=21.18721440000001pt/> для всех 
<img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/5cf84b8aad5808d41db1e352332d85cd.svg?invert_in_darkmode" align=middle width=53.19352499999999pt height=26.447203200000008pt/>. 

Таким образом имеем (просто суммируя все строки таблицы 
в столбце количества повторений):

<p align="center"><img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/04eac8fe5290e7664988b082cef3f6ea.svg?invert_in_darkmode" align=middle width=418.85585115pt height=16.438356pt/></p>

Теперь пусть входная последовательность отсортирована в порядке, обратном
данному. Тогда <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/3f4dccee8b9a290a8984871d98bde886.svg?invert_in_darkmode" align=middle width=42.49054919999999pt height=21.68300969999999pt/> для всех <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/5cf84b8aad5808d41db1e352332d85cd.svg?invert_in_darkmode" align=middle width=53.19352499999999pt height=26.447203200000008pt/>. Следовательно:

<p align="center"><img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/e39e9ccc845f9748d94e42c4ef622e86.svg?invert_in_darkmode" align=middle width=311.38597215pt height=34.7253258pt/></p>

То есть мы рассмотрели лучший и худший случай с точки зрения времени выполнения. 
При дальнейшем анализе алгоритмов, мы будем ориентироваться на худший случай. 

## Разработка алгоритмов

Только что мы рассмотрели алгоритм сортировки вставками. Это пример
**инкрементного** подхода -- мы постепенно решали нашу задачу для всех <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/36b5afebdba34564d884d347484ac0c7.svg?invert_in_darkmode" align=middle width=7.710416999999989pt height=21.68300969999999pt/> от 
<img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/034d0a6be0424bffe9a6e7ac9236c0f5.svg?invert_in_darkmode" align=middle width=8.219209349999991pt height=21.18721440000001pt/> до <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>. 

Ещё одним популярным подходом в разработке алгоритмов является **метод
декомпозиции** или метод **разделяй и властвуй**. Многие алгоритмы разработанные 
таким при помощи этого метода имеют **рекурсивную** структуру. 

Данная парадигма на каждом уровне состоит из 3 шагов:

1. **Разделение** задачи на несколько подзадач, которые представляют собой
   меньшие экземпляры той же задачи.
2. **Властвование** над каждой из подзадач путём её рекурсивного решения. При
   достаточно малом размере подзадачи она может быть решена непосредственно.
3. **Комбинирование** решений каждой подзадачи в решение исходной.

Алгоритм сортировки **слиянием** (**merge sort**) является ярким примером 
этой парадигмы. 

Постановка задачи та же. Разберём алгоритм в очень общем виде:

1. **Разделение:** делим <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>-элементную сортируемую последовательность на две
   подпоследовательности по $n/2$ элементов. 
2. **Властвование:** рекурсивно сортируем последовательности с использованием
   сортировки слиянием.
3. **Комбинирование:** соединяем две отсортированные последовательности для
   получения окончательного отсортированного ответа.

Более подробно сортировка слиянием будет рассмотрена позже.

## Стандартные обозначения и часто встречающиеся функции

Как уже было показано время выполнения алгоритма является функцией зависящей 
от <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/>. Например, в худшем случае время выполнения алгоритма сортировки
вставками будет квадратичной функцией от <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> - количества элементов в входной
последжовательности. 

Краткое обозначение: 
<p align="center"><img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/b26cb503be8cb67bab935b69d4f18fe5.svg?invert_in_darkmode" align=middle width=99.48144525pt height=18.312383099999998pt/></p>

Какой именно смысл этого выражения мы обсуждать не будем, но введём очень общее 
(строго говоря некорректное) правило -- из функции описывающей время выполнения
алгоритма будем брать самый быстрорастущий член.

Приведём наиболее часто встречающиеся в нашем курсе функции в порядке 
увеличения их скорости роста:

| Функция | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/c2ec17c139a8e866e7df7274cd3fd9e8.svg?invert_in_darkmode" align=middle width=40.00371704999999pt height=21.18721440000001pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a42fe370e5cf83036e78eda093d1456a.svg?invert_in_darkmode" align=middle width=48.222926399999984pt height=21.18721440000001pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/238e4d5fe6314119e765063ed87abae2.svg?invert_in_darkmode" align=middle width=56.442135749999984pt height=21.18721440000001pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/6cb7e1099888f2553b215cc02c6b2567.svg?invert_in_darkmode" align=middle width=54.77547239999999pt height=26.76175259999998pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/5e3f2d096874bfae9a2fe8b9a2d981c9.svg?invert_in_darkmode" align=middle width=54.77547239999999pt height=26.76175259999998pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a011879602c705f66499cfcb7a02d874.svg?invert_in_darkmode" align=middle width=54.77547239999999pt height=26.76175259999998pt/> | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/43fbcb6a785182bd5c24afb75a80f928.svg?invert_in_darkmode" align=middle width=54.77547239999999pt height=26.76175259999998pt/> | 
| ------- | ------- | -------- | --------- | ---------- | ---------- | ---------- | ---------- |
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/68f1bbb87512454065f67d6f1803da9e.svg?invert_in_darkmode" align=middle width=41.21390624999999pt height=22.831056599999986pt/> | 2,32 | 3,32     | 6,64      | 9,96       | 13,28      | 19,93      | 26,57      | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/4fd78aba72015f7697ab298a89ec8a9c.svg?invert_in_darkmode" align=middle width=23.565549149999992pt height=24.995338500000003pt/> | 2,23 | 3,16     | 10        | 31,62      | 100        | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/66483eaa045747892b4ec9e7af0be21e.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a0e595dacbc463c3612fcf9c40cac343.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/55a049b8f161ae7cfeb0197d75aff967.svg?invert_in_darkmode" align=middle width=9.86687624999999pt height=14.15524440000002pt/> |        5    | 10       | 100       | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/66483eaa045747892b4ec9e7af0be21e.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a0e595dacbc463c3612fcf9c40cac343.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/43e7e5d805ae33e683f6ddfec02b6efd.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/9e504c5af74ea9ad8254e332a1d55ff8.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/0ada8bc051917c6d3cebde0925458d23.svg?invert_in_darkmode" align=middle width=53.82044084999998pt height=22.831056599999986pt/> | 11,6 | 33,2     | 664       | 9960       |<img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/bcd04784b12328c9a73db217cae13e20.svg?invert_in_darkmode" align=middle width=62.26023539999999pt height=26.76175259999998pt/>|<img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/2bd5e8a96185d79d1027d510a4bb36d7.svg?invert_in_darkmode" align=middle width=54.954352199999995pt height=26.76175259999998pt/> |<img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/efb2aa4b557de301c85d5dc7821921da.svg?invert_in_darkmode" align=middle width=54.954352199999995pt height=26.76175259999998pt/> |
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/021273d50c6ff03efebda428e9e42d77.svg?invert_in_darkmode" align=middle width=16.41942389999999pt height=26.76175259999998pt/> |    25     | 100      | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a0e595dacbc463c3612fcf9c40cac343.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>    | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/43e7e5d805ae33e683f6ddfec02b6efd.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/9e504c5af74ea9ad8254e332a1d55ff8.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/186996cc836533ab0601d8a580cf7847.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/550686362fde6ed94d230836710fd69b.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/69b104384fb98e2ca8d49437b77c09a8.svg?invert_in_darkmode" align=middle width=16.41942389999999pt height=26.76175259999998pt/> |    125    | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/66483eaa045747892b4ec9e7af0be21e.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>   | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/43e7e5d805ae33e683f6ddfec02b6efd.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>    | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/065159456ed4c790e33155c119a0726f.svg?invert_in_darkmode" align=middle width=22.990966349999994pt height=26.76175259999998pt/>     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/186996cc836533ab0601d8a580cf7847.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/58587787f2cc9c0b4bf47bfc3b3592f1.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/ba00b273227965178a0f8455748f3162.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/f8f25e4580c418a51dc556db0d8d2b93.svg?invert_in_darkmode" align=middle width=16.34523329999999pt height=21.839370299999988pt/> |    32     | 1024     | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/8ca8157f6e77b968a84c74214f43733f.svg?invert_in_darkmode" align=middle width=98.26498275pt height=26.76175259999998pt/> |...|...|     ...    |    ...     | 
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/50c0357224674ab662b8ea5e5ca3eb8a.svg?invert_in_darkmode" align=middle width=14.433101099999991pt height=22.831056599999986pt/> | 120        | 3.628.800| ...       | ...        | ...        |     ...    |    ...     |
| <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/b4ad89f6e6010b58fee7a0ecfe8b9daf.svg?invert_in_darkmode" align=middle width=17.99290019999999pt height=21.839370299999988pt/> | 3125      | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/c8d250c8a04e052dbecc78e035493780.svg?invert_in_darkmode" align=middle width=29.54351234999999pt height=26.76175259999998pt/>  | <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/a7e646d767d6a2f59fe85eaa1c986b39.svg?invert_in_darkmode" align=middle width=36.09605999999999pt height=26.76175259999998pt/>  |    ...     |    ...     |     ...    |    ...     | 

Применяя данную таблицу к реальным оценкам времени алгоритмов решения, можно
сделать такие предположения: 
1. Язык **C++**: за 1 секунду <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/3549e9665889bacef5ed91357761d5af.svg?invert_in_darkmode" align=middle width=40.34249834999999pt height=26.76175259999998pt/> итераций
2. Язык **Python**: за 1 секунду <img src="https://rawgit.com/ypodlesov/UG_courses/master/svgs/15e1699668e03a27ae24ebb83df48000.svg?invert_in_darkmode" align=middle width=40.34249834999999pt height=26.76175259999998pt/> итераций

То есть **Python** при решении алгоритмических задач в среднем в 100 раз 
медленнее чем **C++**. Связано это в том числе с тем, что **Python** --
интерпретируемый язык программирования, а **C++** -- компилируемый.




































