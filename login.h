#ifndef LOGIN_H
#define LOGIN_H

#include <string>

void setColor(int color);

class Login {
private:
    std::string id;
    int pass;
    int forgot;
    std::string newid;
    int newpass;
public:
    void signin();
};

#endif
