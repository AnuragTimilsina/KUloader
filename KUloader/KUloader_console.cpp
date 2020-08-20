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

int add_download_uri(std::vector<std::string> &uri,
                     const std::string output_file_name,
                     const std::string output_directory)
{
    auto &session = aria2cpp::Session::get();
    auto [response_value, id] = session.add_download(
        {uri}, {{"out", output_file_name}, {"dir", output_directory}});
    if (response_value < 0)
    {
        std::cerr << "Failed to add download " << std::endl;
        return 0;
    }
    return id;
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

    std::string output_file_name;
    std::string output_directory;
    int uri_added;
    std::vector<std::string> uris;
    auto &session = aria2cpp::Session::init();
    session.set_global_option({{"max-overall-download-limit", "10M"},
                               {"max-overall-upload-limit", "10M"}});

    std::cout << "Enter the file name of the download:";
    std::cin >> output_file_name;
    if (std::cin.get() == '\n')
    {
        output_file_name = "Default";
    }
    std::cout << std::endl;

    std::cin.ignore(1);

    std::cout << "Enter the file path of the download:";
    std::cin >> output_directory;
    if(std::cin.get() == '\n'){
        output_directory = "downloads";
    }

    if (argc < 2)
    {
        std::cerr << "How to download?\n"
                  << "just type: ./kuloader_download <URI1> <URI2> <URI(N)>"
                  << std::endl;
        std::cerr << "Downloading dummy file for now!!!" << std::endl;
        uris = {"http://ipv4.download.thinkbroadband.com/5MB.zip"};

        //Function can be made here
        uri_added = add_download_uri(uris, output_file_name, output_directory);
        if (uri_added == 0)
        {
            return EXIT_FAILURE;
        }
        else
        {
            std::cout << "Added download. Download ID is:" << uri_added << std::endl;
        }
    }

    for (int i = 1; i < argc; i++)
    {
        uris = {argv[i]};
        output_file_name = "Newfile";
        //function can be made here
        uri_added = add_download_uri(uris, output_file_name, output_directory);
        if (uri_added == 0)
        {
            return EXIT_FAILURE;
        }
        else
        {
            std::cout << "Added download. Download ID is:" << uri_added << std::endl;
        }
    }

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

/*

//Guys please implement pause and resume features in the UI
//because there's no relevance to implement this in console.
//It's as simple as calling the following functions with relevant parameters. 

==============================================================================================================================================================

auto aria2cpp::Session::resume_download(id_t id)

Parameters: 
id -> The download ID.

Returns: 0 if successfully resumed, or negative for error.

==============================================================================================================================================================

auto aria2cpp::Session::pause_download(id_t id,
                                       bool force)

Parameters: 
id -> Download ID.
force -> If true, pausing will take place without any action which takes 
         time such as contacting BitTorrent tracker.

Returns: 0 if success, or negative error code.

==============================================================================================================================================================

*/