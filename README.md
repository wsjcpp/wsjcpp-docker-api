# wsjcpp-docker-api

[![Build Status](https://api.travis-ci.com/wsjcpp/wsjcpp-docker-api.svg?branch=master)](https://travis-ci.com/wsjcpp/wsjcpp-docker-api) [![Github Stars](https://img.shields.io/github/stars/wsjcpp/wsjcpp-docker-api.svg?label=github%20%E2%98%85)](https://github.com/wsjcpp/wsjcpp-docker-api/stargazers) [![Github Stars](https://img.shields.io/github/contributors/wsjcpp/wsjcpp-docker-api.svg)](https://github.com/wsjcpp/wsjcpp-docker-api/) [![Github Forks](https://img.shields.io/github/forks/wsjcpp/wsjcpp-docker-api.svg?label=github%20forks)](https://github.com/wsjcpp/wsjcpp-docker-api/network/members) [![Total alerts](https://img.shields.io/lgtm/alerts/g/wsjcpp/wsjcpp-docker-api.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-docker-api/alerts/) [![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/wsjcpp/wsjcpp-docker-api.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/wsjcpp/wsjcpp-docker-api/context:cpp)

C++ implementation for docker-api (used curl)

Main documentation for docker here:

https://docs.docker.com/engine/api/v1.40/

## Integrate to your project

```
$ wsjcpp install "https://github.com/wsjcpp/wsjcpp-docker-api:master"
```

or include files:

* `src.wsjcpp/nlohmann_json/json.hpp`
* `src.wsjcpp/wsjcpp_core/wsjcpp_core.h`
* `src.wsjcpp/wsjcpp_core/wsjcpp_core.cpp`
* `src/wsjcpp_docker_api.h`
* `src/wsjcpp_docker_api.cpp`

## How to use

```
#include <wsjcpp_core.h>
#include <wsjcpp_docker_api.h>

... 

// get default unix socket path (for linux and for mac)
std::string sUnixSocketPath = dockerApi.getDefaultUnixSocketPath();
if (!dockerApi.doConnectUnixSocketPath(sUnixSocketPath) ) {
    WsjcppLog::err(TAG, "Could not connect to '" + sUnixSocketPath + "'");
    return -1;
}

// get list of images like a 'docker images'
std::vector<WsjcppDockerImage> vImages;
std::string sError;
if (!dockerApi.getImages(vImages, sError)) {
    WsjcppLog::err(TAG, "Could not get list of images '" + sError + "'");
    return -1;
}

```

