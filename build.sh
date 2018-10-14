#!/bin/bash
set -e
set -x

CMD=$@
if [[ "$CMD" == "" ]]; then
	CMD="make -C src clean && make -C src -j4"
fi

docker run --rm -v $PWD:/work -w /work xboxkrnl bash -c "$CMD"
