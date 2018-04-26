using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Characters
{
    class NPC : Character
    {
        Random random = new Random();
        public override char Move()
        {
            char tmp = new char();
            switch (random.Next(0, 3))
            {
                case 0:
                    tmp = 'W';
                    break;
                case 1:
                    tmp = 'E';
                    break;
                case 2:
                    tmp = 'S';
                    break;
                case 3:
                    tmp = 'N';
                    break;
            }
            return tmp;

        }
    }
}
