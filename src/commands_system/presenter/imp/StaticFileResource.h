#pragma once

#include "IResource.h"

class StaticFileResource : public IResource {
	const char *path_to_file;

	StaticFileResource(const StaticFileResource &);
public:
	StaticFileResource(const char *path_to_file);
	virtual std::vector<char> get() const;
	virtual ~StaticFileResource() {}
};

