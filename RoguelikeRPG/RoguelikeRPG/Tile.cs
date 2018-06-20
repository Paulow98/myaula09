using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoguelikeRPG
{
    class Tile : IPos
    {
        public int X { get; set; }
        public int Y { get; set; }

        public bool Unknown;
        public bool isExit;

        public Stack<GameObject> Objects = new Stack<GameObject>();

        public Tile(int x, int y)
        {
            Unknown = true;
        }

        public void UpdatePos()
        {
            foreach(GameObject g in Objects)
            {
                g.X = this.X;
                g.Y = this.Y;
            }
        }
        public void AddItem(int ID)
        {
            ObjectsList tmpList = new ObjectsList("ObjectsList.txt");
            switch(tmpList.GetObjInfo(ID).type)
            {
                case "Weapon":
                    Objects.Push(new Weapon(tmpList.GetObjInfo(ID), this.X, this.Y));
                    break;
                case "NPC":
                    Objects.Push(new NPC(tmpList.GetObjInfo(ID), this.X, this.Y));
                    break;
                case "Food":
                    Objects.Push(new Food(tmpList.GetObjInfo(ID), this.X, this.Y));
                    break;
            }
        }

        public override string ToString()
        {
            string tmp = null;
            for(int i = 0; i< Objects.Count; i++)
            {
                if (Objects.ElementAt(i).Icon != null)
                    tmp += Objects.ElementAt(i).Icon;
                else
                    tmp += "-";
            }
            for( int i = 0; i < 10 - Objects.Count;i++)
            {
                tmp += "-";
            }
            if (isExit)
                tmp = "EXIT!EXIT!";
            return tmp;
        }

    }
}
