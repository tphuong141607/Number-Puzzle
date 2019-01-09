//Thao Phuong

#include <QGridLayout>
#include <QAbstractButton>
#include "puzzleview.h"
#include "puzzlemodel.h"
#include <QPushButton>
#include <QMessageBox>

Tile::Tile(int tileNumber): m_Number(tileNumber) {
    QString label = "";
    if (tileNumber > 0) {
        label = QString("%1").arg(tileNumber);
    }
    setText(label);
    QString longText = "click here to push Tile # " + label;
    setWhatsThis(longText);
    setToolTip(longText);
    setStatusTip(longText);
}


PuzzleView::PuzzleView(PuzzleModel* model) : m_Model(model) {
    // Create the buttons
    int numTiles = m_Model->size();
    m_Layout = new QGridLayout(this);
    Tile* t(0);
    for (int i=0; i< numTiles; ++i) {
        QString name = QString("%1").arg(i);
        t = new Tile(i);
        m_Tiles.addButton(t);
    }

    /* This helps avoid connecting a signal for each button */      
    connect (&m_Tiles, SIGNAL(buttonClicked(QAbstractButton*)),
	    this, SLOT(tryToSlide(QAbstractButton*)));
    
    connect (m_Model, SIGNAL(gridChanged()), 
             this, SLOT(refresh()));
    refresh();
}

void PuzzleView::tryToSlide(QAbstractButton* button) {
    Tile* tile = qobject_cast<Tile*>(button);
    int number = tile->getNumber();
    m_Model->slide(number);

    if(m_Model->checkOrderedArray()) {
            QMessageBox msgBox;
            msgBox.setText("Congratulation!");
            msgBox.setInformativeText("Nice Good, You WIN!");
            msgBox.setWindowModality(Qt::WindowModal);
            msgBox.setIcon(QMessageBox::Information);

            QPushButton *playAgainButton = msgBox.addButton(tr("Play Again"), QMessageBox::ActionRole);
            QPushButton *quitButton = msgBox.addButton(tr("Quit"), QMessageBox::ActionRole);

            connect (playAgainButton, SIGNAL(clicked()),
                     m_Model, SLOT(shuffle()));
            connect (quitButton, SIGNAL(clicked()),
                     qApp, SLOT(closeAllWindows()));

            msgBox.exec();
    }
}

void PuzzleView::refresh() {
    QList<QAbstractButton*> buttonList = m_Tiles.buttons();
    for (int r = 0; r < m_Model->rows(); ++r) {
        for (int c = 0; c < m_Model->cols(); ++c) {
            int v = m_Model->value(r,c);
            QAbstractButton* b = buttonList.at(v);
            m_Layout->addWidget(b, r, c);
        }
    }
    QPushButton* bShuffle = new QPushButton("Shuffle");
    QPushButton* bQuit = new QPushButton("Quit");
    m_Layout->addWidget(bShuffle, m_Model->rows()-2, m_Model->cols()+1);
    m_Layout->addWidget(bQuit, m_Model->rows()-1, m_Model->cols()+1);
    connect (bShuffle, SIGNAL(clicked()),
             m_Model, SLOT(shuffle()));

    connect (bQuit, SIGNAL(clicked()),
             qApp, SLOT(closeAllWindows()));
}
