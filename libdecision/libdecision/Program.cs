using System;
using System.Collections.Generic;
using System.IO;
using System.CodeDom.Compiler;
using System.Diagnostics;

namespace libdecision
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            var stopwatch = new Stopwatch();
            var options = new List<IWeightedOption>
            {
                    new WeightedOption("shit", 1.0f),
                    new WeightedOption("eat", 3.0f),
                    new WeightedOption("work", 8.0f)
            };

            var decider = new UtilitySystem(options);

            var results = new Dictionary<string, int>();
            foreach (var option in options)
            {
                results.Add(option.Description, 0);
            }

            stopwatch.Start();
            for (int i = 0; i < 10000; i++)
            {
                var result = decider.Decide();
                results[result.Description] += 1;
            }
            stopwatch.Stop();

            foreach (var result in results)
            {
                Console.WriteLine(result.Key + ": " + result.Value.ToString());
            }

            Console.WriteLine(stopwatch.ElapsedMilliseconds);
        }
    }
}
