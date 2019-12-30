#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <limits>

namespace console {
    
    double get_double(std::string prompt,double min=std::numeric_limits<double>::min(),double max=std::numeric_limits<double>::max(),const int width=0);

    int get_int(std::string prompt,int min=std::numeric_limits<int>::min(),int max=std::numeric_limits<int>::max(),const int width=0);

    char get_char(std::string prompt,bool add_blank_line=true);


}


#endif
