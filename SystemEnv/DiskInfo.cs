using System;
using System.Collections.Generic;
using System.Text;

namespace SystemEnv
{
    public class DiskInfo
    {
        public string Name { get; set; }
        public long Size { get; set; }
        public long FreeSpace { get; set; }

        public DiskInfo(string name, long size, long freeSpace)
        {
            this.Name = name;
            this.Size = size;
            this.FreeSpace = freeSpace;
        }


    }
}
