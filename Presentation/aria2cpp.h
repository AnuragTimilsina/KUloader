/*
 * aria2cpp gives the complete abstraction of functionality of
 * libaria2. However, it will work alongside libaria2.
 *
 * You can use the libaria2 documentation
 * https://aria2.github.io/manual/en/html/libaria2.html
 * for reference as well.
 *
 * This library is under public domain.
 *
 */
#pragma once
#include <aria2/aria2.h>
#include <memory>
#include <iostream>
/*
 * aria2cpp library namespace
 */
namespace aria2cpp {

/*
 * A singleton class that represents RAII enabled aria2::Session and all
 * relevant functions.
 */

class Session {
    public:
    /*
     * Private constructor. This is called only once by init().
     *
     * options = The options for the session.
     * session_config = The session config variables.
     * It returns the download manager instance.
     */
    Session(const aria2::KeyVals& options = {},
            aria2::SessionConfig sessionConfig = {}) {
        aria2::libraryInit();
//        sessionConfig.keepRunning = true;
        sessionConfig.userData = this;
        sessionConfig.downloadEventCallback = downloadEventWrapper;
        session = aria2::sessionNew(options, sessionConfig);
    }

   public:
    /*
     * The aria2::Session. You can access this anytime and use libaria2
     * functions.
     * It is discouraged to do so. aria2cpp is safer and implements all methods
     * of libaria2.
     */
    inline static aria2::Session* session = nullptr;
    /*
     * id_t is same as aria2::A2Gid.
     */
    using id_t = aria2::A2Gid;

    /*
     * Deleted copy constructor.
     * There can only be one session. No copies are allowed.
     *
     */
    Session(const Session&) = delete;

    /*
     * Deleted copy assignment operator.
     * There can only be one session. No copies are allowed.
     */
    Session& operator=(const Session&) = delete;

    /*
     * Initialize the library.
     *
     * Similar to aria2::InitLibrary() and setting up the session variables.
     * No need to aria2::DeinitLibrary() and free session variables since this
     * is done automatically. The library and session variables are deallocated
     * automatically by the destructor.
     *
     * options = The options for the session.
     * session_config = The session config variables.
     * It returns the download manager instance.
     */
    static Session& init(const aria2::KeyVals& options = {},
                         aria2::SessionConfig session_config = {}) {
        static Session manager = {options, session_config};
        return manager;
    }

    /*
     * Get the session instance.
     *
     * It returns the session instance.
     */
    static Session& get() { return init(); }
    /*
     * Automatically deallocates session and library. No need to do this
     * manually anymore.
     */
    ~Session() {
        aria2::sessionFinal(session);
        aria2::libraryDeinit();
    }

    /*
     * Add a download.
     *
     * Queues a download.
     *
     * uris = list of URLs to download the file from. The URLs is for the
     * same download file.
     * options = The options for download. One of the useful option is
     * "out" which specifies output file name.
     * position = The position to place in queue. If -1 it is placed at end
     * of queue.
     * It returns the status code and download ID.
     */
    auto addDownload(const std::vector<std::string>& uris,
                      const aria2::KeyVals& options = {}, int position = -1) {
        id_t id;
        auto ret = aria2::addUri(session, &id, uris, options, position);
        return std::pair{ret, id};
    }

    /*
     * Add a metalink for downlaod
     *
     * metalinkFile = The metalink file.
     * options = List of options for download.
     * position = The position to place in queue. If -1 it is placed at end
     * of queue.
     * It returns the status code and list of download IDs.
     */
    auto addMetaLink(const std::string& metalinkFile,
                      const aria2::KeyVals& options, int position = -1) {
        std::vector<id_t> ids;
        auto ret =
            aria2::addMetalink(session, &ids, metalinkFile, options, position);
        return std::pair{ret, ids};
    }

    /*
     * Add a torrent for downlaod
     *
     * torrentFile = The torrent file.
     * webSeedUris = The URIs for seeding.
     * options = List of options for download.
     * position = The position to place in queue. If -1 it is placed at end
     * of queue.
     * It returns the status code and download ID.
     */
    auto addTorrent(const std::string& torrentFile,__attribute__((unused))
                     const std::vector<std::string>& webSeedUris,
                     const aria2::KeyVals& options, int position = -1) {
        id_t id;
        auto ret =
            aria2::addTorrent(session, &id, torrentFile, options, position);
        return std::pair{ret, id};
    }

    /*
     * Set position of the download
     *
     * id = Download ID.
     * pos = Position in queue.
     * how = OffsetMode.
     *
     * It returns the final destination position of this download, or
     * negative error code.
     */
    int setPosition(id_t id, int pos, aria2::OffsetMode how) {
        return aria2::changePosition(session, id, pos, how);
    }

