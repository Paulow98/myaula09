using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Food : Item
    {
        public Food(ObjectData obj, int x, int y)
        {
            this.Icon = obj.icon;
            this.Name = obj.name;
            this.ID = obj.id;
            this.X = x;
            this.Y = y;
            this.InInventory = false;

            this.Weight = obj.weight;
            this.HPIncrease = obj.HPIncrease;
        }
        public float HPIncrease { get; set; }
        public void Use(Player p)
        {
            p.HP += HPIncrease;
            if (p.HP > 100)
                p.HP = 100;
          
            p.Backpack.Remove(this);
        }
    }
}
