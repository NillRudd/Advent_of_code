#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <thread>
#include <mutex>

std::mutex result_mutex; // Mutex to protect shared results

void processStone(long initialStone, std::vector<long>& results) {
    std::vector<long> stones = {initialStone}; // Each thread starts with its stone

    for (int i = 0; i < 75; i++) {
        std::vector<long> newStones;

        for (long stone : stones) {
            if (stone == 0) {
                newStones.push_back(1);
            } else {
                // Calculate the number of digits
                int numDigits = stone == 0 ? 1 : static_cast<int>(std::log10(stone) + 1);

                if (numDigits % 2 == 0) {
                    // Split the stone into two halves
                    int halfDigits = numDigits / 2;
                    long divisor = static_cast<long>(std::pow(10, halfDigits));
                    long leftPart = stone / divisor;
                    long rightPart = stone % divisor;
                    newStones.push_back(leftPart);
                    newStones.push_back(rightPart);
                } else {
                    newStones.push_back(stone * 2024);
                }
            }
        }

        stones.swap(newStones); // Replace old stones with new ones
    }

    // Append the results from this thread to the shared results vector
    std::lock_guard<std::mutex> lock(result_mutex);
    results.insert(results.end(), stones.begin(), stones.end());
}

int main() {
    std::string s = "8435 234 928434 14 0 7 92446 8992692";
    std::stringstream stream(s);
    long a;
    std::vector<long> initialStones;

    // Parse the input into a vector
    while (stream >> a) {
        initialStones.push_back(a);
    }

    std::vector<std::thread> threads;
    std::vector<long> results;

    // Start a thread for each stone
    for (long stone : initialStones) {
        threads.emplace_back(processStone, stone, std::ref(results));
    }

    // Wait for all threads to finish
    for (std::thread& t : threads) {
        t.join();
    }

    // Output the results
    for (long result : results) {
        std::cout << result << " ";
    }
    std::cout << std::endl;

    std::cout << "Final size: " << results.size() << std::endl;
    return 0;
}
