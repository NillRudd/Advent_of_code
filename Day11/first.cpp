#include <string>
#include <iostream>
#include <sstream>
#include <vector>



int main(){

    std::string s = "8435 234 928434 14 0 7 92446 8992692";

    //s = "125 17";
    std::stringstream stream(s);
    long a;
    std::vector<long> stones;
    while (stream >> a){
        stones.push_back(a);
    }

    for (int i = 0; i < 25; i++){
        std::vector<long> newStones;
        for(int j = 0; j < stones.size(); j++){
            long stone = stones[j];
            std::string st(std::to_string(stone));
            std::cout << stone << " ";
            if (stone == 0) newStones.push_back(1);
            else if (st.size() % 2 == 0) {
                std::string ad = st.substr(0, st.size()/2);
                
                newStones.push_back(std::stoi(ad));
                ad = st.substr(st.size()/2, st.size());
                newStones.push_back(std::stoi(ad));
            }
            else {
                newStones.push_back(stone*2024);
            }
        }
        std::cout << std::endl;
        stones.clear();
        for (auto abc : newStones){
            stones.push_back(abc);
        }
    }
    for (int i = 0; i < stones.size(); i++){
        std::cout << stones[i] << " ";
    }
    std::cout << std::endl;

    std::cout << stones.size();
    return 0;
}