
#ifndef _MGRAPH_H
#define _MGRAPH_H


#include <cstdlib>
#include <stdexcept>
#include <iostream>
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
    bool m_directed;


public:
    MGraph(const Array<V> &vertices, bool isDirected): m_edge_num(0), m_directed(isDirected) {
        m_vertices = vertices;
        size_t size = vertices.size();
        m_edges = Array<Array<W>>(size);
        for (size_t i = 0; i < size; i++)
            m_edges[i] = Array<W>(size);
    }

    MGraph(const size_t &n, bool isDirected): m_edge_num(0), m_directed(isDirected) {
        m_vertices = Array<V>(n);
        for (size_t i = 0; i < n; i++)
            m_vertices.add(i);

        m_edges = Array<Array<W>>(n);
        for (size_t i = 0; i < n; i++) {
            m_edges.add(Array<W>(n));
            for (size_t j = 0; j < n; j++)
                m_edges[i].add(0);
        }
    }

    ~MGraph() = default;

    size_t edgeNum() const {
        return m_edge_num;
    }

    size_t vertexNum() const {
        return m_vertices.size();
    }

    void addEdge(const size_t &w, const size_t &v, const W &weight) {
        if (w >= vertexNum() || v >= vertexNum())
            throw out_of_range("Illegal Vertex Index.");
        if (w == v)
            return;

        m_edges[w][v] = weight;
        m_edge_num++;
        if (!m_directed) {
            m_edges[v][w] = weight;
            m_edge_num++;
        }
    }

    void addEdge(const size_t &w, const size_t &v) {
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
        if (!m_directed) {
            m_edges[v][w] = 0;
            m_edge_num--;
        }
        return ret;
    }

    friend ostream &operator<<(ostream &os, const MGraph<V, W> &mGraph) {
        os << "MGraph, ";
        os << "Directed: ";
        os << (mGraph.m_directed ? "True" : "False");
        os << endl << "  ";
        
        size_t size = mGraph.vertexNum();
        for (size_t i = 0; i < size; i++)
            os << mGraph.m_vertices[i] << ' ';
        
        os << endl;
        for (size_t i = 0; i < size; i++) {
            os << mGraph.m_vertices[i] << " ";
            for (size_t j = 0; j < size; j++) {
                os << mGraph.m_edges[i][j];
                if (j < size - 1)
                    os << ' ';
            }

            os << endl;
        }
        return os;
    }
};

#endif
