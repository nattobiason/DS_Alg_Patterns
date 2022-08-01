#include "../data_structures/Graph.h"
using namespace std;

void depthfirstsearch(vertex v){
    v.visited = true;
    for(int i = 0; i < v.adj.size(); i++){
        if(!v.adj[i].v->visited){
            depthfirstsearch(*v.adj[i].v);
        }
    }
}
void DFS(int value){
    vertex *v = search(value);
    depthfirstsearch(*v);
}


int main(){

    return 0;
}