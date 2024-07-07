
import kotlin.math.pow

class FrequencyTracker() {

    private companion object {
        val VALUES_RANGE = intArrayOf(1, (10.0).pow(5.0).toInt())
        val FREQUENCY_RANGE = intArrayOf(1, (10.0).pow(5.0).toInt())
    }

    private val frequencyOfValues = IntArray(VALUES_RANGE[1] + 1)
    private val frequencyOfFrequencies = IntArray(FREQUENCY_RANGE[1] + 1)

    fun add(value: Int) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]]
        }
        ++frequencyOfValues[value]
        ++frequencyOfFrequencies[frequencyOfValues[value]]
    }

    fun deleteOne(value: Int) {
        if (frequencyOfValues[value] > 0) {
            --frequencyOfFrequencies[frequencyOfValues[value]]
            --frequencyOfValues[value]
        }
        if (frequencyOfValues[value] > 0) {
            ++frequencyOfFrequencies[frequencyOfValues[value]]
        }
    }

    fun hasFrequency(frequency: Int): Boolean {
        return frequencyOfFrequencies[frequency] > 0
    }
}
