#ifndef PUZZLE_APP_H
#define PUZZLE_APP_H

#include <QApplication>
#include <QMainWindow>

class QAction;
class PuzzleModel;
class PuzzleView;

/** Controller class for puzzle game - manages all other objects. */
class PuzzleApp : public QApplication {
    Q_OBJECT
  public:
    PuzzleApp(int argc, char* argv[]);
  private:
    void createWidgets();
    void createActions();
    QMainWindow m_MainWin;
    PuzzleModel *m_Model;
    PuzzleView *m_View;
    QAction* m_Shuffle;
};
#endif        //  #ifndef PUZZLE_APP_H

