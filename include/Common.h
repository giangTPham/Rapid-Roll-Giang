#ifndef COMMON_H
#define COMMON_H
#include <string>

extern float SPEED;
extern float APPEARANCEGAP;
extern float SCOREGAP;
extern int HIGHSCORE;
extern int CHARACTER;
extern std::string characterPath[4];


class Common
{
    public:
        Common();
        virtual ~Common();

    protected:

    private:
};

#endif // COMMON_H
