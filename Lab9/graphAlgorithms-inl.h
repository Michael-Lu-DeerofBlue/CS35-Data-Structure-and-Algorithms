/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include "adts/orderedCollection.h"
#include "adts/stack.h"
#include "adts/stlStack.h"
#include "adts/queue.h"
#include "adts/stlQueue.h"
#include "adts/dictionary.h"
#include "adts/stlHashTable.h"
#include "adts/priorityQueue.h"
#include "adts/stlMinPriorityQueue.h"

template <typename V, typename E, typename W>
bool reachableDFS(V src, V dest, Graph<V, E, W>* g) {
    Stack<V>* stack = new STLStack<V>();
    Dictionary<V,bool>* visited = new STLHashTable<V,bool>();
    stack->push(src);
    visited->insert(src,true);
    V current;
    while(!stack->isEmpty()){
        current = stack->pop();
        if (current == dest){
            delete stack;
            delete visited;
            return true;
        }
        vector<V> neighbors = g->getNeighbors(current);
        for (int i = 0; i < neighbors.size(); i++){
            if (!visited->contains(neighbors[i])){
                visited->insert(neighbors[i],true);
                stack->push(neighbors[i]);
            }
        }
    }
    delete stack;
    delete visited;
    return false;
}

template <typename V, typename E, typename W>
vector<V> shortestLengthPathBFS(V src, V dest, Graph<V, E, W>* g) {
    vector<V> path;
    STLQueue<V> queue;
    STLHashTable<V,V> previous;
    queue.enqueue(src);
    previous.insert(src,src);
    V current;
    while(!queue.isEmpty()){
        current = queue.dequeue();
        if (current == dest){
            path.push_back(dest);
            V prev = previous.get(dest);         
            while(prev != src){
                path.push_back(prev);
                prev = previous.get(prev);
            }
            path.push_back(src);
            vector<V> temp;
            for (int i = path.size()-1; i >= 0 ; i--){
                temp.push_back(path[i]);
            }
            return temp;
        }
        vector<V> neighbors = g->getNeighbors(current);
        for (int i = 0; i < neighbors.size(); i++){
            if (!previous.contains(neighbors[i])){
                previous.insert(neighbors[i],current);
                queue.enqueue(neighbors[i]);
            }
        } 
    }
    if (path.size() == 0){
        throw runtime_error(std::string("Cannot reach destination"));
    }
    return path;
}

template <typename V, typename E, typename W>
Dictionary<V, W>* singleSourceShortestPath(V src, Graph<V, E, W>* g) {
    Dictionary<V,W>* cost = new STLHashTable<V,W>();
    PriorityQueue<W,V>* pq = new STLMinPriorityQueue<W,V>();
    cost->insert(src,0);
    pq->insert(0,src);
    while(!pq->isEmpty()){
        W currPriority = pq->peekPriority();
        V currVertex = pq->remove();
        W currCost = cost->get(currVertex);
        if (currCost == currPriority){
            vector<Edge<V, E, W>> outgoingedges = g->getOutgoingEdges(currVertex);
            for (int i = 0; i < outgoingedges.size(); i++){
                V nextVertex = outgoingedges[i].getDestination();
                W newCost = currCost + outgoingedges[i].getWeight();
                if (!cost->contains(nextVertex)){
                    cost->insert(nextVertex,newCost);
                    pq->insert(newCost,nextVertex);
                }
                else if (newCost < cost->get(nextVertex)){
                    cost->update(nextVertex,newCost);
                    pq->insert(newCost,nextVertex);
                }
            }
        }
    }
    delete pq;
    return cost;
}
