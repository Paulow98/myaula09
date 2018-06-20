using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Renderer
    {

        Grid grid = new Grid();
        public Renderer(Grid grid)
        {
            this.grid = grid;
            
        }
        public void RenderUI()
        {
            int lineCounter = 0;
            List<string> lines = new List<string>();

            string utilSpacer = null;
            for (int i = 0; i < 56; i++)
                utilSpacer += " ";

            // upper section
            Console.WriteLine("                          ROGUELIKE RPG           LEVEL " + "Gamemanager.Level");
            Console.WriteLine("  " + "_____________________________________________________________");
            Console.WriteLine("  " + "|  " + utilSpacer + "  |  ");


            //grid section
            lines.Add("  " + "PLAYER STATS");
            lines.Add("  " + "~~~~~~~~~~~~");
            lines.Add("  " + "HP        - " + "Player.HP");
            lines.Add("  " + "Weapon    - " + "Player.EquipedWeapon");
            lines.Add("  " + "Inventory - " + "Player.Backpack.Perc" + " full");
            lines.Add("  "); 
            lines.Add("  ");
            lines.Add("  ");
            lines.Add("  ");
            lines.Add("  ");
            lines.Add("  " + "SUBTITLES");
            lines.Add("  " + "~~~~~~~~~");
            lines.Add("  " + "Player.Icon" + " - " + "Player.Name");
            lines.Add("  " + "EXIT!" + " - " + "Exit");
            lines.Add("  " + "-" + " - " + "Empty");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" REPLACE THIS");
            lines.Add(" LAST OF THIS");
 
            
            for (int i = 0; i < 8; i++)
            {
                string tmpL = null;
                string tmpL2 = null;
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        tmpL += grid.tiles[i, j].ToString()[k];
                        tmpL2 += grid.tiles[i, j].ToString()[k + 5];
                    }
                    tmpL += "  ";
                    tmpL2 += "  ";
                }
                Console.WriteLine("  " + "|  " + tmpL + "  |  " + lines[lineCounter++]);
                Console.WriteLine("  " + "|  " + tmpL2 + "  |  " + lines[lineCounter++]);
                Console.WriteLine("  " + "|  " + utilSpacer + "  |  " + lines[lineCounter++]);
            }
            //bottom section
            Console.WriteLine("  " + "|____________________________________________________________|");
        }
    }
}
