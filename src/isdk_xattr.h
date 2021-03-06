/*
  Copyright (c) 2012-2013 Riceball LEE(snowyu.lee@gmail.com)
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
 
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
 
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef isdk_xattr__h
 #define isdk_xattr__h

#include <stdbool.h>
/*use the redis C dynamic strings library: sds.h*/
#include "isdk_sds.h"

 #ifdef __cplusplus
 extern "C"
 {
 #endif

/* 
Xattr Error codes:
The following errors may be returned by the system calls themselves. Additionally, the file system implementing the call may return any other errors it desires.
[EFAULT]
 	 The attrnamespace and attrname arguments, or the memory range defined by data and nbytes point outside the process’s allocated address space.
[ENAMETOOLONG]
 	 The attribute name was longer than EXTATTR_MAXNAMELEN.
The extattr_get_fd, extattr_set_fd, extattr_delete_fd, and extattr_list_fd system calls may also fail if:
[EBADF]
 	 The file descriptor referenced by fd was invalid.
Additionally, the extattr_get_file, extattr_set_file, and extattr_delete_file calls may also fail due to the following errors:
[ENOATTR]
 	 The requested attribute was not defined for this file.
[ENOTDIR]
 	 A component of the path prefix is not a directory.
[ENAMETOOLONG]
 	 A component of a pathname exceeded 255 characters, or an entire path name exceeded 1023 characters.
[ENOENT]
 	 A component of the path name that must exist does not exist.
[EACCES]
 	 Search permission is denied for a component of the path prefix.
*/

//the xattr low level functions:
/*
ssize_t xattr_getxattr(const char *path, const char *name,
                              void *value, ssize_t size, u_int32_t position, 
                              int options);
ssize_t xattr_setxattr(const char *path, const char *name,
                              void *value, ssize_t size, u_int32_t position,
                              int options);
//If any of the calls are unsuccessful, the value -1 is returned and the global variable errno is set to indicate the error.
ssize_t xattr_removexattr(const char *path, const char *name,
                                 int options);
ssize_t xattr_listxattr(const char *path, char *namebuf,
                               size_t size, int options);
ssize_t xattr_fgetxattr(int fd, const char *name, void *value,
                               ssize_t size, u_int32_t position, int options);
ssize_t xattr_fsetxattr(int fd, const char *name, void *value,
                               ssize_t size, u_int32_t position, int options);
ssize_t xattr_fremovexattr(int fd, const char *name, int options);
ssize_t xattr_flistxattr(int fd, char *namebuf, size_t size, int options);
*/

ssize_t ListXattr(const char *path, char *namebuf, size_t size);
bool IsXattrExists(const char* aFile, const char* aKey);
sds GetXattr(const char* aFile, const char* aKey);
//0: ok; others: errcode.
ssize_t SetXattr(const char* aFile, const char* aKey, const char *aValue, const size_t aValueSize);
//0: ok; others: errcode.
ssize_t DelXattr(const char* aFile, const char* aKey);

 #ifdef __cplusplus
 }
 #endif

#endif
