//Thao Phuong

#include "puzzlemodel.h"
#include <QStringList>
#include <QMessageBox>
// time()
#include <time.h>
// random()
#include <stdlib.h>
// abs()
#include <math.h>

PuzzleModel::PuzzleModel(int r, int c, QObject* parent) :
    QObject(parent), m_Rows(r), m_Cols(c) {
    int val=0;
    for (r=0; r<m_Rows; ++r)
        for (c=0; c<m_Cols; ++c)
            m_Positions << val++;
    shuffle();
}

int PuzzleModel::size() const {
    return m_Rows * m_Cols;
}

/**
   @param position1, position2 are positions in a m*n matrix
   @return true if the positions are neighboring.
*/
bool PuzzleModel::neighboring(int position1, int position2) const {
    int abval = abs(position1 - position2);
    return (abval == 1) or (abval == m_Cols);
}

//swapping value
bool PuzzleModel::slide(int tilenum) {
    int mypos = m_Positions.indexOf(tilenum);
    int zp = m_Positions.indexOf(0);
    if (neighboring(zp, mypos)) {
        m_Positions.swap(zp, mypos);
        emit gridChanged();
        return true;
    }
    return false;
}

void PuzzleModel::shuffle() {
    // seed the random number generator with the current time
    srandom(time(0));
    int i=0;
    while (i < 100) {
        int tilenum = random() % size();
        if (slide(tilenum)) ++i;
    }
}

int PuzzleModel::value(int r, int c) const {
    return m_Positions.at(index(r,c));
}

int PuzzleModel::index(int r, int c) const {
    return r*m_Cols+c;
}

bool PuzzleModel::checkOrderedArray() {
    int orderedNumber = 1;
    int count = 0;
    for (int r = 0; r < m_Rows; ++r) {
        for (int c = 0; c < m_Cols; ++c) {
            if (value(r, c)  != orderedNumber)
                return false;
            else {
                count += 1;
                orderedNumber += 1;
                if (count == size() - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

QString PuzzleModel::toString() const {
    QStringList rows;
    for (int r=0; r<m_Rows; ++r) {
        QStringList currentRow;
        for (int c=0; c<m_Cols; ++c) {
            int squareNumber = m_Positions.at(index(r,c));
            QString stringValue = QString("%1").arg(squareNumber);
            currentRow << stringValue;
        }
        rows << currentRow.join("\t");
    }
    return rows.join("\n");
}
