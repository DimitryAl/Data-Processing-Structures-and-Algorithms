
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
        if (graph[actual][i] != -1):
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
print('Матрица расстояний графа: ')
for i in range(len(graph)):
    print(graph[i])
tags = ['inf']*len(graph)
mark = [0]*len(graph)#посещенные вершины

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
print('Кратчайший путь от вершины ', start, ' до ', end, 'равен ', tags[end],' :', ' -> '.join((str(i) for i in way(route, end, start, len(graph)))))
