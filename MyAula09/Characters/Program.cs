using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Characters
{
    class Characters
    {
        static void Main(string[] args)
        {
            Player p = new Player("Kripparian");
            NPC npc = new NPC("RNG");

            for (; ; )
            {
                Console.WriteLine("The NPC moved to: " + npc.Move());
                Console.WriteLine("The Player moved to:" + p.Move());
            }
        }
    }
}
