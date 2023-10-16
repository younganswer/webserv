#include <FileManager/FileTableManager/FileTableManager.hpp>

FileBufferManager::FileBufferManager(void) :
_clientWaitingQueue(std::queue<ft::shared_ptr<Client_id> >()),
_readFromFileToClientBuffer(ft::shared_ptr<IoReadAndWriteBuffer>(new IoReadAndWriteBuffer())) {}

FileBufferManager::~FileBufferManager(void) {}