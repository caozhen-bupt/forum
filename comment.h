#ifndef COMMENT
#define COMMENT
#include<QString>


class comment
{
public:
    comment();
    ~comment();
    comment(const QString &Content, const QString &Time, const QString &CommentWriter);
    void getComment(QString &Content,  QString &Time, QString &CommentWriter);    
    void setComment();

private:
    QString content;
    QString time;
    QString commentWriter;
};

#endif // COMMENT

