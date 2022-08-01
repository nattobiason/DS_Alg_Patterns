#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct adjVertex{
    vertex *v;
    int weight;
    adjVertex(vertex *x){
        v = x;
        weight = 1;
    }
};

struct vertex{
    int key;
    bool visited;
    int distance;
    vector<adjVertex> adj;

    vertex(int n){
        key = n;
        visited = false;
        distance = 0;
    }
};



class Graph{
    private:
        vector <vertex> vertices;
    public:
        void insertVertex(int value);
        void insertEdge(int v1, int v2, int w);
        void DFS(int v);
        vertex BFS(int s, int e);
        vertex *search(int v);
        void dijkstras(int start, int end);

};

void Graph::insertVertex(int value){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value){
            found = true;
            break;
        }
    }
    if(!found){
        vertex *v = new vertex(value);
        vertices.push_back(*v);
    }
}

void Graph::insertEdge(int v1, int v2, int weight){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].key == v2 && i != j){
                    adjVertex *a = new adjVertex(&vertices[j]);
                    vertices[i].adj.push_back(*a);
                }
            }
        }
    }
}

vertex* Graph::search(int value){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].key == value) return &vertices[i];
    }
    return NULL;
}