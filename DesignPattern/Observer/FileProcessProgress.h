
#ifndef OBSERVER_FILEPROCESSPROGRESS_H
#define OBSERVER_FILEPROCESSPROGRESS_H


class FileProcessProgress {
public:
    virtual ~FileProcessProgress() = default;
    virtual void doProgress(double progress) = 0;
};

#endif
