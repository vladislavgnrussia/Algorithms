#include <vector>
#include <iostream>

std::vector<int> merge(const std::vector<int>& v1, const std::vector<int>& v2){
    int szr = 0;
    int sz1 = (int) v1.size();
    int sz2 = (int) v2.size();
    int p1 = 0;
    int p2 = 0;
    std::vector<int> result(sz1 + sz2);
    while (szr <= sz1 + sz2 - 1){
        if (p1 == sz1 or (p2 < sz2 and v1.at(p1) > v2.at(p2))){
            result.at(szr) = v2.at(p2);
            p2++;
        }
        else{
            result.at(szr) = v1.at(p1);
            p1++;
        }
        szr++;
    }
    return result;
}

std::vector<int> mergesort(std::vector<int> arr){
    if (arr.size() == 1){
        return arr;
    }
    else{
        int sz = (int) arr.size();
        std::vector<int> v1(sz / 2);
        std::vector<int> v2(sz - (sz / 2));
        for (int i = 0; i < sz; i++){
            if (i < sz / 2){
                v1.at(i) = arr.at(i);
            }
            else{
                v2.at(i - (sz / 2)) = arr.at(i);
            }
        }
        return merge(mergesort(v1), mergesort(v2));
    }
}

int main(){
    int t;
    std::cin >> t;
    std::vector<int> v(t);
    for (int i = 0; i < t; i++){
        std::cin >> v[i];
    }
    std::vector<int> sorted = mergesort(v);
    
    for (int i = 0; i < t; i++){
        printf("%d ", sorted.at(i));
    }

    return 0;

}