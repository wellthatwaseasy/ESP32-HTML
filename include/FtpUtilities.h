#ifndef FTPUTILITIES
#define FTPUTILITIES
#include "FtpServer.h"

void _callback(FtpOperation ftpOperation, unsigned int freeSpace, unsigned int totalSpace);
void _transferCallback(FtpTransferOperation ftpOperation, const char* name, unsigned int transferredSize);

#endif