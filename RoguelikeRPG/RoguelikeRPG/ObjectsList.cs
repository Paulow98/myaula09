using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace RoguelikeRPG
{

    public struct ObjectData
    {
        public string name, icon, type;
        public int id;
        public float weight, attackPower, durability, HPIncrease, maxDamage, healthPoints;
        public List<int> dropList;
    }
    class ObjectsList
    {
        public List<ObjectData> Objects = new List<ObjectData>();

        public ObjectsList(string filePath)
        {
            SetObjectList(filePath);
        }

        public ObjectData GetObjInfo(int ID)
        {
            ObjectData tmp = new ObjectData();
            foreach(ObjectData obj in Objects)
            {
                if (obj.id == ID)
                    tmp = obj;
            }
            return tmp;
        }

        public List<ObjectData> getList()
        {
            return Objects;
        }
        public void SetObjectList(string filePath)
        {
            ObjectData tmpObj;
            StreamReader sr = new StreamReader(filePath);
            string tmp = sr.ReadLine();
            while (tmp != "END")
            {
                tmpObj = new ObjectData();
                while (tmp != "-")
                {
                    switch (tmp)
                    {
                        case "id":
                            tmp = sr.ReadLine();
                            tmpObj.id = Convert.ToInt32(tmp);
                            break;
                        case "name":
                            tmp = sr.ReadLine();
                            tmpObj.name = tmp;
                            break;
                        case "hp":
                            tmp = sr.ReadLine();
                            tmpObj.healthPoints = Convert.ToSingle(tmp);
                            break;
                        case "type":
                            tmp = sr.ReadLine();
                            tmpObj.type = tmp;
                            break;
                        case "icon":
                            tmp = sr.ReadLine();
                            tmpObj.icon = tmp;
                            break;
                        case "attackpower":
                            tmp = sr.ReadLine();
                            tmpObj.attackPower = Convert.ToSingle(tmp);
                            break;
                        case "weight":
                            tmp = sr.ReadLine();
                            tmpObj.weight = Convert.ToSingle(tmp);
                            break;
                        case "durability":
                            tmp = sr.ReadLine();
                            tmpObj.durability = Convert.ToSingle(tmp);
                            break;
                        case "hpincrease":
                            tmp = sr.ReadLine();
                            tmpObj.HPIncrease = Convert.ToSingle(tmp);
                            break;
                        case "maxdamage":
                            tmp = sr.ReadLine();
                            tmpObj.maxDamage = Convert.ToSingle(tmp);
                            break;
                        case "droplist":
                            tmp = sr.ReadLine();
                            tmpObj.dropList = new List<int>();
                            while (tmp != "droplistEnd")
                            {
                                tmpObj.dropList.Add(Convert.ToInt32(tmp));
                                tmp = sr.ReadLine();
                            }
                            break;
                    }
                    tmp = sr.ReadLine();
                }
                Objects.Add(tmpObj);
                tmp = sr.ReadLine();
            }
            sr.Close();
        }
    }
}
