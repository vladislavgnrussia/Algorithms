#include <vector>
#include <string>
#include <iostream>

// Задача о ферзях: нужно вывести все расстановки K ферзей
// на доске N*N, так чтобы они не били друг друга
// ответ выводится в форме последовательности чисел от 1 до N (длинна последовательности - N)
// i-ое число означает вертикаль ферзя, стоящего на i-ой горизонтали
// (два ферзя на одной вертикали по смыслу задачи стоять не могут)

bool test(std::vector<int> arr, int pos){
    int column = arr.size();
    int row1 = pos;
    int row2 = pos;
    while (column > 0){
        column--;
        row1--;
        row2++;
        if (arr.at(column) == row1 or arr.at(column) == row2) return false;
    }
    return true;

}

void queens(std::vector<int> arr, std::vector<int> used, int k, int n){
    if (arr.size() == k){
        for (int el: arr){
            printf("%d ", el + 1);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++){

        if (used[i] != 1 and test(arr, i)){
            used[i] = 1;
            arr.push_back(i);
            queens(arr, used, k, n);
            arr.pop_back();
            used[i] = 0;
        }
    }
}

int main(){
    int len, k;
    std::cin >> len >> k;
    std::vector<int> used(len, 0);
    queens(std::vector<int>{}, used, len, k);

    return 0;
}