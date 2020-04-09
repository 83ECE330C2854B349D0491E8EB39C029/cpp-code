#ifndef _MATCH_H_
#define _MATCH_H_

#include "Sq_Stack.h"

class Match
{
    private:
        Stack<char> strList;
    public:
        bool Tmatch(const std::string &str)
        {
            for (int i = 0; i < str.size(); i++) {
                switch (str[i])
                {
                    case '(':
                        strList.push(str[i]);
                        break;
                    case '{':
                        strList.push(str[i]);
                        break;   
                    case '[':
                        strList.push(str[i]);
                        break;

                    case ')':
                        if ('(' != strList.top())
                            return false;
                        else {
                            strList.pop();
                            break;
                        }
                    case '}':
                        if ('{' != strList.top())
                            return false;
                        else {
                            strList.pop();
                            break;
                        }
                    case ']':
                        if ('[' != strList.top())
                            return false;
                        else {
                            strList.pop();
                            break;
                        }
                    default:
                        break;
                }
            }
            return true;
        }
};

#endif
