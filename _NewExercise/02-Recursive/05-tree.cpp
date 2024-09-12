//
// Created by Ignorant on 2024/9/10.
//

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int index = 0;
    int depth = 0;
    Node *parent = nullptr;
    vector<Node *> children;
    int num_of_children = 0;
};

struct Tree {
    Node *root = nullptr;
    int depth = 0;
};

int get_ancestor(Tree &tree, Node *x, Node *y) {
    if (x == tree.root || y == tree.root) {
        return tree.root->index;
    }
    if (x == y) {
        return x->index;
    }
    if (x->parent == y->parent) {
        return x->parent->index;
    }
    if (x->depth < y->depth) {
        return get_ancestor(tree, x, y->parent);
    }
    if (x->depth > y->depth) {
        return get_ancestor(tree, x->parent, y);
    }
    return get_ancestor(tree, x->parent, y->parent);
}

int relation[1000][1000] = {0};

Tree get_tree(Tree &tree, Node *nodes, int r) {
    for (int i = 0; i < 1000; i++) {
        if (nodes[r - 1].parent != nullptr && nodes[r - 1].parent->index == i + 1) {
            continue;
        }
        if (relation[r - 1][i] == 1) {
            Node *child = &nodes[i];
            child->parent = &nodes[r - 1];
            child->depth = nodes[r - 1].depth + 1;
            tree.depth = max(tree.depth, child->depth);
            nodes[r - 1].children.push_back(child);
            nodes[r - 1].num_of_children++;
            get_tree(tree, nodes, i + 1);
        }
    }
    return tree;
}

int main() {
    int n = 0;
    int r = 0;
    cin >> n >> r;
    Node root = {r, 1, nullptr, {}, 0};
    auto *nodes = new Node[n];
    for (int i = 0; i < n; i++) {
        nodes[i].index = i + 1;
    }
    nodes[r - 1] = root;
    Tree tree = {&nodes[r - 1], 1};
    for (int i = 0; i < n - 1; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;
        relation[u - 1][v - 1] = 1;
        relation[v - 1][u - 1] = 1;
    }
    tree = get_tree(tree, nodes, r);
    int q = 0;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
        cout << get_ancestor(tree, &nodes[x - 1], &nodes[y - 1]) << endl;
    }
    delete[] nodes;
    return 0;
}
