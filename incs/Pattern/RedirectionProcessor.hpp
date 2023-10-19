#ifndef REDIRECTIONPROCESSOR_HPP
# define REDIRECTIONPROCESSOR_HPP

#include <Pattern/ProcessorObject.hpp>

class RedirectionProcessor : public ProcessorObject {
    public:
        RedirectionProcessor(void);
        virtual ~RedirectionProcessor(void);
        virtual e_pattern_Process_result process(ft::shared_ptr
            <VirtualServerManager> virtualServerManager,
            ft::shared_ptr<Client> client);
};

#endif