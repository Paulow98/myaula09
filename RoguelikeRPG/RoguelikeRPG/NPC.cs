using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class NPC : Character, IAttackPower
    {
        public NPC(ObjectData obj, int x, int y)
        {
            this.Icon = obj.icon;
            this.Name = obj.name;
            this.ID = obj.id;
            this.X = x;
            this.Y = y;

            this.AttackPower = obj.attackPower;
            this.HP = obj.healthPoints;
            this.dropList = obj.dropList;
        }
        public float AttackPower { get; set; }
        private List<int> dropList = new List<int>();
    }
}
