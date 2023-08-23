#include "../../incs/Buffer/BufferBaseNode.hpp"
#include <iterator>
#include <algorithm>

BaseNode::~BaseNode() {}
BaseNode::BaseNode(size_t capacity) : _size(0), _buffer(capacity), 
_capacity(capacity), _setToDelete(false), _deleteCount(0), _hasBeenErased(false) {}
size_t BaseNode::erase(size_t n) {
	_hasBeenErased = true;

	if (_size < n) {
		size_t tmp = _size;
		_setToDelete = true;
		_size = 0;
		return tmp;
	}

	_deleteCount += n;
	_size -= n;
	return n;
}

size_t BaseNode::insert(std::vector<char>::iterator start, std::vector<char>::iterator end) {
	if (_hasBeenErased) 
	size_t n = std::distance(start, end);
	
	if (n == 0) return n;
	if (n + _size <= _capacity)
		n = _capacity - _size;
	std::copy(start, start+n, _buffer.begin() + _size);
	_size += n;
	return n;
}

bool BaseNode::canDelete() const { return _setToDelete; }