    /* Start the download process
     * mode = The run mode.
     *
     * If the mode is `RUN_DEFAULT` this function returns 0 when no
     * downloads are left to be processed. If the mode is `RUN_ONCE`, this
     * function returns after one event polling. In the current implementation,
     * event polling timeouts in 1 second. This function also returns on each
     * timeout. On return, when no downloads are left to be processed,
     * this function returns 0. Otherwise, returns 1, indicating that the
     * caller must call this function one or more time to complete
     * downloads.
     * In either case, this function returns negative error code on error.
     */
    auto run(aria2::RUN_MODE mode = aria2::RUN_ONCE) {
        return aria2::run(session, mode);
    }

    /*
     * Statistics for the download
     * It returns an aria2::GlobalStat struct.
     */
    auto getGlobalStatistics() { return aria2::getGlobalStat(session); }

    /*
     * It returns list of active download IDs.
     */
    auto getActiveDownloads() { return aria2::getActiveDownload(session); }

    /*
     * You do not need to deleteDownloadHandle here. That is done automatically.
     *
     * id = The download ID.
     * It returns the download handle for a download.
     */
    auto getDownloadHandle(id_t id) {
        return std::unique_ptr<aria2::DownloadHandle>(aria2::getDownloadHandle(session, id));
    }

    /*
     * id = Download ID.
     * force = If true, removal will take place without any action which takes
     * time such as contacting BitTorrent tracker.
     * It returns 0 if it succeeds, or negative error code.
     */
    auto remove_download(id_t id, bool force = false) {
        return aria2::removeDownload(session, id, force);
    }

    /*
     * Pauses a downlaod
     *
     * [ "To make pause work, the application must set
     * `aria2::SessionConfig::keepRunning` to true. Otherwise, the
     * behavior is undefined." ]
     *
     * id = Download ID.
     * force, If true, pausing will take place without any action which
     * takes time such as contacting BitTorrent tracker.
     *
     * It returns 0 if success, or negative error code.
     */
    auto pauseDownload(id_t id, bool force = false) {
        return aria2::pauseDownload(session, id, force);
    }

    /*
     * Resumes a download
     *
     * id = The download ID.
     * It returns 0 if success, or negative error code.
     */
    auto resumeDownload(id_t id) {
        return aria2::unpauseDownload(session, id);
    }

    /*
     * It shuts the session down
     *
     * force, if true, pausing will take place without any action which
     * takes time such as contacting BitTorrent tracker.
     *
     * It returns 0 if success, or negative error code.
     */
    auto shutDown(bool force = false) {
        return aria2::shutdown(session, force);
    }

    /*
     * It returns a list of all global options.
     */
    auto getGlobalOptions() { return aria2::getGlobalOptions(session); }

    /*
     * Extra options for a download can be set
     * id = Download ID.
     * options = The list of options.
     * It returns 0 if success, or negative error code.
     */
    auto setDownloadOption(id_t id, const aria2::KeyVals& options) {
        return aria2::changeOption(session, id, options);
    }

    /*
     * With this method, we can tweak the default values of the options for a download.
     * options = The list of options.
     * It returns 0 if success, or negative error code.
     */
    auto changeGlobalOption(const aria2::KeyVals& options) {
        return aria2::changeGlobalOption(session, options);
    }
    /*
     * It is the similar to writing a callback function in aria2.
     * downloadEventCallback will call this function through a detour.
     *
     * event = The aria2::DownloadEvent object.
     * id = The download ID that generated the event.
     * Must return 0 for compatibility.
     */
    int handleEvent (aria2::DownloadEvent event, id_t id) {
        switch (event) {
            case aria2::EVENT_ON_DOWNLOAD_COMPLETE:
                std::cout << "COMPLETE";
//                ui->stackedWidget->event->setText("EVENT: Download Complete. Please Quit this program");
                break;
            case aria2::EVENT_ON_DOWNLOAD_ERROR:
                std::cout << "ERROR";
                break;
            case aria2::EVENT_ON_BT_DOWNLOAD_COMPLETE:
                std::cout << "Torrent download complete. Starting to seed.";
                break;
            case aria2::EVENT_ON_DOWNLOAD_PAUSE:
                std::cout << "Download Paused";
            break;
            default:
                return 0;
        }
        std::cout << " [" << id << "] ";
        std::cout << std::endl;
        return 0;
    }

   private:
    /* A wrapper for the download callback function in aria2.
     *
     * session = The aria2::Session* object.
     * event = The aria2::DownloadEvent object.
     * id = The download ID that generated the event.
     * user_data = Custom user data.
     * It returns the value returned by handle_event.
     */
    static int downloadEventWrapper (__attribute__((unused))aria2::Session* session,
                                      aria2::DownloadEvent event, id_t id,
                                      void* userData) {

        return static_cast<Session*>(userData)->handleEvent(event, id);
    }
};

}  // namespace aria2cpp


















