using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Grid
    {
        public Grid()
        {
            this.Fill();
        }
        public Tile[,] tiles = new Tile[8, 8];
        public void Fill()
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    tiles[i, j] = new Tile(i, j);
                }
            }
        }
    }
}
