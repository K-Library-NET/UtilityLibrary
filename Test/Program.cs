using System;
using System.Collections.Generic;
using System.Text;
using MyDownloader.Extension.Protocols;
using MyDownloader.Core;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            //获取系统信息
            string sysInfo = new SystemEnv.SystemInfo().ToString();
            Console.WriteLine(sysInfo);

            //下载
            IHttpFtpProtocolParameters protocolParameters = new HttpFtpProtocolParametersSettingsProxy();
            protocolParameters.UseProxy = false;
            new HttpFtpProtocolExtension(protocolParameters);
            // starts to listen to the event 'DownloadEnded' from DownloadManager
            DownloadManager.Instance.DownloadEnded += new EventHandler<DownloaderEventArgs>(Instance_DownloadEnded);

            // indicates that download should start immediately
            bool startNow = true;

            Downloader download = DownloadManager.Instance.Add(
                ResourceLocation.FromURL("http://jogos.download.uol.com.br/videos/pc/thewitcher12.wmv"),
                null,
                @"c:/thewitcher12.wmv",
                3,          // Three segments 
                startNow    // Start download now
            );
            //获取下载进度
            while (DownloadManager.Instance.Downloads[0].Progress < 100)
            {
                System.Threading.Thread.Sleep(2000);
                Console.WriteLine(String.Format("{0:d}k/{1:d}k({2:f2}%)", DownloadManager.Instance.Downloads[0].Transfered / 1024, DownloadManager.Instance.Downloads[0].FileSize / 1024, DownloadManager.Instance.Downloads[0].Progress));
            }

            Console.Read();

        }

        static void Instance_DownloadEnded(object sender, DownloaderEventArgs e)
        {
            Console.WriteLine(e.Downloader.LocalFile + " downloaded");
        }

    }
}
