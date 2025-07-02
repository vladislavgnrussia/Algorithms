#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#define MAX_CATEGORY 9 // константа, означающая максимальный разряд в числах, встречающихся во входных данных
// например, если в условии сказано, что в массиве входных данных числа по модулю не превосходят 10^9, то эта константа равна 9
// сложность ~ O(MAX_CATEGORY * N) - при определенных входных данных рабоает быстрее NlogN - сортировок

std::vector<int> radix_sort(std::vector<int> v, int current_category){
    if (v.size() == 1 or current_category == -1) return v;

    const int rad = std::pow(10, current_category);
    std::vector<std::vector<int>> radix(19); // здесь использован вектор, а не map, т.к вектор работает быстрее (на одном из тестов 0.112 против 0.201)
    for (int i = 0; i < 19; i++){
        radix[i] = std::vector<int> {};
    }
    for (int el: v){
        radix.at((el / rad) % 10 + 9).push_back(el); // (el / rad) % 10 - число, стоящее в разряде rad, +9 нужно для того. чтобы -9 имел индекс 0, а +9 - 18
    }
    std::vector<int> result;
    for (auto& element: radix){
        if (element.size() != 0){
            element = radix_sort(element, current_category - 1);
            result.insert(result.end(), element.begin(), element.end());
        }
    }
    return result;
}

int main(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++){
        std::cin >> v[i];
    }
    std::vector<int> sorted = radix_sort(v, MAX_CATEGORY);
    for (int element: sorted){
        printf("%d ", element);
    }
}