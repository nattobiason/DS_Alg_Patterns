#include <queue>
#include <iostream>
using namespace std;

void BFS(int start, int value){
    queue<vertex> q;
    vertex *v = search(start);
    v->visited = true;
    q.push(*v);
    while(!q.empty()){
        vertex n = q.front(); q.pop();
        for(int i = 0; i < n.adj.size(); i++){
            if(!n.adj[i].v->visited){
                if(n.adj[i].v->key == value) return *n.adj[i].v;
                else{
                    n.adj[i].v->visited = true;
                    q.push(*n.adj[i].v);
                }
            }
        }
        return NULL;
    }
}

int main(){

    return 0;
}