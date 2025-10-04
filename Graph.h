// Graph.h
#pragma once
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>
#include <queue>
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
struct Node {
    int id;
    std::string name;
    double lat;
    double lng;
};

struct Edge {
    int target;
    double weight;
};

class Graph {
private:
    std::unordered_map<int, Node> nodes;
    std::unordered_map<int, std::vector<Edge>> adj;

public:
    void addNode(int id, const std::string& name, double lat, double lng) {
        nodes[id] = { id, name, lat, lng };
    }
    void AddEdgeBetween(int id1, int id2) {
        Node n1 = getNode(id1);
        Node n2 = getNode(id2);
        double dist = haversine(n1.lat, n1.lng, n2.lat, n2.lng);
        addEdge(id1, id2, dist);
    }
    void addEdge(int source, int target, double weight) {
        adj[source].push_back({ target, weight });
        adj[target].push_back({ source, weight }); // nếu là đồ thị vô hướng
    }
	double haversine(double lat1, double lon1, double lat2, double lon2) {  //Hàm tính khoảng cách giữa hai điểm trên bề mặt Trái Đất
        const double R = 6371e3; // bán kính Trái Đất (m)
        double phi1 = lat1 * M_PI / 180;
        double phi2 = lat2 * M_PI / 180;
        double dPhi = (lat2 - lat1) * M_PI / 180;
        double dLambda = (lon2 - lon1) * M_PI / 180;

        double a = sin(dPhi / 2) * sin(dPhi / 2) +
            cos(phi1) * cos(phi2) *
            sin(dLambda / 2) * sin(dLambda / 2);
        double c = 2 * atan2(sqrt(a), sqrt(1 - a));

        return R * c;
    }

    std::vector<int> dijkstra(int startId, int endId) {
        std::unordered_map<int, double> dist;
        std::unordered_map<int, int> prev;
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;

        for (const auto& pair : nodes) {
            dist[pair.first] = std::numeric_limits<double>::infinity();
        }
        dist[startId] = 0;
        pq.push({ 0, startId });

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            double currentDist = top.first;
            int u = top.second;
            if (u == endId) break;

            for (const Edge& edge : adj[u]) {
                double alt = currentDist + edge.weight;
                if (alt < dist[edge.target]) {
                    dist[edge.target] = alt;
                    prev[edge.target] = u;
                    pq.push({ alt, edge.target });
                }
            }
        }

        std::vector<int> path;
        for (int at = endId; prev.count(at); at = prev[at]) {
            path.push_back(at);
        }
        if (startId == endId || !path.empty()) path.push_back(startId);
        std::reverse(path.begin(), path.end());
        return path;
    }

    Node getNode(int id) {
        return nodes[id];
    }
    std::unordered_map<int, Node> getAllNodes() {
        return nodes;
    }
    std::unordered_map<int, std::vector<Edge>> getAllEdges() {
        return adj;
    }
    void clear() {
        nodes.clear();
       
    }


};
