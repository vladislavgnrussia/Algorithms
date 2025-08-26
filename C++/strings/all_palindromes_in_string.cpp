#include <string>
#include <iostream>
#include <vector>

std::vector<int> manaker(const std::string& s)
{
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

int up_div_2(int arg)
{
    return arg % 2 == 0 ? arg / 2 : arg / 2 + 1;
}

std::vector<std::string> multiplePalindrom(const std::string& palindrom)
{
    std::vector<std::string> answer;
    int len;
    int ptr_l;
    if (palindrom.size() % 2 == 0){
        ptr_l = palindrom.size() / 2 - 1;
        len = 2;
    }
    else{
        ptr_l = palindrom.size() / 2;
        len = 1;
    }
    while (ptr_l != -1){
        answer.push_back(palindrom.substr(ptr_l, len));
        len += 2;
        ptr_l--;
    }
    return answer;
}

std::vector<std::string> allPalindromes(const std::string& s)
{
    std::string new_s(s.size() * 2 - 1, '0');
    for (int i = 0; i < s.size() * 2 - 1; i++){
        new_s.at(i) = i % 2 == 0 ? s.at(i / 2) : '#';
    }
    std::vector<int> mnkr = manaker(new_s);
    std::vector<std::string> answer;
    for (int i = 0; i < mnkr.size(); i++){

        std::vector<std::string> palindromes;

        if (i % 2 == 0){
            palindromes = multiplePalindrom(s.substr(i / 2 - mnkr.at(i) / 2, (mnkr.at(i) / 2) * 2 + 1 ));
        }  
        else{
            palindromes = multiplePalindrom(s.substr( (i - 1) / 2 - up_div_2(mnkr.at(i)) + 1, 2 * up_div_2(mnkr.at(i))));
        }
        answer.insert(answer.end(), palindromes.begin(), palindromes.end());
    }
    return answer;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);
    std::vector<std::string> answer = allPalindromes(line);
    for (int i = 0; i < answer.size(); i++){
        printf("%s ", answer.at(i).c_str());
    }
}
