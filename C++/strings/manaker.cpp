#include <iostream>
#include <string>
#include <vector>

std::vector<int> manaker(const std::string& s){
    int sz = s.size();
    std::vector<int> result(sz, 0);
    result.at(0) = 0;
    int center = 0;
    int len_rightest_pal = 0;
    for (int index = 1; index < sz; index++){
        if (len_rightest_pal + center >= index){
            result.at(index) = std::min(result.at(center * 2 - index), len_rightest_pal + center - index);
        }
        int l = index - result.at(index) - 1;
        int r = index + result.at(index) + 1;
        while (l > -1 and r < sz and s.at(l) == s.at(r)){
            l--;
            r++;
            result.at(index)++;
        }

        if (r > center + len_rightest_pal){
            center = index;
            len_rightest_pal = r - index - 1;
        }
    }
    return result;
}

template<typename T>
void printVector(const std::vector<T>& v ){
    for (T element: v){
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

int main(){
    
    std::string line;
    std::getline(std::cin, line);
    printVector(manaker(line));

    return 0;
}
