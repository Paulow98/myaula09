using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tsts
{
    class Program
    {
        static void Main(string[] args)
        {
            for(; ; )
            {
                if (Console.ReadKey().Key == ConsoleKey.NumPad1)
                    Console.WriteLine("yas");
                else
                    Console.WriteLine("noo");
            }
            
           // Console.WriteLine(c);
        }
    }
}
