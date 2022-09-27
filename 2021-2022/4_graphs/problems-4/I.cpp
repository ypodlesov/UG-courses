#include <bits/stdc++.h>
// using namespace std;

// #define num long long

using num = long long;
const num lg2 = 20;


struct Node
{
    vector<num> edges, redges; //ребра и обратные ребра
    num timein, timeout;            //время входа и выхода
    num up[lg2];                    //массив вершин выше данной по степени двойки
    num up_forward, up_reverse;
};

std::vector<Node> tree;             //дерево
std::vector<bool> was;              //были ли мы в этой вершине дфсом

void dfs(num v, num p, num up_forward, num up_reverse)  //p это тот, от кого мы пришли
{                                                       //v это вершина которую мы взяли
    if(was[v]) return;
    was[v] = true;

    static num time = 0;
    tree[v].timein = time++;

    tree[v].up_forward = up_forward;  //up_forward это откуда мы пришли снизу
    tree[v].up_reverse = up_reverse;  //up_reverse это корень под-дфса
    tree[v].up[0] = p;
    for(num i = 1; i < lg2; i++) tree[v].up[i] = tree[tree[v].up[i-1]].up[i-1];

    for(auto u : tree[v].edges)     //пробегаем по прямым ребрам и вызваем дфс
        dfs(u, v, u, up_reverse);
    for(auto u : tree[v].redges)   //пробегаем по обратным ребрам и вызываем дфс
        dfs(u, v, up_forward, u);

    tree[v].timeout = time++;
}

bool is_ancestor(num potential_ancestor, num vertex)
{
    return tree[potential_ancestor].timein <= tree[vertex].timein
        && tree[vertex].timeout <= tree[potential_ancestor].timeout;
}

num lca(num v, num u) // обычный LCA
{
    if(is_ancestor(v, u)) return v;
    if(is_ancestor(u, v)) return u;
    for(num i = lg2 - 1; i >= 0; i--) if(!is_ancestor(tree[v].up[i], u)) v = tree[v].up[i];
    return tree[v].up[0];
}

bool forward_reachable(num ancestor, num vertex)
{
    return is_ancestor(tree[vertex].up_forward, ancestor);
}

bool reverse_reachable(num ancestor, num vertex)
{
    return is_ancestor(tree[vertex].up_reverse, ancestor);
}

bool reachable(num start, num finish)
{
    const num ancestor = lca(start, finish);
    return forward_reachable(ancestor, start) && reverse_reachable(ancestor, finish);
}

int main()
{
    num n;
    std::cin >> n;
    tree.resize(n);

    for(num i = 1; i < n; i++)
    {
        num a, b;
        std::cin >> a >> b;
        --a; --b;
        tree[a].edges.push_back(b); //ребро
        tree[b].redges.push_back(a); //обратное ребро
    }
    was.assign(n, false);
    dfs(0, 0, 0, 0);
    num m;
    std::cin >> m;
    while(m--)
    {
        num x, y;
        std::cin >> x >> y;
        --x; --y;
        if(reachable(x, y)) std::cout << "Yes\n";
        else std::cout << "No\n";
    }
}
