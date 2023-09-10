# Stage 1: Build stage
FROM alpine:latest AS build

RUN apk add --no-cache g++ cmake make

COPY . /myzip

WORKDIR /myzip

RUN mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    chmod +x Compressor

# Stage 2: Runtime stage
FROM alpine:latest

RUN apk add --no-cache libstdc++

COPY --from=build /myzip/build/Compressor /usr/local/bin/Compressor

ENTRYPOINT ["Compressor"]