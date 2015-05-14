#include "MultiplicationTableModel.h"

MultiplicationTableModel::MultiplicationTableModel(int n, int m, QObject *parent)
    : QAbstractItemModel(parent)
    , m_rowCount(n)
    , m_columnCount(m)
{
}

QModelIndex MultiplicationTableModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return this->createIndex(row, column);
}

QModelIndex MultiplicationTableModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);
    return QModelIndex();
}

int MultiplicationTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_rowCount;
}

int MultiplicationTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_columnCount;
}

QVariant MultiplicationTableModel::data(const QModelIndex &index, int role) const
{
    if( role == Qt::DisplayRole ) {
        return (index.column() + 1) * (index.row() + 1);
    }

    return QVariant();
}
