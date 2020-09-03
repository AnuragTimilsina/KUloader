/**
 *
 * aria2cpp gives the complete abstraction of functionality of
 * libaria2. It will work alongside libaria2 although this is not recommended
 * since aria2cpp designed to be safer.
 *
 * You can use <a href="https://aria2.github.io/manual/en/html/libaria2.html">
 * libaria2 documentation </a> for reference as well. Most of the methods here
 * are safer counterparts of libaria2
 *
 * @author anon
 *
 * This library is under public domain.
 *
 */

 #pragma once
#include <aria2/aria2.h>
#include <utility>
#include <memory>
#include <iostream>

/**
 * aria2cpp library namespace
 */
namespace aria2cpp {

/**
 * A singleton class that represents RAII enabled aria2::Session and all
 * relevant functions.
 *
 */
class Session {
public:
    /** @brief Private constructor. This is called only once by init().
     *
     * @param options The options for the session.
     * @param session_config The session config variables.
     * @return The download manager instance.
     */
    Session(const aria2::KeyVals& options = {},
            aria2::SessionConfig session_config = {}) {
        aria2::libraryInit();
        session_config.keepRunning = true;  //this
        session_config.userData = this;
        session_config.downloadEventCallback = download_event_wrapper;
        session = aria2::sessionNew(options, session_config);
    }

   public:
    /**
     * @brief The aria2::Session. You can access this anytime and use libaria2
     * functions.
     * It is discouraged to do so. aria2cpp is safer and implements all methods
     * of libaria2.
     */
    inline static aria2::Session* session = nullptr;
    /**
     * @brief id_t is same as aria2::A2Gid.
     */
    using id_t = aria2::A2Gid;

    /**
     * @brief Deleted copy constructor.
     * There can only be one session. No copies are allowed.
     *
     */
    Session(const Session&) = delete;

    /**
     * @brief Deleted copy assignment operator.
     * There can only be one session. No copies are allowed.
     */
    Session& operator=(const Session&) = delete;

    /**
     * @brief Initialize the library.
     *
     * Similar to aria2::InitLibrary() and setting up the session variables.
     * No need to aria2::DeinitLibrary() and free session variables since this
     * is done automatically. The library and session variables are deallocated
     * automatically by the destructor.
     *
     * @param options The options for the session.
     * @param session_config The session config variables.
     * @return The download manager instance.
     */
    static Session& init(const aria2::KeyVals& options = {},
                         aria2::SessionConfig session_config = {}) {
        static Session manager = {options, session_config};
        return manager;
    }

    /**
     * @brief Get the session instance.
     *
     * @return The session instance.
     */
    static Session& get() { return init(); }
    /**
     *
     * Automatically deallocates session and library. No need to do this
     * manually anymore.
     *
     */
    ~Session() {
        aria2::sessionFinal(session);
        aria2::libraryDeinit();
    }

