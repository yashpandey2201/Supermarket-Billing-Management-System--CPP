#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <string>

void setColor(int color);

class Feedback {
private:
    std::string Name;
    std::string Address;
    int contact;
    int shopreview;
    int billingspeed;
    int staffriendliness;
    std::string anysuggestion; 
public:
    void form();
};

#endif

