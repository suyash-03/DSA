#include <iostream>
#include <vector>

using namespace std;

class RandomUniqueNumberGenerator {
    private:
        int remainingNumbers;
        vector<int> numbers;
    public:
        RandomUniqueNumberGenerator(int minValue, int maxValue) {
            for (int i = minValue; i <= maxValue; ++i) {
                numbers.push_back(i);
            }
            remainingNumbers = numbers.size();
        }

        int getRandomUniqueNumber(){
            if(remainingNumbers == 0){
                throw out_of_range("No more unique numbers available.");
            }

            int randomIndex = rand() % remainingNumbers;
            int randomNumber = numbers[randomIndex];
            swap(numbers[randomIndex],  numbers[remainingNumbers - 1]);
            remainingNumbers--;
            return randomNumber;
        }
};

int main() {
    RandomUniqueNumberGenerator rng(1, 10); // Generate unique numbers between 1 and 10
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    std::cout << rng.getRandomUniqueNumber() << std::endl;
    return 0;
}