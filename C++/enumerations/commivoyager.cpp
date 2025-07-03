#include <vector>
#include <string>
#include <iostream>


/*
Метод ветвей и границ
Оптимизация: если длинна маршрута при заходе в определенный город больше текущего минимума (answer) рекурсивный вызов для этого города не выполняется
Также если длинна пути на 1 меньше количества городов, то рекурсивный вызов тоже не выполняется - минимум обновляется сразу
(так как мы знаем следующий город (а соответственно и расстояние до него от текущего) до следующего рекурсивного вызова)
Тесты:
4
0 20 42 35
20 0 30 34
42 30 0 12
35 34 12 0
Ответ - 101

5
0 100 162 162 100
100 0 100 162 162
162 100 0 100 162
162 162 100 0 100
100 162 162 100 0
Ответ - 500

5
0 20 18 12 8
5 0 14 7 11
12 18 0 6 11
11 17 11 0 12
5 5 5 5 0
Ответ - 41

5
0 90 80 40 100
60 0 40 50 70
50 30 0 60 20
10 70 20 0 50
20 40 50 20 0
Ответ - 180
*/

int answer = 1000000000;
std::vector<int> resultWay;

template<typename T> 
void printVector(std::vector<T> v){
    for (T el: v){
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

void commivoyager(int now, std::vector<std::vector<int>> cities, int length, std::vector<bool> used, int n, std::vector<int> way){

    bool is_entry = false;
    if (way.size() == n - 1){
        is_entry = true;
    }
    for (int i = 0; i < n; i++){
        int path = cities[now][i];
        if (path + length < answer and not is_entry and not used[i]){
            used[i] = true;
            way.push_back(i);
            commivoyager(i, cities, length + path, used, n, way);
            used[i] = false;
            way.pop_back();
        }
        else if (not used[i] and is_entry and cities[i][0] + path + length < answer){
            answer = length + path + cities[i][0];
            way.push_back(i);
            way.push_back(0);
            resultWay = way;
            way.pop_back();
            way.pop_back();
        }
    }
}

int main(){
    int len;
    std::cin >> len;
    std::vector<std::vector<int>> cities(len, std::vector<int>(len));
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            std::cin >> cities[i][j];
        }
    }
    std::vector<bool> used(len, false);
    used[0] = true;
    commivoyager(0, cities, 0, used, len, std::vector<int>{0});
    printf("%d\n", answer);
    printVector(resultWay);

    return 0;
}