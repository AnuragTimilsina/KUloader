#include <iostream>
#include <chrono>
#include <aria2/aria2.h>

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event,
    aria2::A2Gid gid, void* userData)
{
    switch (event) {
    case aria2::EVENT_ON_DOWNLOAD_COMPLETE:
        std::cerr << "COMPLETE";
        break;
    case aria2::EVENT_ON_DOWNLOAD_ERROR:
        std::cerr << "ERROR";
        break;
    default:
        return 0;
    }
    std::cerr << " [" << aria2::gidToHex(gid) << "] ";
    aria2::DownloadHandle* dh = aria2::getDownloadHandle(session, gid);
    if (!dh)
        return 0;
    if (dh->getNumFiles() > 0) {
        aria2::FileData f = dh->getFile(1);
        // Path may be empty if the file name has not been determined yet.
        if (f.path.empty()) {
            if (!f.uris.empty()) {
                std::cerr << f.uris[0].uri;
            }
        }
        else {
            std::cerr << f.path;
        }
    }
    aria2::deleteDownloadHandle(dh);
    std::cerr << std::endl;
    return 0;
}

int main(int argc, char** argv)
{
  int response_value;
  if (argc < 2) {
    std::cerr << "How to download?:\n"
              <<"just type: ./kuloader_download <URI1> <URI2> <URI(N)>"
              << std::endl;
    exit(EXIT_SUCCESS);
  }
  aria2::libraryInit();//initializing the library

  //Creating session object
  //Note:only one session for 1 process
  aria2::Session* session;

  //Using default configuration
  //The libaria takes care of signal handling
  aria2::SessionConfig config;

  // just tempering the download event callback method
  //with our own defined function
  config.downloadEventCallback = downloadEventCallback;
  session = aria2::sessionNew(aria2::KeyVals(), config);

  // Add download item to session
  for (int i = 1; i < argc; ++i) {
    std::vector<std::string> uris = {argv[i]};
    aria2::KeyVals options;
    response_value = aria2::addUri(session, nullptr, uris, options);
    if (response_value < 0) {
      std::cerr << "Failed to add download " << uris[0] << std::endl;
    }
  }

  //To perform the download, call run() repeatedly until it returns the value other than 1:
  auto start = std::chrono::steady_clock::now();
  for (;;) 
  {
    response_value = aria2::run(session, aria2::RUN_ONCE);
    if (response_value != 1) {
      break;
    }

    // the application can call aria2 API to add URI or query progress
    // here

    auto now = std::chrono::steady_clock::now();
    auto count =
        std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
            .count();
    // Print progress information once per 2000ms
    if (count >= 2000) {
      start = now;
      aria2::GlobalStat gstat = aria2::getGlobalStat(session);
      std::cerr << "Overall #Active:"  <<gstat.numActive
                << "#waiting:" << gstat.numWaiting
                << "Dspeed:" << gstat.downloadSpeed/1024 <<"KB/s"
                << "Uspeed:" << gstat.uploadSpeed/1024 <<"KB/s"<<std::endl;
      
      std::vector<aria2::A2Gid> gids = aria2::getActiveDownload(session);

      for (const auto& gid : gids) {
        
        aria2::DownloadHandle* dh = aria2::getDownloadHandle(session, gid);
        
        if (dh) {
            std::cerr << "  ["<<aria2::gidToHex(gid)<<"] "
                <<dh->getCompletedLength()<<"/"<<dh->getTotalLength()
                <<"("
                <<(dh->getTotalLength() > 0
                            ? (100 * dh->getCompletedLength() /
                               dh->getTotalLength())
                            : 0)
                <<"%)"
                <<"Dspeed:" <<dh->getDownloadSpeed()/1024
                <<"KB/s, Uspeed:"<<dh->getUploadSpeed()/1024<<"KB/s"
                <<std::endl;
            aria2::deleteDownloadHandle(dh);
        }
      }
    }
  }
  
  response_value = aria2::sessionFinal(session);
  aria2::libraryDeinit();
  return response_value;

}