
public class FrequencyTracker {

    private static final int[] VALUES_RANGE = {1, (int) Math.pow(10, 5)};
    private static final int[] FREQUENCY_RANGE = {1, (int) Math.pow(10, 5)};

    private final int[] frequencyOfValues;
    private final int[] frequencyOfFrequencies;

    public FrequencyTracker() {
        frequencyOfValues = new int[VALUES_RANGE[1] + 1];
        frequencyOfFrequencies = new int[FREQUENCY_RANGE[1] + 1];
    }

    public void add(int value) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]];
        }
        ++frequencyOfValues[value];
        ++frequencyOfFrequencies[frequencyOfValues[value]];
    }

    public void deleteOne(int value) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]];
            --frequencyOfValues[value];
        }
        if (frequencyOfValues[value] > 0) {
            ++frequencyOfFrequencies[frequencyOfValues[value]];
        }
    }

    public boolean hasFrequency(int frequency) {
        return frequencyOfFrequencies[frequency] > 0;
    }
}
