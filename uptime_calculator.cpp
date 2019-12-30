#include <fstream>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <cmath>



template <typename T> void display(T value);
std::map<std::string,std::vector<double> > load_uptimes(const std::string file_name);
void process_uptimes(const std::map<std::string,std::vector<double> >& uptimes);



int main() {
    const std::string file_name{"uptimes.txt"};
    
    std::cout << "Processing regional uptimes in " << file_name << "\n\n";
    

    std::map<std::string,std::vector<double> > uptimes = load_uptimes(file_name);
    
    process_uptimes(uptimes);


}



std::map<std::string,std::vector<double> > load_uptimes(const std::string file_name) {
    

    std::ifstream input_file{file_name};
    
    std::map<std::string,std::vector<double> > uptimes{};
    std::stringstream ss;
    if(input_file) {
    
        std::string line{};

        while(std::getline(input_file,line)) {
            
            ss.str(line);
            ss.clear();
            std::string region{};

            ss >> region;
            
            std::vector<double> times{};
            double uptime{};
            while(ss >> uptime) {
                times.push_back(uptime); 

            }

            uptimes[region] = times;

        }


        input_file.close();


    }


    return uptimes;
}

void process_uptimes(const std::map<std::string,std::vector<double> >& uptimes) {
    

    std::string region{};
    std::vector<double> times{};
    

    std::cout << std::fixed << std::setprecision(2);
    double total_uptime{};
    for(auto p: uptimes) {
        


        region = p.first;
        times = p.second;
        
        std::cout << region << std::endl;
        
        double total{std::accumulate(times.begin(),times.end(),0.0)};
        total_uptime += total;
        double average{total/times.size()};
        average = std::round(average * 100) / 100;
        std::cout << "\tAvg Uptime - " << average << '%' << std::endl;

        std::cout << "\t"  << std::left << std::setw(8) <<  "Daily:";
        
        std::for_each(times.begin(),times.end(),display<double>);
        std::cout << std::endl;
    

        std::cout << "\t" << std::setw(8) << "Sorted: ";
        std::sort(times.begin(),times.end());
        std::for_each(times.begin(),times.end(),display<double>);
        std::cout << std::endl;




    }

    double uptime_total = std::accumulate(uptimes.begin(),uptimes.end(),0.0,[](double total,auto p) -> double {return total + std::accumulate(p.second.begin(),p.second.end(),0.0);});
    int uptime_count = std::accumulate(uptimes.begin(),uptimes.end(),0,[](int accumulator, auto p) -> int {return accumulator + p.second.size();});

    double total_average{uptime_total/uptime_count};

    total_average =std::round(total_average *100) /100;
    
    std::cout << "\n\nAvg Uptime across all regions - " << total_average << "%";

}

template <typename T> void display(T value) {
    
    std::cout << value << "% ";

}


