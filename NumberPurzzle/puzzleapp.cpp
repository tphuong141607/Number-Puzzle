//Thao Phuong

#include <QGridLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "puzzleapp.h"
#include "puzzlemodel.h"
#include "puzzleview.h"


void PuzzleApp::createWidgets() {
    m_Model = new PuzzleModel(3,3,this);
    m_View = new PuzzleView(m_Model);
    m_MainWin.setCentralWidget(m_View);
}

void PuzzleApp::createActions() {
    m_Shuffle = new QAction(this);
    m_Shuffle->setText("Shuffle");
    QMenu* game = new QMenu(&m_MainWin);
    game->setTitle("Game");
    m_MainWin.menuBar()->addMenu(game);
    game->addAction(m_Shuffle);
    connect (m_Shuffle, SIGNAL(triggered()), 
             m_Model, SLOT(shuffle()));
}

PuzzleApp::PuzzleApp(int argc, char** argv) :
    QApplication(argc, argv) {
    createWidgets();
    createActions();
    m_MainWin.setWindowTitle("Puzzle");
    m_MainWin.show();
}
