#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>




int main() {

    
    const int first_col_width{10};
    const int other_col_widths{10};
    double monthly_investment{};

    std::cout << std::left <<  "Monthly Investment: ";

    std::cin >> monthly_investment;
    
    std::cout << "\n\n";
    
    std::cout << std::setw(first_col_width) << "Year";

    
    std::stringstream stream{};
    for(double rate=5.0;rate <= 6.5;rate += 0.5) {
        
        stream << std::fixed << std::setprecision(2);
        stream << rate;
        std::string string_rate{stream.str()};
        std::cout << std::setw(other_col_widths) << string_rate + '%';

        stream.str(""); //empty string


    }

    std::cout << std::endl;




    for(int i=1;i <= 6;++i) {
        
        std::cout << std::setw(first_col_width) << i;

        for(double rate=5.0;rate <= 6.5;rate += 0.5) {
            int months{i * 12};

            double monthly_rate{rate/12.0/100};
            double future_value{};
            for(int month=1;month <= months;++month) {
                future_value = (future_value + monthly_investment) * (1 + monthly_rate);


            }
            
            future_value = std::round(future_value);

            std::cout << std::setw(other_col_widths) << future_value;





        }

        std::cout << std::endl;

    }





}
