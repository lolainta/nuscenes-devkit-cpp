FROM archlinux:latest

RUN pacman -Syyu --noconfirm
RUN pacman -Sy --noconfirm make cmake gcc
RUN pacman -Sy --noconfirm python-pytest
RUN pacman -Sy --noconfirm fish

WORKDIR /workdir
COPY . ./
RUN cmake -S . -B build
RUN cmake --build build -j

RUN curl -o v1.0-mini.tgz https://www.nuscenes.org/data/v1.0-mini.tgz
RUN rm data; mkdir data
RUN tar xf v1.0-mini.tgz -C ./data
RUN pytest -v
