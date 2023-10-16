#ifndef CLIENTIDMANAGER_HPP
# define CLIENTIDMANAGER_HPP

# include <set>
# include <Client/ClientLimitExceededException.hpp>
# include "../../libs/shared_ptr/shared_ptr.hpp"

typedef int clinet_id_t;
typedef enum {
    ActionNone,
    ActionRead,
    ActionWrite,
    ActionDelete
}   e_client_file_action;
class Client_id {
public:
    class fileActionKey {
    private:
        friend class FileManager;
        fileActionKey(void);
        ~fileActionKey(void);
    };
private:
    clinet_id_t _id;
    bool _isAvailable;
    e_client_file_action _fileAction;
public:
    Client_id(clinet_id_t id, bool isAvailable, e_client_file_action fileAction);
    ~Client_id();
    clinet_id_t getId() const;
    bool isAvailable() const;
    e_client_file_action getfileAction() const;
    void release();
    void setFileAction(e_client_file_action fileAction,
    const fileActionKey &fileActionKey);
};

class ClientIdManager {
public:
    class AcessKey {
    private:
        friend class Client;
        AcessKey(void);
        ~AcessKey(void);
    };
private:
    std::set<clinet_id_t> _availableIds;
    clinet_id_t _nextId;
    static ClientIdManager *_instance;
private:
    ClientIdManager();
    ClientIdManager(const ClientIdManager &src);
    ClientIdManager &operator=(const ClientIdManager &rhs);
    ~ClientIdManager();
public:
    static ClientIdManager &getInstance(const AcessKey &acessKey);

public:
    ft::shared_ptr<Client_id> allocateId();
    void releaseId(ft::shared_ptr<Client_id> id);
};
#endif