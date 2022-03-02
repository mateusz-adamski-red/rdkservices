#!/bin/bash

set -e

THUNDER_ROOT=$(pwd)/thunder
THUNDER_INSTALL_DIR=${THUNDER_ROOT}/install

OPTION=""
if [[ "$1" == "-D" ]]; then
    OPTION="gdb"
fi

# Create socket to simulate response
python Source/socketMock.py &
sleep 0.1

PATH=${THUNDER_INSTALL_DIR}/usr/bin:${PATH} \
LD_LIBRARY_PATH=${THUNDER_INSTALL_DIR}/usr/lib:${THUNDER_INSTALL_DIR}/usr/lib/wpeframework/plugins:${LD_LIBRARY_PATH} \
$OPTION RdkServicesTest

# finish socketMock.py process
pkill -f "Source/socketMock.py"

echo "==== DONE ===="

exit 0
