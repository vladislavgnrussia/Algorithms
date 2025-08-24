#include <iostream>
#include <vector>
#include <string>

std::vector<int> prefix(const std::string& str){
    int sz = str.size();
    std::vector<int> result(sz);
    result.at(0) = 0;
    int len_last_prefix = 0;
    bool ok = false;

    for (int index = 1; index < sz; index++){
        //printf("%d %d\n", len_last_prefix, index);
        if (str.at(len_last_prefix) == str.at(index)){
            result.at(index) = ++len_last_prefix;
            continue;  
        }
        while (len_last_prefix != 0){
            len_last_prefix = result.at(len_last_prefix - 1);

            if (str.at(len_last_prefix) == str.at(index)){
                result.at(index) = ++len_last_prefix;
                ok = true;
                break;
            }
        }
        if (not ok) result.at(index) = 0;
        ok = false;
        
    }
    return result;

}

int main(){
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> result = prefix(line);
    for (auto el: result){
        printf("%d ", el );
    }
    printf("\n");
    
    return 0;
}
