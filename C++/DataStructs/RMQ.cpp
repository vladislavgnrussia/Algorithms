#include <iostream>
#include <vector>
#include <cmath>


auto cmp(std::pair<int, int> a, std::pair<int, int> b)
{
    if (a.first > b.first) return a;
    return b;
}

class RMQ
{
public:
std::vector< std::pair<int, int> > tree;
int len;

    RMQ(std::vector<int>& arr)
    {   
        std::vector<std::pair<int, int> > new_arr(arr.size());
        for (int i = 0; i < arr.size(); ++i)
        {
            new_arr.at(i) = std::make_pair(arr.at(i), i);
        }
        tree = std::vector< std::pair<int, int> >(4 * new_arr.size() - 1, std::make_pair(-1e9, -1e9));
        len = (int)new_arr.size();
        build(new_arr, 0, 0, len);
    }

    void build(std::vector< std::pair<int, int> >& arr, int i, int tl, int tr)
    {
        if (tr - tl == 1)
        {
            tree.at(i) = arr.at(tl);
        }
        else
        {
            int middle = (tl + tr) / 2;
            build(arr, 2 * i + 1, tl, middle);
            build(arr, 2 * i + 2, middle, tr);
            tree.at(i) = cmp(tree.at(2 * i + 1), tree.at(2 * i + 2));   
        }
    }

    std::pair<int, int> operate(int ql, int qr, int tl=0 , int tr=-1, int i=0)
    {
        if (tr == -1) tr = len;
        if (tr <= ql or tl >= qr) return std::make_pair(-1e9, -1e9);
        else if (ql <= tl and tr <= qr) return tree.at(i);
        int middle = (tl + tr) / 2;
        return cmp(operate(ql, qr, tl, middle, i * 2 + 1), operate(ql, qr, middle, tr, i * 2 + 2));
    }

    void update(int ind, int x, int i=0, int tl=0, int tr=-1)
    {
        if (tr == -1) tr = len;
        if (tr - tl == 1) tree.at(i) = std::make_pair(x, ind);
        else
        {
            int middle = (tr + tl) / 2;
            if (ind < middle) update(ind, x, i * 2 + 1, tl, middle);
            else update(ind, x, 2 * i + 2, middle, tr);
            tree.at(i) = cmp(tree.at(2 * i + 1), tree.at(2 * i + 2)); 
        }
    }
};
