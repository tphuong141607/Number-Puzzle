#ifndef PUZZLE_MODEL_H
#define PUZZLE_MODEL_H

#include <QObject>
#include <QList>
#include <QString>


/** Stores the internal representation of a puzzle, 
    containing no knowledge of the view */
class PuzzleModel : public QObject {
    Q_OBJECT
  public:
    /** return true of the puzzle is ordered */
    bool checkOrderedArray();

    /** Creates a new rows*columns puzzle */
    PuzzleModel(int rows, int columns, QObject* parent=0);

    /** Returns the index into m_Positions for a given r,c 
    @return 0 if the empty square, or the tile# at that position. */
    int value(int r, int c) const;

    QString toString() const;

	/** @return dimension of puzzle */
    int size() const;

    /** Attempts to slide the numbered tile. 
    @return true if it succeeds, which is only
    possible if square 0 is a neighbor. 
    */    
    bool slide(int tilenum); 

    /** @return true if two positions are neighboring.
        pos1 and pos2 are index positions (offsets from 0)
	*/
    bool neighboring(int pos1, int pos2) const;

    int rows() const {return m_Rows;}
    int cols() const {return m_Cols;}

    /** @return the index into an array that stores the 
        tile at position (r,c).
    */
    int index(int r, int c) const;
  public slots:
    void shuffle(); 
  signals:
    void gridChanged();
	
  private:
    QList<int> m_Positions;
    int m_Rows, m_Cols;
};

#endif        //  #ifndef PUZZLE_MODEL_H

