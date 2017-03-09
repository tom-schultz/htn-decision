using System;

namespace libdecision
{
    public interface IAction
    {
        bool Perform();
    }

    public abstract class Action : IAction
    {
        public readonly string desc;

        public Action(string desc)
        {
            this.desc = desc;
        }

        public override string ToString()
        {
            return desc;
        }

        public abstract bool Perform();
    }

    public class MoveAction : Action, IAction
    {
        private IActor actor;

        public MoveAction(string desc, IActor actor)
            :base(desc)
        {
            this.actor = actor;
        }

        public override bool Perform()
        {
            if (HasArrived())
            {
                return true;
            }

            int distanceX = actor.Destination.x - actor.Position.x;
            int distanceY = actor.Destination.y - actor.Position.y;

            /*
            if (Math.Abs(distanceX) > Math.Abs(distanceY))
            {
                actor.Position.x += Math.Sign(distanceX);
            }
            else
            {
                actor.Position.y += Math.Sign(distanceY);
            }
            */

            return HasArrived();
        }

        private bool HasArrived()
        {
            return (actor.Position.x == actor.Destination.x && actor.Destination.y == actor.Destination.y);
        }
    }

    public struct Point
    {
        public int x;
        public int y;
    }

    public interface IActor
    {
        Point Position { get; set; }
        Point Destination { get; set; }
    }
}