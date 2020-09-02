#include <chrono>
#include <iostream>

#include "aria2cpp/aria2cpp.hpp"

int aria2cpp::Session::handle_event(aria2::DownloadEvent event, id_t id)
{
    switch (event)
    {
    case aria2::EVENT_ON_DOWNLOAD_COMPLETE:
        std::cerr << "COMPLETE";
        break;
    case aria2::EVENT_ON_DOWNLOAD_ERROR:
        std::cerr << "ERROR";
        break;
    case aria2::EVENT_ON_BT_DOWNLOAD_COMPLETE:
        std::cerr << "Torrent download complete. Starting to seed.";
        break;
    default:
        return 0;
    }
    std::cerr << " [" << id << "] ";
    std::cerr << std::endl;
    return 0;
}

void print_info()
{
    auto &session = aria2cpp::Session::get();
    auto stat = session.get_global_statistics();
    std::cerr << "Overall #Active:" << stat.numActive
              << "#waiting:" << stat.numWaiting
              << "Dspeed:" << stat.downloadSpeed / 1024 << "KB/s"
              << "Uspeed:" << stat.uploadSpeed / 1024 << "KB/s" << std::endl;

    auto ids = session.get_active_downloads();

    for (auto id : ids)
    {
        auto download_handle = session.get_download_handle(id);
        if (download_handle)
        {
            std::cerr << "  [" << id << "] "
                      << download_handle->getCompletedLength() << "/"
                      << download_handle->getTotalLength() << "("
                      << (download_handle->getTotalLength() > 0
                              ? (100 * download_handle->getCompletedLength() /
                                 download_handle->getTotalLength())
                              : 0)
                      << "%)"
                      << "Dspeed:" << download_handle->getDownloadSpeed() / 1024
                      << "KB/s, Uspeed:"
                      << download_handle->getUploadSpeed() / 1024 << "KB/s"
                      << std::endl;
        }
    }
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cerr << "How to download?:\n"
                  << "just type: ./kuloader_download <URI1> <URI2> <URI(N)>"
                  << std::endl;
        exit(EXIT_SUCCESS);
    }

    auto url = "http://ipv4.download.thinkbroadband.com/5MB.zip";

    const auto output_file_name = "5MB";
    const auto output_directory = "downloads";
    auto &session = aria2cpp::Session::init();

    session.set_global_option({{"max-overall-download-limit", "10M"},
                               {"max-overall-upload-limit", "10M"}});

    auto [response_value, id] = session.add_download(
        {url}, {{"out", output_file_name}, {"dir", output_directory}});
    if (response_value < 0)
    {
        std::cerr << "Failed to add download " << url << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "Added download. Download ID is:" << id << std::endl;

    auto start = std::chrono::steady_clock::now();
    for (int response_value = 0; (response_value = session.run()) == 1;)
    {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
        if (count >= 2000)
        {
            start = now;
            print_info();
        }
    }
    return EXIT_SUCCESS;
}