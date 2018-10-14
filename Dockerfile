FROM ubuntu:18.04
USER root
RUN apt-get update && apt-get install -y git nasm build-essential sudo libclang-4.0-dev python
RUN useradd -m docker
RUN echo "docker:docker" | chpasswd && adduser docker sudo

USER docker
CMD /bin/bash
