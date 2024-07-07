
#include <array>
using namespace std;

class FrequencyTracker {

    static constexpr array<int, 2> VALUES_RANGE = { 1, 100000 };
    static constexpr array<int, 2> FREQUENCY_RANGE = { 1, 100000 };

    array<int, VALUES_RANGE[1] + 1> frequencyOfValues{};
    array<int, FREQUENCY_RANGE[1] + 1> frequencyOfFrequencies{};

public:
    FrequencyTracker() = default;

    void add(int value) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]];
        }
        ++frequencyOfValues[value];
        ++frequencyOfFrequencies[frequencyOfValues[value]]; 
    }

    void deleteOne(int value) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]];
            --frequencyOfValues[value];
        }
        if (frequencyOfValues[value] > 0) {
            ++frequencyOfFrequencies[frequencyOfValues[value]];
        }
    }

    bool hasFrequency(int frequency) const {
        return frequencyOfFrequencies[frequency] > 0;
    }
};
