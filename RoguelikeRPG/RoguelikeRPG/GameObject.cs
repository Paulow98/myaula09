using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    abstract class GameObject : IPos
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public int X { get; set; }
        public int Y { get; set; }
        public string Icon { get; set; }
    }
}
