using System;
using System.Collections.Generic;
using System.Linq;

namespace libdecision
{
    public class TaskNetwork
    {
        private ICollection<IAction> actions;
        private ICollection<IAction> plan;

        public TaskNetwork(ICollection<IAction> actions)
        {
            this.actions = actions;
        }

        public void BuildPlan()
        {
            plan = actions.OrderBy(a => new Guid()).ToList();
            Console.WriteLine("New plan: ");

            foreach (var action in plan)
            {
                Console.WriteLine(plan);
            }
        }

        public bool ExecutePlan()
        {
            if (plan.Count > 0 && plan.First().Perform())
            {
                plan.Remove(plan.First());
                return true;
            }

            Console.WriteLine("Did nothing.");
            return false;
        }
    }
}