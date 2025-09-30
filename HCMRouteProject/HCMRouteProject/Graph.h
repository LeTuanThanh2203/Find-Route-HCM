#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

struct Edge {
    int to;
    double weight;
};

class Graph {
private:
    vector<vector<Edge>> adj;
public:
    Graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v, double w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // song hướng
    }

    vector<int> dijkstra(int start, int end) {
        int n = adj.size();
        vector<double> dist(n, numeric_limits<double>::infinity());
        vector<int> prev(n, -1);
        dist[start] = 0;

        using P = pair<double, int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push(P(0, start));

        while (!pq.empty()) {
            P top = pq.top();
            pq.pop();
            double d = top.first;
            int u = top.second;

            if (d > dist[u]) continue;
            for (auto &e : adj[u]) {
                if (dist[e.to] > dist[u] + e.weight) {
                    dist[e.to] = dist[u] + e.weight;
                    prev[e.to] = u;
                    pq.push(P(dist[e.to], e.to));
                }
            }
        }

        vector<int> path;
        for (int at = end; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};
