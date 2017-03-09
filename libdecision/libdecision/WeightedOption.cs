using System;

namespace libdecision
{
    public interface IWeightedOption
    {
        float Weight { get; }
        string Description { get; }
    }

    public class WeightedOption: IWeightedOption
    {
        public string Description { get; }
        public float Weight { get; }

        public WeightedOption(string desc, float weight)
        {
            Description = desc;
            Weight = weight;
        }
    }
}