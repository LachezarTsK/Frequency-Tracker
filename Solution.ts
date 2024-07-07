
class FrequencyTracker {

    VALUES_RANGE: number[];
    FREQUENCY_RANGE: number[];

    frequencyOfValues: number[];
    frequencyOfFrequencies: number[];

    constructor() {
        this.VALUES_RANGE = [1, Math.pow(10, 5)];
        this.FREQUENCY_RANGE = [1, Math.pow(10, 5)];

        this.frequencyOfValues = new Array(this.VALUES_RANGE[1] + 1).fill(0);
        this.frequencyOfFrequencies = new Array(this.FREQUENCY_RANGE[1] + 1).fill(0);
    }

    add(value: number): void {
        if (this.frequencyOfValues[value] > 0) {
            --this.frequencyOfFrequencies[this.frequencyOfValues[value]];
        }
        ++this.frequencyOfValues[value];
        ++this.frequencyOfFrequencies[this.frequencyOfValues[value]];
    }

    deleteOne(value: number): void {
        if (this.frequencyOfValues[value] > 0) {
            --this.frequencyOfFrequencies[this.frequencyOfValues[value]];
            --this.frequencyOfValues[value];
        }
        if (this.frequencyOfValues[value] > 0) {
            ++this.frequencyOfFrequencies[this.frequencyOfValues[value]];
        }
    }

    hasFrequency(frequency: number): boolean {
        return this.frequencyOfFrequencies[frequency] > 0;
    }
}
