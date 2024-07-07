
package main

import (
    "fmt"
    "math"
)

var VALUES_RANGE = [2]int{1, int(math.Pow(10.0, 5.0))}
var FREQUENCY_RANGE = [2]int{1, int(math.Pow(10.0, 5.0))}

type FrequencyTracker struct {
    frequencyOfValues      []int
    frequencyOfFrequencies []int
}

func Constructor() FrequencyTracker {
    return FrequencyTracker{
        frequencyOfValues:      make([]int, VALUES_RANGE[1]+1),
        frequencyOfFrequencies: make([]int, FREQUENCY_RANGE[1]+1),
    }
}

func (this *FrequencyTracker) Add(value int) {
    if this.frequencyOfValues[value] > 0 {
        this.frequencyOfFrequencies[this.frequencyOfValues[value]]--
    }
    this.frequencyOfValues[value]++
    this.frequencyOfFrequencies[this.frequencyOfValues[value]]++
}

func (this *FrequencyTracker) DeleteOne(value int) {
    if this.frequencyOfValues[value] > 0 {
        this.frequencyOfFrequencies[this.frequencyOfValues[value]]--
        this.frequencyOfValues[value]--
    }
    if this.frequencyOfValues[value] > 0 {
        this.frequencyOfFrequencies[this.frequencyOfValues[value]]++
    }
}

func (this *FrequencyTracker) HasFrequency(frequency int) bool {
    return this.frequencyOfFrequencies[frequency] > 0
}
