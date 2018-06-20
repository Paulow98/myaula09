using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Weapon : Item, IAttackPower
    {
        public Weapon(ObjectData obj, int x, int y)
        {
            this.ID = obj.id;
            this.Icon = obj.icon;
            this.Name = obj.name;
            this.AttackPower = obj.attackPower;
            this.Durability = obj.durability;
            this.Weight = obj.weight;
            this.X = x;
            this.Y = y;
            this.InInventory = false;
        }
        public float AttackPower { get; set; }
        private float Durability { get; set; }
        public void Use(NPC npc)
        {
            npc.HP -= this.AttackPower;
        }

    }
}
