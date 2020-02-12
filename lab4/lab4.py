
def min_vertex(mk, tg, size):
    min = -1
    for i in range(size):
        if (mk[i] != 1):
            if (min == -1 and tg[i] != 'inf'):
                min = tg[i]
            else:
                if (tg[i] != 'inf'):
                    if (tg[i] < min):
                        min = tg[i]
    if min == -1:
        return min
    for i in range(size):
        if (min == tg[i] and mk[i] != 1):
            min = i
            return min
            break
       #находим вершину с минимальной меткой

def put(actual, rt):
    for i in range(len(graph)):
        if (graph[actual][i] != 0):
            if (tags[i] == 'inf'):
                tags[i] = tags[actual] + graph[actual][i]
                rt[i] = actual
            elif (tags[i] > tags[actual] + graph[actual][i]):
                tags[i] = tags[actual] + graph[actual][i]
                rt[i] = actual
    return               #присваиваем новую метку вершине

def way (rt, nd, st, size):
    if (rt[nd] == '-'):
        return 'no route'
    w = [nd]
    nd = rt[nd]
    for i in range(size):
        if (nd == '-'):
            break
        w.append(nd)
        nd = rt[nd]
    w.reverse()
    return w        #нахождения кратчайшего пути

def graphOutput(graph):
    for i in range(len(graph)):
        print(graph[i])
    return              #вывод графа

'''
graph = [
    [-1, 10, 30, -1, -1, -1, 10, 30, -1, -1],
    [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1],
    [-1, -1, 20, -1, 10, -1, -1, 20, -1, 10],
    [-1, 40, 20, -1, -1, -1, 40, 20, -1, -1],
    [10, -1, 10, -1, -1, 10, -1, 10, -1, -1],
    [-1, 10, 30, -1, -1, -1, 10, 30, -1, -1],
    [-1, -1, -1, -1, -1, -1, -1, -1, -1, -1],
    [-1, -1, 20, -1, 10, -1, -1, 20, -1, 10],
    [-1, 40, 20, -1, -1, -1, 40, 20, -1, -1],
    [10, -1, 10, -1, -1, 10, -1, 10, -1, -1]
    ]     #таблица смежности графов
'''

####################                            ЗАДАНИЕ 1               ####################

graph = [
    [0, 2, 0, 4, 0, 5, 0, 2, 1, 0], 
    [5, 0, 0, 0, 0, 3, 0, 2, 0, 5], 
    [0, 0, 0, 2, 0, 0, 2, 0, 1, 1], 
    [4, 0, 2, 0, 0, 0, 0, 0, 0, 0], 
    [0, 4, 5, 0, 0, 3, 0, 9, 8, 0], 
    [5, 0, 0, 0, 0, 0, 0, 0, 1, 0], 
    [0, 0, 2, 0, 5, 0, 0, 3, 0, 0], 
    [2, 2, 0, 0, 0, 0, 3, 0, 7, 0], 
    [1, 0, 1, 0, 0, 1, 0, 0, 0, 0], 
    [0, 5, 1, 0, 6, 0, 0, 0, 0, 0], 
    ]

'''
import random
qu = 10
graph = []
for i in range(qu):
    gdd = []
    for j in range(qu):
        gdd.append(random.randint(-1, 5))
    graph.append(gdd)
    gdd.clear
   '''
   
print('Задание 1\nМатрица расстояний ориентированного графа: ')
graphOutput(graph)
tags = ['inf']*len(graph)   #отмечаем посещенные вершины
mark = [0]*len(graph)       #посещенные вершины

start = int(input('Введите начальную вершину: '))
if (start < 0 or start >= len(graph)):
    print('Ошибка: неверный номер вершины')
    exit(0)

route = ['-']*len(graph)  #ПУТЬ
end = int(input('Введите конечную вершину: '))
if (end < 0 or end >= len(graph)):
    print('Ошибка: неверный номер вершины') 
    exit(0)

tags[start] = 0
current = start
for i in range(len(graph)):
    put(current, route)
    mark[current] = 1
    current = min_vertex(mark, tags, len(graph))
    if (current == -1):
        
        break
#s = way(route, end, start, len(graph))
if (way(route, end, start, len(graph)) == 'no route'):
    print(way(route, end, start, len(graph)))
else:
    print('Кратчайший путь от вершины ', start, ' до ', end, 'равен ', tags[end],' :', ' -> '.join((str(i) for i in way(route, end, start, len(graph)))))

####################                            ЗАДАНИЕ 2               ####################

print('\nЗадание 2\nМатрица расстояний неориентированного графа: ')
for i in range(len(graph)):
    for j in range(len(graph)):
        if graph[j][i] < graph[i][j]:
            graph[j][i] = graph[i][j]
        else:
            graph[i][j] = graph[j][i]
graphOutput(graph)

