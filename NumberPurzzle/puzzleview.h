#ifndef PUZZLE_VIEW_H
#define PUZZLE_VIEW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QActionGroup>
#include <QButtonGroup>

class QGridLayout;
class PuzzleModel;


/** A single tile in the GUI of the 15 puzzle */
class Tile : public QPushButton {
    Q_OBJECT
  public:
    Tile(int tileNumber);
    int getNumber() {return m_Number;}
  private:
    int m_Number;
    
};

/** A view for the puzzle */
class PuzzleView : public QWidget {
    Q_OBJECT
  public:
    PuzzleView(PuzzleModel* model);
  public slots:
    void refresh();
    void tryToSlide(QAbstractButton* button);
  private:
    PuzzleModel *m_Model;
    QGridLayout *m_Layout;
    QButtonGroup m_Tiles;
};

#endif        //  #ifndef PUZZLE_VIEW_H

