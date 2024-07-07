
class FrequencyTracker {

    constructor() {
        this.VALUES_RANGE = [1, Math.pow(10, 5)];
        this.FREQUENCY_RANGE = [1, Math.pow(10, 5)];

        this.frequencyOfValues = new Array(this.VALUES_RANGE[1] + 1).fill(0);
        this.frequencyOfFrequencies = new Array(this.FREQUENCY_RANGE[1] + 1).fill(0);
    }

    /** 
     * @param {number} value
     * @return {void}
     */
    add(value) {
        if (this.frequencyOfValues[value] > 0) {
            --this.frequencyOfFrequencies[this.frequencyOfValues[value]];
        }
        ++this.frequencyOfValues[value];
        ++this.frequencyOfFrequencies[this.frequencyOfValues[value]];
    }

    /** 
     * @param {number} value
     * @return {void}
     */
    deleteOne(value) {
        if (this.frequencyOfValues[value] > 0) {
            --this.frequencyOfFrequencies[this.frequencyOfValues[value]];
            --this.frequencyOfValues[value];
        }
        if (this.frequencyOfValues[value] > 0) {
            ++this.frequencyOfFrequencies[this.frequencyOfValues[value]];
        }
    }

    /** 
     * @param {number} frequency
     * @return {boolean}
     */
    hasFrequency(frequency) {
        return this.frequencyOfFrequencies[frequency] > 0;
    }
}
