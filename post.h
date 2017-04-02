#ifndef POST
#define POST

#include <QDateTime>
#include <vector>
#include <QTextStream>

#include "comment.h"
#include "datastructure.h"

class post
{
public:
    post();
    post(const QString &postWriter, const QString &title, const QString &content,
         const QString &pubishtime, const std::vector<comment> &postcomments, const BoardType &postkind);
    ~post();
    void getpostinfo(QString &postWriter, QString &title, QString &content,
                     QString &pubishtime, std::vector<comment> &postcomments, BoardType &postkind);
    void setpostkind(const BoardType &postkind);
    BoardType getpostkind(const BoardType &postkind);

    std::vector<comment> postcomments;

private:
    QString postWriter;
    QString title;
    QString content;
    QString pubishtime;
    BoardType postkind;

friend QTextStream& operator >> (QTextStream &in, post &thePost);
friend QTextStream& operator << (QTextStream &out, post &thePost);
};






#endif // POST

