FROM ubuntu:18.04

RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install build-essential \ 
        vim gcc git autoconf bison re2c pkg-config \
        libxml2-dev libsqlite3-dev libffi-dev -y
WORKDIR /php-ffi