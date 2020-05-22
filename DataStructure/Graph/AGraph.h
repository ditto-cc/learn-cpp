
#ifndef _AGRAPH_H
#define _AGRAPH_H


#include <cstddef>
#include <stdexcept>
#include "../Array/Array.h"
#include "../List/LinkedList.h"

using std::out_of_range;


template<class V, typename W = bool>
class AGraph {
private:
    struct EdgeNode {
        size_t adj;
        W weight;
        EdgeNode *next;
    };

    bool m_directed;
    size_t m_vertex_num, m_edge_num;
    Array<size_t> m_vertices;
    Array<EdgeNode*> m_adj_list;

    EdgeNode *getEdgePrior(const size_t &w, const size_t &v) const {
        auto p = m_adj_list[w];
        for (; p->next && p->next->adj != v; p = p->next);
        return p;
    }

    void _addEdge(const size_t &w, const size_t &v, const W &weight) {
        auto *node = new EdgeNode();
        node->adj = v;
        node->weight = weight;
        node->next = m_adj_list[w]->next;
        m_adj_list[w]->next = node;
        m_edge_num++;
    }

    W _removeEdge(const size_t &w, const size_t &v) {
        auto *node = getEdgePrior(w, v);
        if (node->next == nullptr)
            return 0;
        auto *delNode = node->next;
        node->next = delNode->next;
        W ret = delNode->weight;
        delNode->next = nullptr;
        delete delNode;
        return ret;
    }

public:
    AGraph(const size_t &vertex_num, bool directed): m_vertex_num(vertex_num), m_edge_num(0), m_directed(directed) {
        m_vertices = Array<size_t>(vertex_num);
        for (size_t i = 0; i < vertex_num; i++)
            m_vertices.add(i);
        m_adj_list = Array<EdgeNode*>(vertex_num);
        for (size_t i = 0; i < vertex_num; i++) {
            m_adj_list.add(new EdgeNode());
            m_adj_list[i]->next = nullptr;
        }
    }

    AGraph(const Array<size_t> &vertices, bool directed): m_vertex_num(vertices.size()), m_edge_num(0), m_directed(directed) {
        m_vertices = vertices;
        m_adj_list = Array<EdgeNode*>(m_vertex_num);
        for (size_t i = 0; i < m_vertex_num; i++) {
            m_adj_list.add(new EdgeNode());
            m_adj_list[i]->next = nullptr;
        }
    }

    ~AGraph() = default;

    size_t edgeNum() const {
        return m_edge_num;
    }

    size_t vertexNum() const {
        return m_vertices.size();
    }

    bool containsEdge(const size_t &w, const size_t &v) const {
        return getEdgePrior(w, v)->next != nullptr;
    }

    void addEdge(const size_t &w, const size_t &v, const W &weight) {
        if (w >= m_vertex_num || v >= m_vertex_num)
            throw out_of_range("Illegal Vertex Index.");

        if (w == v || containsEdge(w, v))
            return;

        _addEdge(w, v, weight);

        if (!m_directed && !containsEdge(v, w))
            _addEdge(v, w, weight);
    }

    void addEdge(const size_t &w, const size_t &v) {
        addEdge(w, v, true);
    }

    W removeEdge(size_t w, size_t v) {
        if (w >= vertexNum() || v >= vertexNum())
            throw out_of_range("Illegal Vertex.");
        if (w == v)
            return;

        W ret = _removeEdge(w, v);
        if (!m_directed)
            _removeEdge(v, w);
        return ret;
    }

    friend ostream &operator<<(ostream &os, const AGraph<V, W> &aGraph) {
        os << "MGraph, ";
        os << "Directed: ";
        os << (aGraph.m_directed ? "True" : "False");
        os << endl;

        for (size_t i = 0, size = aGraph.vertexNum(); i < size; i++) {
            os << aGraph.m_vertices[i] << ": ";
            EdgeNode *p = aGraph.m_adj_list[i]->next;
            for (; p; p = p->next)
                os << "(" << p->adj << ", " << p->weight << ")->";
            os << "NULL" << endl;
        }
        return os;
    }
};

#endif