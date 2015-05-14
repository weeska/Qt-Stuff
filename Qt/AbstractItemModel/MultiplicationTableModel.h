#ifndef MULTIPLICATIONTABLEMODEL_H
#define MULTIPLICATIONTABLEMODEL_H

#include <QAbstractItemModel>

class MultiplicationTableModel
    : public QAbstractItemModel
{
public:

    MultiplicationTableModel(int n, int m, QObject *parent = 0);

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;


    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

private:
    int m_rowCount;
    int m_columnCount;
};

#endif // MULTIPLICATIONTABLEMODEL_H
