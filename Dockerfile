FROM archlinux:latest

RUN pacman -Syyu --noconfirm
RUN pacman -Sy --noconfirm make cmake gcc
RUN pacman -Sy --noconfirm python-pytest
RUN pacman -Sy --noconfirm fish

WORKDIR /workdir
COPY src tests CMakeLists.txt pytest.ini ./
RUN cmake -S . -B build
RUN cmake --build build
RUN pytest -v
