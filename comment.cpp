#include"comment.h"

comment::comment()
{}

comment::comment(const QString &Content, const QString &Time, const QString &CommentWriter):
    content(Content), time(Time), commentWriter(CommentWriter)
{}

comment::~comment()
{}

void comment::getComment(QString &Content, QString &Time, QString &CommentWriter)
{
    Content = content;
    Time = time;
    CommentWriter = commentWriter;
}
