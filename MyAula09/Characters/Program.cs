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
            Player p = new Player();
            NPC npc = new NPC();

            for (; ; )
            {
                Console.WriteLine("The NPC moved to: " + npc.Move());
                Console.WriteLine("The Player moved to:" + p.Move());
            }
        }
    }
}
