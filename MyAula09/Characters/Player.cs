using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Characters
{
    class Player : Character, IKeyControllable
    {
        public char ReadControlKey()
        {
            char tmp = new char();
            bool tmpB;
            do
            {
                tmpB = true;
                Console.WriteLine("Wich way do you wanna go? (WSAD)");
                switch (Console.ReadKey().Key)
                {
                    case ConsoleKey.A:
                        tmp = 'W';
                        break;
                    case ConsoleKey.S:
                        tmp = 'S';
                        break;
                    case ConsoleKey.D:
                        tmp = 'E';
                        break;
                    case ConsoleKey.W:
                        tmp = 'N';
                        break;
                    default:
                        tmpB = false;
                        break;
                }
            } while (!tmpB);
            return tmp;
        }
        public override char Move()
        {
             return ReadControlKey();
        }
        public Player(string name) : base(name) { }
    }
}
