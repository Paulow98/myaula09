using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Trap : GameObject
    {
        public Trap(ObjectData obj, int x, int y)
        {
            this.Icon = obj.icon;
            this.Name = obj.name;
            this.ID = obj.id;
            this.X = x;
            this.Y = y;
            this.MaxDamage = obj.maxDamage;
            this.Triggered = false;
        }
        public bool Triggered { get; set; }
        public float MaxDamage { get;}

        public void TrapAction(Grid grid)
        {
            foreach(Player p in grid.tiles[X,Y].Objects)
            {
                if (!this.Triggered)
                {
                    p.HP -= MaxDamage;
                    this.Triggered = true;
                }
            }
           
        }
    }
}
