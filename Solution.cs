
using System;

public class FrequencyTracker
{
    private static readonly int[] VALUES_RANGE = { 1, (int)Math.Pow(10, 5) };
    private static readonly int[] FREQUENCY_RANGE = { 1, (int)Math.Pow(10, 5) };

    private readonly int[] frequencyOfValues;
    private readonly int[] frequencyOfFrequencies;

    public FrequencyTracker()
    {
        frequencyOfValues = new int[VALUES_RANGE[1] + 1];
        frequencyOfFrequencies = new int[FREQUENCY_RANGE[1] + 1];
    }

    public void Add(int value)
    {
        if (frequencyOfValues[value] > 0)
        {
            --frequencyOfFrequencies[frequencyOfValues[value]];
        }
        ++frequencyOfValues[value];
        ++frequencyOfFrequencies[frequencyOfValues[value]];
    }

    public void DeleteOne(int value)
    {
        if (frequencyOfValues[value] > 0)
        {
            --frequencyOfFrequencies[frequencyOfValues[value]];
            --frequencyOfValues[value];
        }
        if (frequencyOfValues[value] > 0)
        {
            ++frequencyOfFrequencies[frequencyOfValues[value]];
        }
    }

    public bool HasFrequency(int frequency)
    {
        return frequencyOfFrequencies[frequency] > 0;
    }
}
