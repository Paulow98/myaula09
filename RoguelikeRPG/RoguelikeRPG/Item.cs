using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    abstract class Item: GameObject
    {

        public bool InInventory { get; set; }
        public float Weight { get; set; }
        public virtual void PickUp(Player p)
        {
            p.Backpack.Add(this);
            this.InInventory = true;
        }
        public virtual void Drop()
        {

        }
        public virtual void Use()
        {

        }

    }
}
