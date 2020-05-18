
#ifndef _MGRAPH_H
#define _MGRAPH_H


#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "../Array/Array.h"

using std::endl;
using std::ostream;
using std::out_of_range;

template<class V, typename W = bool>
class MGraph {
private:

    Array<V> m_vertices;
    Array<Array<W>> m_edges;
    size_t m_edge_num;
    bool isDirected;


public:
    explicit MGraph(const Array<V> &vertices, bool isDirected): m_edge_num(0), isDirected(isDirected) {
        m_vertices = vertices;
        m_edges = Array<Array<W>>(vertices.size());
        for (size_t i = 0; i < vertices.size(); i++) {
            m_edges[i] = Array<W>(vertices.size());
        }
    }

    ~MGraph() = default;

    size_t edgeNum() const {
        return m_edge_num;
    }

    size_t vertexNum() const {
        return m_vertices.size();
    }

    void addEdge(size_t w, size_t v, const W &weight) {
        if (w >= vertexNum() || v >= vertexNum())
            throw out_of_range("Illegal Vertex.");
        if (w == v)
            return;

        m_edges[w][v] = weight;
        m_edge_num++;
        if (!isDirected) {
            m_edges[v][w] = weight;
            m_edge_num++;
        }
    }

    void addEdge(size_t w, size_t v) {
        addEdge(w, v, true);
    }

    W removeEdge(size_t w, size_t v) {
        if (w >= vertexNum() || v >= vertexNum())
            throw out_of_range("Illegal Vertex.");
        if (w == v)
            return;

        W ret = m_edges[w][v];
        m_edges[w][v] = 0;
        m_edge_num--;
        if (isDirected) {
            m_edges[v][w] = 0;
            m_edge_num--;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const MGraph<V, W> &mGraph) {
        os << "MGraph, ";
        os << "Directed: ";
        os << (mGraph.isDirected ? "True": "False");
        os << endl << "\t";
        size_t size = mGraph.vertexNum();
        for (size_t i = 0; i < size; i++) {
            os << mGraph.m_vertices[i] << '\t';
        }
        os << endl;
        for (size_t i = 0; i < size; i++) {
            os << mGraph.m_vertices[i] << "\t";
            for (size_t j = 0; j < size; j++) {
                os << mGraph.m_edges[i][j];
                if (j < size - 1)
                    os << '\t';
            }

            os << endl;
        }
        return os;
    }
};

#endif
