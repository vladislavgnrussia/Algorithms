#include <iostream>
#include <string>
#include <vector>

std::vector<int> prefix_function (const std::string& line){
    int sz = line.size();
    std::vector<int> result(sz);
    result.at(0) = 0;
    int len_last_prefix = 0;
    bool ok = false;

    for (int index = 1; index < sz; index++){

        while (len_last_prefix != 0 and line.at(len_last_prefix) != line.at(index)){
            len_last_prefix = result.at(len_last_prefix - 1);
        }
        if (len_last_prefix == 0 and line.at(0) != line.at(index)){
            result.at(index) = 0;
        }
        else{
            result.at(index) = ++len_last_prefix;
        }
    }
    return result;
}

auto kmp(const std::string& s, const std::string& t){
    int sz = t.size();
    std::string new_s = t + "$" + s;
    std::vector<int> prefixes = prefix_function(new_s);
    // you can use z-function instead of prefix-function
    std::vector<std::pair<int, int>> answer;
    
    for (int index = 0; index < prefixes.size(); index++){
        if (prefixes.at(index) == sz){
            answer.push_back(std::make_pair(index - sz * 2 , index - 1 - sz));
        }
    }
    return answer;
    
}

int main(){
    std::string s, t, new_s;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    std::vector<std::pair<int, int>> result = kmp(s, t);
    printf("count of entries: %d\n", static_cast<int>(result.size()));
    for (auto el : result){
        printf("left: %d | right: %d\n", el.first, el.second);
    }

    return 0;
}
