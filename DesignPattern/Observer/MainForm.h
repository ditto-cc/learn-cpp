
#ifndef OBSERVER_MAINFORM_H
#define OBSERVER_MAINFORM_H

#include "Form.h"
#include "ProgressBar.h"
#include "FileProcessProgress.h"

class MainForm : public Form, public FileProcessProgress {
private:
    ProgressBar *m_progressBar;

public:
    MainForm() {
        m_progressBar = new ProgressBar();
    }

    ~MainForm() override {
        delete m_progressBar;
    }

    void doProgress(double progress) override {
        m_progressBar->setValue(progress);
    }
};

#endif
