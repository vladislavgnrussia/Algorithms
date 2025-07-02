#include <vector>
#include <iostream>

// Функция основана на алгоритме быстрой сортировки
// Суть задачи следующая: необходимо определить к-ый по величине элемент массива
// Можно, например, отсортироваить массив за О(NlogN) и получить к-ый элемент
// А можно за О(N) следующим образом:

int kth_largest_element(std::vector<int> v, int k){
    if (v.size() < 2){
        return v[0];
    }
    else if(v.size() == 2){
        if (v[0] > v[1]) std::swap(v[0], v[1]);
        return v[k];
    }
    else{
        std::vector<int> more;
        std::vector<int> less;
        std::vector<int> equals;
        int sz = v.size();
        int low = v.at(0);
        int high = v.at(sz - 1);
        int medium = v.at(sz / 2);
        int median = low + high + medium - std::min(std::min(low, high), medium) - std::max(std::max(low, high), medium);
        for (int i = 0; i < sz; i++){
            int el = v.at(i);
            if (el < median) less.push_back(el);
            else if (el == median) equals.push_back(el);
            else more.push_back(el);
        }
        if (k < less.size()) return kth_largest_element(less, k);
        else if (k < less.size() + equals.size()) return equals[0];
        else return kth_largest_element(more, k - less.size() - equals.size());
    }
}

int main(){
    int t;
    std::cin >> t;
    std::vector<int> v(t);
    for (int i = 0; i < t; i++){
        std::cin >> v[i];
    }
    int k;
    std::cin >> k;
    printf("%d\n", kth_largest_element(v, k));
    return 0;

}