    /**
     * @brief Add a download.
     *
     * Queues a download.
     * See <a href = "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::addUri </a> for reference.
     *
     * @param uris list of URLs to download the file from. The URLs is for the
     * same download file.
     * @param options The options for download. One of the useful option is
     * "out" which specifies output file name.
     * @param position The position to place in queue. If -1 it is placed at end
     * of queue.
     * @return Returns status code and download ID.
     */
    auto add_download(const std::vector<std::string>& uris,
                      const aria2::KeyVals& options = {}, int position = -1) {
        id_t id;
        auto ret = aria2::addUri(session, &id, uris, options, position);
        return std::pair{ret, id};
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::addMetalink() </a>
     *
     * @param metalinkFile The metalink file.
     * @param options List of options for download.
     * @param position The position to place in queue. If -1 it is placed at end
     * of queue.
     * @return Returns the status code and list of download IDs.
     */
    auto add_metalink(const std::string& metalinkFile,
                      const aria2::KeyVals& options, int position = -1) {
        std::vector<id_t> ids;
        auto ret =
            aria2::addMetalink(session, &ids, metalinkFile, options, position);
        return std::pair{ret, ids};
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html"> aria2::addTorrent
     * </a>
     *
     * @param torrentFile The torrent file.
     * @param webSeedUris The URIs for seeding.
     * @param options List of options for download.
     * @param position The position to place in queue. If -1 it is placed at end
     * of queue.
     *  @return Returns the status code and download ID.
     */
    auto add_torrent(const std::string& torrentFile,__attribute__((unused))
                     const std::vector<std::string>& webSeedUris,
                     const aria2::KeyVals& options, int position = -1) {
        id_t id;
        auto ret =
            aria2::addTorrent(session, &id, torrentFile, options, position);
        return std::pair{ret, id};
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::setPosition </a>
     *
     * @param id Download ID.
     * @param pos Position in queue.
     * @param how OffsetMode.
     *
     * @return  Returns the final destination position of this download, or
     * negative error code.
     */
    int set_position(id_t id, int pos, aria2::OffsetMode how) {
        return aria2::changePosition(session, id, pos, how);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html"> aria2::run </a>
     *
     * @param mode The run mode.
     * @return If the mode is `RUN_DEFAULT` this function returns 0 when no
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

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::getGlobalStat </a>.
     *
     * @return Returns an aria2::GlobalStat struct.
     */
    auto get_global_statistics() { return aria2::getGlobalStat(session); }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::getActiveDownload </a>
     *
     * @return List of active download IDs.
     */
    auto get_active_downloads() { return aria2::getActiveDownload(session); }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::getDownloadHandle</a>. You do not need to deleteDownloadHandle
     * here. That is done automatically.
     *
     * @param id The download ID.
     * @return RAII download handle.
     */
    auto get_download_handle(id_t id) {
        return std::unique_ptr<aria2::DownloadHandle,
                               decltype(&aria2::deleteDownloadHandle)>{
            aria2::getDownloadHandle(session, id),
            &aria2::deleteDownloadHandle};
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::removeDownload.</a>
     *
     * @param id Download ID.
     * @param force  If true, removal will take place without any action which
     * takes time such as contacting BitTorrent tracker.
     * @return 0 if it succeeds, or negative error code.
     */
    auto remove_download(id_t id, bool force = false) {
        return aria2::removeDownload(session, id, force);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::pauseDownload.</a>
     *
     * NOTE: To make pause work, the application must set
     * `aria2::SessionConfig::keepRunning` to true. Otherwise, the
     * behavior is undefined.
     * @param id Download ID.
     * @param force If true, pausing will take place without any action which
     * takes time such as contacting BitTorrent tracker.
     * @return 0 if success, or negative error code.
     */
    auto pause_download(id_t id, bool force = false) {
        return aria2::pauseDownload(session, id, force);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::unpauseDownload.</a>
     * @param id The download ID.
     * @return 0 if success, or negative error code.
     */
    auto resume_download(id_t id) {
        return aria2::unpauseDownload(session, id);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::shutdown.</a>
     * @param force If true, pausing will take place without any action which
     * takes time such as contacting BitTorrent tracker.
     * @return 0 if success, or negative error code.
     */
    auto shutdown(bool force = false) {
        return aria2::shutdown(session, force);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::getGlobalOption.</a>
     * @param name The name of the global option.
     * @return The value of the option if present, else empty string.
     */
    auto get_global_option(const std::string& name) {
        return aria2::getGlobalOption(session, name);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::getGlobalOptions.</a>
     * @return A list of all global options.
     */
    auto get_global_options() { return aria2::getGlobalOptions(session); }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::changeOption.</a>
     * @param id Download ID.
     * @param options The list of options.
     * @return 0 if success, or negative error code.
     */
    auto set_download_options(id_t id, const aria2::KeyVals& options) {
        return aria2::changeOption(session, id, options);
    }

    /**
     * @brief See <a href =
     * "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::changeGlobalOption.</a>
     * @param options The list of options.
     * @return 0 if success, or negative error code.
     */
    auto set_global_option(const aria2::KeyVals& options) {
        return aria2::changeGlobalOption(session, options);
    }
    /**
     * @brief You need to implement this method. By default there is no
     * definition. It is the similar to writing a callback function in aria2.
     * downloadSessionCallback will call this function through a detour.
     *
     * @param event The aria2::DownloadEvent object.
     * @param id The download ID that generated the event.
     * @return Must return 0 for compatibility.
     */
    int (handle_event) (aria2::DownloadEvent event, id_t id) {
        switch (event) {
            case aria2::EVENT_ON_DOWNLOAD_COMPLETE:
                std::cerr << "COMPLETE";
                shutdown();
                break;
            case aria2::EVENT_ON_DOWNLOAD_ERROR:
                std::cerr << "ERROR";
                break;
            case aria2::EVENT_ON_BT_DOWNLOAD_COMPLETE:
                std::cerr << "Torrent download complete. Starting to seed.";
                break;
            case aria2::EVENT_ON_DOWNLOAD_PAUSE:
                std::cerr << "Download Paused";
            break;
            default:
                return 0;
        }
        std::cerr << " [" << id << "] ";
        std::cerr << std::endl;
        return 0;
    }

   private:
    /** @brief A wrapper for the download callback function in aria2.
     * See <a href = "https://aria2.github.io/manual/en/html/libaria2.html">
     * aria2::DownloadEventCallback.</a>
     *
     * @param session The aria2::Session* object.
     * @param event The aria2::DownloadEvent object.
     * @param id The download ID that generated the event.
     * @param user_data Custom user data.
     * @return Returns value returned by handle_event.
     */
    static int download_event_wrapper (__attribute__((unused))aria2::Session* session,
                                      aria2::DownloadEvent event, id_t id,
                                      void* user_data) {

        return static_cast<Session*>(user_data)->handle_event(event, id);
    }
};

}  // namespace aria2cpp
