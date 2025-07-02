#include <vector>
#include <iostream>

std::vector<int> merge(std::vector<int> v1, const std::vector<int>& v2){
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}

std::vector<int> quicksort(std::vector<int> v){
    if (v.size() < 2){
        return v;
    }
    else if(v.size() == 2){
        if (v[0] > v[1]) std::swap(v[0], v[1]);
        return v;
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
        less = quicksort(less);
        more = quicksort(more);
        return merge(merge(less, equals), more);
    }
}

int main(){
    int t;
    std::cin >> t;
    std::vector<int> v(t);
    for (int i = 0; i < t; i++){
        std::cin >> v[i];
    }
    std::vector<int> sorted = quicksort(v);
    for (int i = 0; i < t; i++){
        printf("%d ", sorted.at(i));
    }
    return 0;
}