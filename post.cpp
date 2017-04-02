#include <QDebug>
#include "post.h"

post::post()
{

}

post::post(const QString &PostWriter, const QString &Title, const QString &Content,
     const QString &Pubishtime, const std::vector<comment> &Postcomments, const BoardType &Postkind):
    postWriter(PostWriter), title(Title), content(Content),
             pubishtime(Pubishtime), postcomments(Postcomments), postkind(Postkind)
{ }

post::~post(){

}


BoardType post::getpostkind(const BoardType &postkind)
{
    return postkind;
}
void post::setpostkind(const BoardType &postkind)
{
    this->postkind = postkind;
}

void post::getpostinfo(QString &writer, QString &Title, QString &Content,
                 QString &time, std::vector<comment> &comments, BoardType &kind)
{
    writer = postWriter;
    Title = title;
    Content = content;
    time = pubishtime;
    comments = postcomments;
    kind = postkind;
    qDebug()<<"int getpost:kind="<<(int)kind;
}

QTextStream& operator >>(QTextStream &in, post &thePost)
{
    QString id = in.readLine();
    QString time = in.readLine();
    QString title = in.readLine();
    QString content = in.readLine();
    QString tempt = in.readLine();
    std::vector<comment> commentvec;
//    BoardType BT;

    while(tempt != "comment:"){
        content += tempt;
        content += '\n';
        tempt = in.readLine();
    }
    tempt = in.readLine();
    while(tempt != "#"){
        QStringList CommentList = tempt.split("+");
        comment oneComment(CommentList[2], CommentList[1], CommentList[0]);
        commentvec.push_back(oneComment);
        tempt = in.readLine();
    }
    thePost.postWriter = id;
    thePost.title = title;
    thePost.content = content;
    thePost.pubishtime = time;
//    thePost.postkind = BT;
    thePost.postcomments = commentvec;

    return in;
}

QTextStream& operator <<(QTextStream &out, post &thePost)
{
    QString commentcontent;
    QString commenttime;
    QString commentWriter;

    out<<"***"<<endl;
    out<<thePost.postWriter<<endl;
    out<<thePost.pubishtime<<endl;
    out<<thePost.title<<endl;
    out<<thePost.content<<endl;
    out<<"comment:"<<endl;

    for(int j = 0; j < thePost.postcomments.size(); j++)
    {
        thePost.postcomments[j].getComment(commentcontent, commenttime, commentWriter);
        out<<commentWriter<<'+';
        out<<commenttime<<'+';
        out<<commentcontent<<endl;
    }
    out << "#" << endl;
    return out;
}

