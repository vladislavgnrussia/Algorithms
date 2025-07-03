#include <vector>
#include <string>
#include <iostream>

void gen(std::vector<int> v, int n){
    if (v.size() == n){
        for (int el: v) printf("%d", el);
        printf("\n");
    }
    else{
        v.push_back(0);
        gen(v, n);
        v.pop_back();
        v.push_back(1);
        gen(v, n);
    }
}

int main(){
    int n;
    std::cin >> n;
    gen(std::vector<int> {}, n);
    return 0;

}