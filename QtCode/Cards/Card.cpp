#include<cmath>
#include "Card.h"
#include <QDateTime>

const QString Card::typeName[4]={"Plain", "Text", "Word", "Choices"};


Card::Card():
	review_times(0),
    ac_time(0)
{}

Card::~Card() = default;

int Card::get_id() const
{
	return id;
}

Card::cardType Card::get_type() const
{
    return type;
}

QString Card::get_prob() const
{
    return prob;
}

QString Card::get_title() const
{
    return title;
}

void Card::set_id(int i){id=i;}

void Card::set_init_time(long t)
{
    timestamp=lastime=t;
    next_review=t+86400;
}

long Card::get_nextReview() const {return next_review;}

void Card::test_update(int ac)  // 1 for ac, 0 for not
{
    review_times++;
    if(ac) ac_time++;
    long tnow = QDateTime::currentDateTime().toSecsSinceEpoch();
    next_review = tnow+(tnow-lastime+86400)/(2-ac);
    lastime = tnow;
}

void Card::set_title(QString title_)
{
    title=title_;
}

void Card::set_prob(QString prob_)
{
    prob=prob_;
}

QString Card::add_display(int x) const{return "null";}

QString Card::option(int id, QString str){return "null";}


