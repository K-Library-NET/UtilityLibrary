﻿using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;

namespace SystemEnv
{
    public class ProcessInfo
    {
        /// <summary>
        /// 关联进程的唯一标识符
        /// </summary>
        public int Id { get; set; }
        /// <summary>
        /// 进程名称
        /// </summary>
        public string ProcessName { get; set; }
        /// <summary>
        /// 获取以整毫秒数和毫秒的小数部分表示的当前 System.TimeSpan 结构的值。
        /// </summary>
        public double TotalMilliseconds { get; set; }
        /// <summary>
        /// 关联的进程分配的物理内存量
        /// </summary>
        public long WorkingSet64 { get; set; }
        /// <summary>
        /// 模块的完整路
        /// </summary>
        public string FileName { get; set; }

        public ProcessInfo(int id, string processName, double totalMilliseconds, long workingSet64, string fileName)
        {
            this.Id = id;
            this.ProcessName = processName;
            this.TotalMilliseconds = totalMilliseconds;
            this.WorkingSet64 = workingSet64;
            this.FileName = fileName;
        }

        public static readonly char Seperator = ',';

        public static string AllProcessNamesToString()
        {
            return AllProcessNamesToString(Seperator);
        }

        public static string AllProcessNamesToString(char seperator)
        {
            StringBuilder builder = new StringBuilder();

            try
            {
                Process[] processes = Process.GetProcesses();
                foreach (Process p in processes)
                {
                    builder.Append(p.ProcessName);
                    builder.Append(seperator);
                }
            }
            catch (Exception ex)
            {
                builder.Append("系统诊断工具获取进程信息发生异常：" + ex.Message + "\t" + ex.StackTrace);
            }

            return builder.ToString().Trim(seperator);
        }
    }
}
