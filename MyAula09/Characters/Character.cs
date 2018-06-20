using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Characters
{
    public abstract class Character
    {
        private string name;

        public string Name { get { return this.name; } }
        public abstract char Move();
        public Character( string name)
        {
            this.name = name;
        }
    }
}
