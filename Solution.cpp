
#include <array>
using namespace std;

/*
since std::pow(base, exp) does not produce compile-time constant
defining utility::tenToPowersOfPositiveN(n) for this purpose
in order to use "constexpr" for the arrays for the ranges
and "template<class T, size_t N> struct array" for the arrays for the frequencies.
*/
namespace utility {
    consteval int tenToPowersOfPositiveN(int n) {
        int value = 10;
        while (n-- > 0) { value *= 10; }
        return value;
    }
}

class FrequencyTracker {

    static constexpr array<int, 2> VALUES_RANGE = { 1, utility::tenToPowersOfPositiveN(5) };
    static constexpr array<int, 2> FREQUENCY_RANGE = { 1, utility::tenToPowersOfPositiveN(5) };

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
