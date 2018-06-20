using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Character : GameObject, IHP
    {
        public float HP { get; set; }
        public virtual void Move(char dir)
        {
            switch (dir)
            {
                case 'w':
                    if (Y != 0)
                    {
                        Y--;
                    }
                    break;
                case 'a':
                    if (X != 0)
                    {
                        X--;
                    }
                    break;
                case 's':
                    if (Y != 7)
                    { 
                        Y++;
                    }
                    break;
                case 'd':
                    if (X != 7)
                    {
                        X++;
                    }
                    break;
            }
        }
    }
}
