#include <iostream>
#include <string>
#include <vector>

std::vector<int> zFunction(std::string line){
    int sz = line.size();
    std::vector<int> result(sz);
    result[0] = 0;
    std::pair<int, int> z_block{0, 0};
    for (int index = 1; index < sz; index++){
        if (index <= z_block.second){
            int now = std::min(result.at(index - z_block.first), z_block.second - index + 1);
            if (now == 0){
                result.at(index) = 0;
                continue;
            }
            int next_1 = now;
            int next_2 = z_block.second + 1;
            while (next_2 < sz and line.at(next_1) == line.at(next_2)){
                next_1++;
                next_2++;
            }
            if (next_2 - 1  > z_block.second){ 
                z_block.second = next_2 - 1;
                z_block.first = index;
            }
            result.at(index) = next_1;
        }
        else{
            int i = 0;
            int j = index;
            while (j < sz and  line.at(i) == line.at(j)){
                i++;
                j++;
            }
            if (i != 0){
                z_block.first = index;
                z_block.second = j - 1;
            }
            result.at(index) = i;
        }
    }
    return result;
}

int main(){

    std::string line;
    std::getline(std::cin, line);
    std::vector<int> answer = zFunction(line);
    for (int index = 0; index < line.size(); index++){
        printf("%d ", answer.at(index));
    }
    
    return 0;
}
