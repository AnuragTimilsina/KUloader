#pragma once
#include <aria2/aria2.h>

#include <memory>

namespace aria2cpp {


class Session {
    Session(const aria2::KeyVals& options = {},
            aria2::SessionConfig session_config = {}) {
        aria2::libraryInit();
        session_config.userData = this;
        session_config.downloadEventCallback = download_event_wrapper;
        session = aria2::sessionNew(options, session_config);
    }

   public:
  
    inline static aria2::Session* session = nullptr;
    using id_t = aria2::A2Gid;
    Session(const Session&) = delete;
    Session& operator=(const Session&) = delete;

    static Session& init(const aria2::KeyVals& options = {},
                         aria2::SessionConfig session_config = {}) {
        static Session manager = {options, session_config};
        return manager;
    }

    static Session& get() { return init(); }

    ~Session() {
        aria2::sessionFinal(session);
        aria2::libraryDeinit();
    }

    auto add_download(const std::vector<std::string>& uris,
                      const aria2::KeyVals& options = {}, int position = -1) {
        id_t id;
        auto ret = aria2::addUri(session, &id, uris, options, position);
        return std::pair{ret, id};
    }

    auto add_metalink(const std::string& metalinkFile,
                      const aria2::KeyVals& options, int position = -1) {
        std::vector<id_t> ids;
        auto ret =
            aria2::addMetalink(session, &ids, metalinkFile, options, position);
        return std::pair{ret, ids};
    }

    auto add_torrent(const std::string& torrentFile,
                     const std::vector<std::string>& webSeedUris,
                     const aria2::KeyVals& options, int position = -1) {
        id_t id;
        auto ret =
            aria2::addTorrent(session, &id, torrentFile, options, position);
        return std::pair{ret, id};
    }

    int set_position(id_t id, int pos, aria2::OffsetMode how) {
        return aria2::changePosition(session, id, pos, how);
    }

    auto run(aria2::RUN_MODE mode = aria2::RUN_ONCE) {
        return aria2::run(session, mode);
    }

    auto get_global_statistics() { return aria2::getGlobalStat(session); }


    auto get_active_downloads() { return aria2::getActiveDownload(session); }

    auto get_download_handle(id_t id) {
        return std::unique_ptr<aria2::DownloadHandle,
                               decltype(&aria2::deleteDownloadHandle)>{
            aria2::getDownloadHandle(session, id),
            &aria2::deleteDownloadHandle};
    }

    auto remove_download(id_t id, bool force = false) {
        return aria2::removeDownload(session, id, force);
    }

    auto pause_download(id_t id, bool force = false) {
        return aria2::pauseDownload(session, id, force);
    }

    auto resume_download(id_t id) {
        return aria2::unpauseDownload(session, id);
    }

    auto shutdown(bool force = false) {
        return aria2::shutdown(session, force);
    }

    auto get_global_option(const std::string& name) {
        return aria2::getGlobalOption(session, name);
    }

    auto get_global_options() { return aria2::getGlobalOptions(session); }

    auto set_download_options(id_t id, const aria2::KeyVals& options) {
        return aria2::changeOption(session, id, options);
    }

    auto set_global_option(const aria2::KeyVals& options) {
        return aria2::changeGlobalOption(session, options);
    }

    int handle_event(aria2::DownloadEvent event, id_t id);

   private:

    static int download_event_wrapper(aria2::Session* session,
                                      aria2::DownloadEvent event, id_t id,
                                      void* user_data) {
        return static_cast<Session*>(user_data)->handle_event(event, id);
    }
};

}  