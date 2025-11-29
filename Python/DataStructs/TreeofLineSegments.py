from math import log2, ceil
# дерево отрезков для суммы

class RSQ:

    def __init__(self, arr):
        arr = self.prepare_arr(arr)
        self.tree = [0] * (2 * len(arr) - 1)
        self.ln = len(arr)
        self.build(arr, 0, 0, len(arr))

    @staticmethod
    def prepare_arr(arr):
        h = ceil(log2(len(arr)))
        for _ in range((1 << h) - len(arr)):
            arr.append(0)
        return arr

    def build(self, arr, i, tl, tr):
        if tl == tr - 1:
            self.tree[i] = arr[tl]
        else:
            middle = (tl + tr) // 2
            self.build(arr, 2 * i + 1, tl, middle)
            self.build(arr, 2 * i + 2, middle, tr)
            self.tree[i] = self.tree[2 * i + 1] + self.tree[2 * i + 2]

    def sum(self, ql, qr, tl=0, tr=-1, i=0) -> int:
        if tr == -1: tr = self.ln
        if tr <= ql or tl >= qr:
            return 0
        elif tl >= ql and tr <= qr:
            return self.tree[i]
        middle = (tl + tr) // 2
        return self.sum(ql, qr, tl, middle, 2 * i + 1) + self.sum(ql, qr, middle, tr, 2 * i + 2)

    def update(self, ind, x, i=0, tl=0, tr=-1):
        if tr == -1: tr = self.ln
        if tr - tl == 1:
            self.tree[i] = x
        else:
            middle = (tl + tr) // 2
            if ind < middle:
                self.update(ind, x, 2 * i + 1, tl, middle)
            else:
                self.update(ind, x, 2 * i + 2, middle, tr)
            self.tree[i] = self.tree[2 * i + 1] + self.tree[2 * i + 2]

    #not implemented
    def lazy_update(self, i, tl, tr, tree_upd):
        if not tree_upd[i]:
            return
        if tl == tr - 1:
            tree_upd[i] = False
            self.tree[i] = tree_upd[i]
        else:
            tree_upd[2 * i + 1] = tree_upd[2 * i + 2] = tree_upd[i]
            self.tree[i] = (tr - tl) * tree_upd[i]
            tree_upd[i] = False

    #not implemented
    def mass_upd(self, i, tl, tr, ql, qr, x, tree_upd):
        if tl >= qr or tr <= tl:
            return
        elif tl >= ql and tr <= qr:
            tree_upd[i] = x
        else:
            middle = (tl + tr) // 2
            #mass_upd(...)
            #mass_upd(...) от детей
            self.tree[i] = self.tree[2 * i + 1] + self.tree[2 * i + 2]

    def print_tree(self) -> None:
        power = 0
        now = 0
        shift = self.ln * 2 + 2
        while 2 ** power <= self.ln:
            line = []
            for i in range(2 ** power):
                line.append(str(self.tree[now]))
                now += 1
            print(' '.join(line).center(shift))
            power += 1


a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
o = RSQ(a)
o.update(8, 6)
o.print_tree()
print(o.sum(1, 9))
