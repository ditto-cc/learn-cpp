
#ifndef OBSERVER_FILEPROCESS_H
#define OBSERVER_FILEPROCESS_H

#include <string>
#include <utility>
#include <set>
#include <random>
#include <ctime>
#include <iostream>
#include "FileProcessProgress.h"

using namespace std;


class FileProcess {
private:
    string m_filename, m_filepath;
    double m_size, m_processed;

    set<FileProcessProgress *> m_progressList;

public:
    explicit FileProcess(string filepath, string filename) : m_filepath(move(filepath)), m_filename(move(filename)),
                                                             m_processed(0) {
        m_size = 1000;
        m_progressList = set<FileProcessProgress *>();
    }

    ~FileProcess() = default;

    void addObserver(FileProcessProgress *progress) {
        m_progressList.insert(progress);
    }

    void removeObserver(FileProcessProgress *progress) {
        m_progressList.erase(progress);
    }

    void process() {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> uniform_dist(1, 10);
        while (m_processed < m_size) {
            m_processed += uniform_dist(gen);
            for (FileProcessProgress *progress : m_progressList) {
                progress->doProgress(min(m_processed, m_size) / m_size);
            }
        }
    }
};

#endif
