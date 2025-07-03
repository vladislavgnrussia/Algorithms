#include <vector>
#include <string>
#include <iostream>
#define BLOCK 1000000000 // значение, которого нет в массиве

void genAllPermutations(std::vector<int> arr, std::vector<int> v, int n){
    if (v.size() == n){
        for (int el: v) printf("%d ", el);
        printf("\n");
    }
    else{
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] != BLOCK){
                std::vector<int> new_arr = arr;
                new_arr[i] = BLOCK;
                v.push_back(arr[i]);
                genAllPermutations(new_arr, v, n);
                v.pop_back();
            }
        }
    }
}

void genAllSubsets(std::vector<int> arr, std::vector<int> v, int n){
    if (v.size() == n){
        for (int el: v) printf("%d ", el);
        printf("\n");
    }
    else{
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] != BLOCK){
                v.push_back(arr[i]);
                arr[i] = BLOCK;
                genAllSubsets(arr, v, n);
                v.pop_back();
            }
        }
    }
}

int main(){
    int len;
    std::cin >> len;
    std::vector<int> arr(len);
    for (int i = 0; i < len; i++){
        std::cin >> arr[i];
    }
    for (int n = 1; n <= len; n++){
        genAllSubsets(arr, std::vector<int>{}, n);
    }
    return 0;
}