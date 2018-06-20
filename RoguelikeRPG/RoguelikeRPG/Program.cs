using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Program
    {
        static void Main(string[] args)
        {
            ObjectsList obj = new ObjectsList("ObjectsList.txt");
            List<ObjectData> test = new List<ObjectData>();
            Grid g = new Grid();
            g.tiles[3, 3].AddItem(1);
            g.tiles[2, 4].AddItem(2);
            g.tiles[2, 4].AddItem(1);
            Renderer render = new Renderer(g);
            render.RenderUI();
            Console.WriteLine(g.tiles[3, 3].Objects.ElementAt(0).Name);
            Console.WriteLine();

        }
    }
}
