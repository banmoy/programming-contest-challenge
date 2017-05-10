/*
 * union find implementations
 *
 * reference: https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf
 */

#include <iostream>
#include <vector>

using namespace std;


// basic operations in union find
class UnionFind {
    public:
        /* find root of the set n belongs to */
        virtual int root(int i) = 0;

        /* union the set n1 belongs to and the set n2 belongs to */
        virtual void unite(int i, int j) = 0;

        /* find whether n1 and n2 belong to one set */
        virtual bool find(int i, int j) = 0;

        /* print the union (i,root(i)) */
        virtual void print() = 0;
};


// id[i] store the root of the set it belongs to
// find: O(1) unite: O(N)
class QuickFind : public UnionFind {
    public:
        QuickFind(int n) : N(n) { init(); }

        void init() {
            id = vector<int>(N);
            for(int i=0; i<N; ++i)
                id[i] = i;
        }

        int root(int i) {
            if(i<0 || i>=N)
                return -1;
            return id[i];
        }

        void unite(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return;
            int p1 = root(i);
            int p2 = root(j);
            if(p1 != p2) {
                for(int k=0; k<N; ++k)
                    if(id[k] == p1)
                        id[k] = p2;
            }
        }

        bool find(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return false;
            return root(i) == root(j);
        }

        void print() {
            cout << "QuickFind: ";
            for(int i=0; i+1<N; ++i)
                cout << "(" << i << "," << id[i] << ") ";
            cout << "(" << N-1 << "," << id[N-1] << ")" << endl;
        }

    private:
        int N;
        vector<int> id;
};


// the root of i is id[...id[id[i]]...] until id[i]==i
// find: O(N) unite: O(N)
// in some cases unite perform better than QuickFind
class QuickUnion: public UnionFind {
    public:
        QuickUnion(int n) : N(n) { init(); }

        void init() {
            id = vector<int>(N);
            for(int i=0; i<N; ++i)
                id[i] = i;
        }

        int root(int i) {
            if(i<0 || i>=N)
                return -1;
            while(id[i] != i)
                i = id[i];
            return i;
        }

        void unite(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return;
            int p1 = root(i);
            int p2 = root(j);
            id[p1] = p2;
        }

        bool find(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return false;
            return root(i) == root(j);
        }

        void print() {
            cout << "QuickUnion: ";
            for(int i=0; i+1<N; ++i)
                cout << "(" << i << "," << id[i] << ") ";
            cout << "(" << N-1 << "," << id[N-1] << ")" << endl;
        }

    private:
        int N;
        vector<int> id;
};


// improve QuickUnion
// w[i] is the size of subtree of i
// when unite i and j, add the tree with the smaller size to the other
// find: O(logN) unite: O(logN)
class WQuickUnion: public UnionFind {
    public:
        WQuickUnion(int n) : N(n) { init(); }

        void init() {
            id = vector<int>(N);
            w = vector<int>(N, 1);
            for(int i=0; i<N; ++i)
                id[i] = i;
        }

        int root(int i) {
            if(i<0 || i>=N)
                return -1;
            while(id[i] != i)
                i = id[i];
            return i;
        }

        void unite(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return;
            int p1 = root(i);
            int p2 = root(j);
            if(w[p1] < w[p2]) {
                id[p1] = p2;
                w[p2] += w[p1];
            } else {
                id[p2] = p1;
                w[p1] += w[p2];
            }
        }

        bool find(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return false;
            return root(i) == root(j);
        }

        void print() {
            cout << "WQuickUnion: ";
            for(int i=0; i+1<N; ++i)
                cout << "(" << i << "," << id[i] << ") ";
            cout << "(" << N-1 << "," << id[N-1] << ")" << endl;
        }

    private:
        int N;
        vector<int> id;
        vector<int> w;
};


// improve WQuickUnion
// w[i] is the size of subtree of i
// 1. when unite i and j, add the tree with the smaller size to the other
// 2. when root i, set id[i] to id[id[i]]
// find: O(log*N) unite: O(log*N) (log*N is constant in this universe)
class PWQuickUnion: public UnionFind {
    public:
        PWQuickUnion(int n) : N(n) { init(); }

        void init() {
            id = vector<int>(N);
            w = vector<int>(N, 1);
            for(int i=0; i<N; ++i)
                id[i] = i;
        }

        int root(int i) {
            if(i<0 || i>=N)
                return -1;
            while(id[i] != i) {
                id[i] = id[id[i]];
                i = id[i];
            }
            return i;
        }

        void unite(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return;
            int p1 = root(i);
            int p2 = root(j);
            if(w[p1] < w[p2]) {
                id[p1] = p2;
                w[p2] += w[p1];
            } else {
                id[p2] = p1;
                w[p1] += w[p2];
            }
        }

        bool find(int i, int j) {
            if(i<0 || i>=N || j<0 || j>=N)
                return false;
            return root(i) == root(j);
        }

        void print() {
            cout << "PWQuickUnion: ";
            for(int i=0; i+1<N; ++i)
                cout << "(" << i << "," << id[i] << ") ";
            cout << "(" << N-1 << "," << id[N-1] << ")" << endl;
        }

    private:
        int N;
        vector<int> id;
        vector<int> w;
};

int main() {
    int N = 10;
    int un[9][2] = {
        {3, 4},
        {4, 9},
        {8, 0},
        {2, 3},
        {5, 6},
        {5, 9},
        {7, 3},
        {4, 8},
        {6, 1}
    };

    QuickFind qf(N);
    for(int i=0; i<9; ++i)
        qf.unite(un[i][0], un[i][1]);
    qf.print();

    QuickUnion qu(N);
    for(int i=0; i<9; ++i)
        qu.unite(un[i][0], un[i][1]);
    qu.print();

    WQuickUnion wqu(N);
    for(int i=0; i<9; ++i)
        wqu.unite(un[i][0], un[i][1]);
    wqu.print();

    PWQuickUnion pwqu(N);
    for(int i=0; i<9; ++i)
        pwqu.unite(un[i][0], un[i][1]);
    pwqu.print();
}