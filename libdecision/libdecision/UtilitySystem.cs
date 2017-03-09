using System;
using System.Collections.Generic;
using System.Linq;

namespace libdecision
{
    public interface IUtilitySystem
    {
        IWeightedOption Decide();
    }

    public class UtilitySystem : IUtilitySystem
    {
        private ICollection<IWeightedOption> options;
        float sumWeight;
        private Random rand = new Random();

        public UtilitySystem(ICollection<IWeightedOption> options)
        {
            this.options = options;
            sumWeight = options.Sum(o => o.Weight);
        }

        public IWeightedOption Decide()
        {
            float num = (float) rand.NextDouble() * sumWeight;

            foreach (var option in options)
            {
                if (num < option.Weight)
                {
                    return option;
                }

                num -= option.Weight;
            }

            throw new ApplicationException("Should have found an option by now. Uh oh.");
        }
    }
}

